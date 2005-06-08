#ifndef JEZUK_SimpleDOM_ELEMENTBYTAGIMPL_H
#define JEZUK_SimpleDOM_ELEMENTBYTAGIMPL_H

#include <DOM/Node.h>
#include <DOM/Simple/NodeImpl.h>

namespace SimpleDOM
{

template<class stringT, class string_adaptorT>
class DocumentImpl;

template<class stringT, class string_adaptorT>
class ElementByTagList : public DOM::NodeList_impl<stringT>
{
  public:
    ElementByTagList(DocumentImpl<stringT, string_adaptorT>* ownerDoc, 
                     DOM::Node_impl<stringT>* rootNode,
                     const stringT& tagName) :
        DOM::NodeList_impl<stringT>(),
        rootNode_(rootNode),
        ownerDoc_(ownerDoc),
        tagName_(tagName),
        useNamespace_(false),
        allNamespaces_(false),
        allNames_(false),
        changes_(0),
        refCount_(0)
    {
      string_adaptorT SA;
      allNames_ = (tagName_ == SA.makeStringT("*"));
      populate();
    } // ElementByTagList

    ElementByTagList(DocumentImpl<stringT, string_adaptorT>* ownerDoc, 
                     DOM::Node_impl<stringT>* rootNode,
                     const stringT& namespaceURI,
                     const stringT& localName) :
        DOM::NodeList_impl<stringT>(),
        rootNode_(rootNode),
        ownerDoc_(ownerDoc),
        namespaceURI_(namespaceURI),
        tagName_(localName),
        useNamespace_(true),
        allNamespaces_(false),
        allNames_(false),
        changes_(0),
        refCount_(0)
    {
      string_adaptorT SA;
      allNames_ = (tagName_ == SA.makeStringT("*"));
      allNamespaces_ = (namespaceURI_ == SA.makeStringT("*"));
      populate();
    } // ElementByTagList

		virtual ~ElementByTagList() { }

    //////////////////////////////////////////////////
    // Ref counting
    virtual void addRef()
    {
      ++refCount_;
      ownerDoc_->addRef();
    } // addRef

    virtual void releaseRef()
    {
      ownerDoc_->releaseRef();
      if(--refCount_ == 0)
        delete this;
    } // releaseRef

    /////////////////////////////////////////////////
    // DOM::NodeList methods
    virtual DOM::Node_impl<stringT>* item(unsigned int index) const
    {
      if(index >= nodes_.size())
        return 0;

      if(changes_ != ownerDoc_->changes())
        populate();

      return nodes_[index];
    } // item

    virtual unsigned int getLength() const
    {
      if(changes_ != ownerDoc_->changes())
        populate();

      return static_cast<unsigned int>(nodes_.size());
    } // getLength

  private:
    void populate() const
    {
			NodeListT dummy;
      nodes_.swap(dummy);

      checkNode(rootNode_);

      changes_ = ownerDoc_->changes();
    } // populate

    void checkNode(DOM::Node_impl<stringT>* node) const
    {
      if(useNamespace_)
      {
        if((node->hasNamespaceURI() && namespaceURI_ == node->getNamespaceURI()) || allNamespaces_)
        {
          if((tagName_ == node->getLocalName()) || (allNames_ && node->getNodeType() == DOM::Node<stringT>::ELEMENT_NODE))
            nodes_.push_back(node);
        }
      } 
      else
        if((tagName_ == node->getNodeName()) || (allNames_ && node->getNodeType() == DOM::Node<stringT>::ELEMENT_NODE))
          nodes_.push_back(node);

      for(DOM::Node_impl<stringT>* child = node->getFirstChild(); child != 0; child = child->getNextSibling())
        if(child->getNodeType() == DOM::Node<stringT>::ELEMENT_NODE)
          checkNode(child);
    } // checkNode
    

    typedef std::deque<DOM::Node_impl<stringT>*> NodeListT;
    mutable NodeListT nodes_;
    DOM::Node_impl<stringT>* rootNode_;
    DocumentImpl<stringT, string_adaptorT>* ownerDoc_;
    stringT namespaceURI_;
    stringT tagName_;
    bool useNamespace_;
    bool allNamespaces_;
    bool allNames_;
    mutable unsigned int changes_;
    unsigned int refCount_;
}; // class ElementByTagList

} // namespace SimpleDOM

#endif


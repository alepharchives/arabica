#ifndef test_hc_documentcreateelementcasesensitive
#define test_hc_documentcreateelementcasesensitive


/*
This C++ source file was generated for Arabica
from the source document contained in the W3C
DOM Conformance Test Suite.
The source document contained the following notice:


Copyright (c) 2001-2003 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/
/**
 *     The tagName parameter in the "createElement(tagName)"
 *    method is case-sensitive for XML documents.
 *    Retrieve the entire DOM document and invoke its 
 *    "createElement(tagName)" method twice.  Once for tagName
 *    equal to "acronym" and once for tagName equal to "ACRONYM"
 *    Each call should create a distinct Element node.  The
 *    newly created Elements are then assigned attributes 
 *    that are retrieved.
 *    Modified on 27 June 2003 to avoid setting an invalid style
 *    values and checked the node names to see if they matched expectations.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-2141741547">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-2141741547</a>
* @see <a href="http://www.w3.org/Bugs/Public/show_bug.cgi?id=243">http://www.w3.org/Bugs/Public/show_bug.cgi?id=243</a>
*/

template<class string_type, class string_adaptor>
class hc_documentcreateelementcasesensitive : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     hc_documentcreateelementcasesensitive(std::string name) : baseT(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = baseT::getContentType();
    baseT::preload(contentType, "hc_staff", true);
    }

  typedef typename Arabica::DOM::DOMImplementation<string_type, string_adaptor>  DOMImplementation;
  typedef typename Arabica::DOM::Document<string_type, string_adaptor> Document; 
  typedef typename Arabica::DOM::DocumentType<string_type, string_adaptor> DocumentType;
  typedef typename Arabica::DOM::DocumentFragment<string_type, string_adaptor> DocumentFragment; 
  typedef typename Arabica::DOM::Node<string_type, string_adaptor> Node;
  typedef typename Arabica::DOM::Element<string_type, string_adaptor> Element;
  typedef typename Arabica::DOM::Attr<string_type, string_adaptor> Attr;
  typedef typename Arabica::DOM::NodeList<string_type, string_adaptor> NodeList;
  typedef typename Arabica::DOM::NamedNodeMap<string_type, string_adaptor> NamedNodeMap;
  typedef typename Arabica::DOM::Entity<string_type, string_adaptor> Entity;
  typedef typename Arabica::DOM::EntityReference<string_type, string_adaptor> EntityReference;
  typedef typename Arabica::DOM::CharacterData<string_type, string_adaptor> CharacterData;
  typedef typename Arabica::DOM::CDATASection<string_type, string_adaptor> CDATASection;
  typedef typename Arabica::DOM::Text<string_type, string_adaptor> Text;
  typedef typename Arabica::DOM::Comment<string_type, string_adaptor> Comment;
  typedef typename Arabica::DOM::ProcessingInstruction<string_type, string_adaptor> ProcessingInstruction;
  typedef typename Arabica::DOM::Notation<string_type, string_adaptor> Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;


   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      Element newElement1;
      Element newElement2;
      String attribute1;
      String attribute2;
      String nodeName1;
      String nodeName2;
      doc = (Document) baseT::load("hc_staff", true);
      newElement1 = doc.createElement(SA::construct_from_utf8("ACRONYM"));
      newElement2 = doc.createElement(SA::construct_from_utf8("acronym"));
      newElement1.setAttribute(SA::construct_from_utf8("lang"), SA::construct_from_utf8("EN"));
      newElement2.setAttribute(SA::construct_from_utf8("title"), SA::construct_from_utf8("Dallas"));
      attribute1 = newElement1.getAttribute(SA::construct_from_utf8("lang"));
      attribute2 = newElement2.getAttribute(SA::construct_from_utf8("title"));
      baseT::assertEquals("EN", attribute1, __LINE__, __FILE__);
  baseT::assertEquals("Dallas", attribute2, __LINE__, __FILE__);
  nodeName1 = newElement1.getNodeName();
      nodeName2 = newElement2.getNodeName();
      baseT::assertEquals("ACRONYM", nodeName1, __LINE__, __FILE__);
  baseT::assertEquals("acronym", nodeName2, __LINE__, __FILE__);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/hc_documentcreateelementcasesensitive";
   }
};

#endif

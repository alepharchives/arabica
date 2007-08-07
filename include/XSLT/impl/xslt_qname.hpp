#ifndef ARABICA_XSLT_QNAME_HPP
#define ARABICA_XSLT_QNAME_HPP

namespace Arabica
{
namespace XSLT
{

struct QName
{
  std::string prefix;
  std::string localName;
  std::string namespaceURI;

  static QName createQName(const std::string& qName) 
  {
    QName qn;

    size_t colon = qName.find(':');
    if(colon == std::string::npos)
      qn.localName = qName;
    else
    {
      qn.prefix = qName.substr(0, colon);
      qn.localName = qName.substr(colon+1);
    }

    return qn;
  } // createQName

  static QName createQName(const std::string& qName, const std::string namespaceURI) 
  {
    QName qn(createQName(qName));
    qn.namespaceURI = namespaceURI;
  
    if(!qn.prefix.empty() && qn.namespaceURI.empty())
      throw SAX::SAXException("Undeclared prefix " + qn.prefix);
    return qn;
  } // createQName
}; // QName


} // namespace XSLT
} // namespace Arabica
#endif
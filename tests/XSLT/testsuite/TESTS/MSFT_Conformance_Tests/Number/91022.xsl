<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<!-- XSLT - Numbering - Rounding and conversion to number of value attribute -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/18/2000 -->

	<xsl:template match="/">
        <xsl:number value="1999"/><BR/>
        <xsl:number value="1999.499999999"/><BR/>
        <xsl:number value="'1999'"/><BR/>
        <xsl:number value="'1999.5'"/><BR/>
        <xsl:number value=".00000000000000000000000000001"/><BR/>
        <xsl:number value="-2147483648"/><BR/>
        <xsl:number value="2147483647"/>
	</xsl:template>
   
</xsl:stylesheet>  

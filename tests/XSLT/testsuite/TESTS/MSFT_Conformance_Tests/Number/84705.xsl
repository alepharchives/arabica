<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output encoding="UTF-16"/>

<!-- XSLT: Number formatting - format="&#x05d0;" (Hebrew)- letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/05/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//שדקראט">  
			<TR><TD>  
				<TD>
					<xsl:number format="&#x05d0;" letter-value="alphabetic" /> -
					<xsl:number format="&#x05d0;" letter-value="traditional" /> -
					<xsl:value-of select = "text()"/>										
				</TD>
			</TD></TR>  
		</xsl:for-each>  
	</TABLE>  
</xsl:template>  

</xsl:stylesheet>  

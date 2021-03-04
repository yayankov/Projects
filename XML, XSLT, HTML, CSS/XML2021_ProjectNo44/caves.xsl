<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
    <xsl:output method="xml" version="1.0" indent="yes"/>
    <xsl:template match="/">
        <fo:root>
            <fo:layout-master-set>
                <fo:simple-page-master page-height="297mm" page-width="210mm"
                    margin="5mm 25mm 5mm 25mm" master-name="page">
                    <fo:region-body margin="20mm 0mm 20mm 0mm"/>
                </fo:simple-page-master>
            </fo:layout-master-set>

    <!--  HeaderPage  -->
            
            <fo:page-sequence master-reference="page">
                <fo:flow flow-name="xsl-region-body">
                    <fo:block-container position ="absolute" top="-2.5cm" left = "-2.5cm" >
                        <fo:block position ="absolute" text-align ="center" font-weight="bold" margin-left="2cm"
                        font-family="Monotype Corsiva" font-size="48pt" padding-before="50mm" color="black" >
                            <fo:block margin-bottom="50mm">
                                Каталог на пещери в България
                            </fo:block>
                        </fo:block>
                    </fo:block-container>
                </fo:flow>
            </fo:page-sequence>
            
    <!--  Caves  -->
                
            <fo:page-sequence master-reference="page">
                <fo:flow flow-name="xsl-region-body">
                    <fo:block-container position ="relative" top="-2.5cm" left = "-2.5cm" >											
                            
                                            
                        <fo:block position="relative" text-align ="center" font-family="Arial" font-weight="bold" font-size="22pt" color="black" padding-before="5mm">
                            Южен централен район
                        </fo:block> 

                        <fo:block position="relative" padding-before = "5mm" >			
                            <xsl:for-each select=".//district[@regionId='SC']/cave">												
                                <xsl:apply-templates select="."/>		
                            </xsl:for-each>
                        </fo:block>


                        <fo:block position="relative" text-align ="center" font-family="Arial" font-weight="bold" font-size="22pt" color="black" padding-before="5mm">
                            Северозападен район
                        </fo:block> 

                        <fo:block position="relative" padding-before = "5mm" >			
                            <xsl:for-each select=".//district[@regionId='NW']/cave">												
                                <xsl:apply-templates select="."/>		
                            </xsl:for-each>
                        </fo:block>

                        
                        <fo:block position="relative" text-align ="center" font-family="Arial" font-weight="bold" font-size="22pt" color="black" padding-before="5mm">
                            Северoизточен район
                        </fo:block> 

                        <fo:block position="relative" padding-before = "5mm" >			
                            <xsl:for-each select=".//district[@regionId='NC']/cave">												
                                <xsl:apply-templates select="."/>		
                            </xsl:for-each>
                        </fo:block>								
                                    
                                
                    </fo:block-container>
                </fo:flow>
            </fo:page-sequence>
            
        </fo:root>
    </xsl:template> 

    <!--  CaveTemplate -->

        <xsl:template match="cave">

            <fo:block position="relative" text-align ="center" font-family="Arial" font-style="italic" font-weight="bold" color="black" font-size="19pt"
            padding-before="5mm">
                    <xsl:value-of select="./title/text()"/> 
            </fo:block> 
            
            <fo:block position="absolute" text-align = "center" padding-before = "10mm" padding-after="5mm" >
                <xsl:apply-templates select="./image"/>
            </fo:block>	
            
            <fo:block position="relative" font-family="Arial" font-weight="bold" font-size="14pt" color="black" padding-before="5mm">
                Описание:
                <fo:inline position="relative" padding-left="5mm" font-weight="normal" font-size="14pt" >
                    <xsl:value-of select="./description/text()"/> 
                </fo:inline>
		    </fo:block> 

            <fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="14pt" padding-before="5mm" padding-after="5mm">
                Интересно за пещерата:			
                <fo:block position="relative" padding-before="5mm" padding-left="5mm" font-weight="normal" font-size="14pt" >
                    <xsl:apply-templates select="./characteristics"/> 
                </fo:block>
            </fo:block> 

            <fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="14pt" padding-before="5mm" padding-after="1mm">
                Карта:
            </fo:block>
            <fo:block position="absolute" text-align = "center" padding-before = "10mm" padding-after="5mm" >
                <xsl:apply-templates select="./map"/>
            </fo:block>	

            <fo:block position="relative" font-weight="bold" font-family="Arial" color="black" font-size="14pt" padding-before="5mm" padding-after="40mm">
                Интересно за туристите:			
                <fo:block position="relative" padding-before="5mm" padding-left="5mm" font-weight="normal" font-size="14pt" >
                    <xsl:apply-templates select="./forTourists"/> 
                </fo:block>
            </fo:block> 

        </xsl:template>

<!--  CharacteristicsTemplate  -->

	<xsl:template match="characteristics">
	  <fo:table >
		<fo:table-body>		
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Локация</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./location/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>			
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Планина</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./mountain/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>						
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Дължина</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./length/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
			
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Фауна:</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./animalSpecies/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
					
			
		</fo:table-body>
	  </fo:table>
	</xsl:template>


<!--  ForTouristsTemplate  -->

	<xsl:template match="forTourists">
	  <fo:table >
		<fo:table-body>		
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Работно време:</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./workingTime/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>			
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Цена:</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./cost/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>						
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Телефон</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./phoneNumber/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
			
			<fo:table-row>
				<fo:table-cell border="solid" font-weight="bold" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm">
					<fo:block>Време за посещение:</fo:block>
				</fo:table-cell>
				<fo:table-cell border="solid" text-align="center" padding-left="3mm" padding-right="3mm" padding-before="5mm" padding-after="5mm" font-size="12pt">
					<fo:block   >
						<xsl:value-of select="./visitTime/text()"/>
					</fo:block >
				</fo:table-cell>
			</fo:table-row>
					
		</fo:table-body>
	  </fo:table>
	</xsl:template>


<!-- ImageTemplateCave -->

	<xsl:template match="image">
		<fo:external-graphic src="{unparsed-entity-uri(@href)}" content-height="700" content-width="800"/>
	</xsl:template>

<!-- ImageTemplateMap -->

	<xsl:template match="map">
		<fo:external-graphic src="{unparsed-entity-uri(@href)}" content-height="410" content-width="510"/>
	</xsl:template>

</xsl:stylesheet>

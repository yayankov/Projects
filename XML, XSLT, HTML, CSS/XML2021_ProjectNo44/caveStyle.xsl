<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <link rel="stylesheet" type="text/css" href="style.css" />
                <title>Каталог на пещери</title>
            </head>
            <body>
                <h1 id="main-title"> Каталог на пещерите в България </h1>

                <div id="container">
                    <xsl:for-each select="catalogCaves/caveList/district">
                        
                        <h2 class="region-title">
                            <xsl:value-of select="id(@regionId)"/>
                        </h2>
                        
                        <xsl:for-each select="./cave">
                            
                            <h3 class="cave-title">
                                <xsl:value-of select="title"/>
                            </h3>
                            <p class="cave-image">
                                <img src="{unparsed-entity-uri(image/@href)}"/>
                            </p>    

                            <div class="description">
                                <h4 class="description-title">Описание: </h4>
                                <p class="description-text">
                                    <xsl:value-of select="description"/>
                                </p>
                            </div>
                            
                            <div class="map">
                                <h4 class="map-title">Карта:</h4> 
                                <p class="map-image">   
                                    <img src="{unparsed-entity-uri(map/@href)}"/>
                                </p>   
                            </div>

                            <div class="characteristics">
                                <h4 class="characteristics-title">Интересно за пещерата:</h4>
                                <p class="characteristics-text"> Област:
                                    <xsl:value-of select="characteristics/location"/>
                                </p>
                                <p class="characteristics-text"> Планина:
                                    <xsl:value-of select="characteristics/mountain"/>
                                </p>
                                <p class="characteristics-text"> Дължина:
                                    <xsl:value-of select="characteristics/length"/>
                                </p>
                                <p class="characteristics-text"> Фауна:
                                    <xsl:value-of select="characteristics/animalSpecies"/>
                                </p>
                            </div>

                            <div class="forTourists">
                                <h4 class="forTourists-title">Полезно за туристите:</h4>
                                <p> Работно време:
                                    <xsl:value-of select="forTourists/workingTime"/>
                                </p>
                                <p class="forTourists-text"> Цена:
                                    <xsl:value-of select="forTourists/cost"/>
                                </p>
                                <p class="forTourists-text"> Телефон за връзка:
                                    <xsl:value-of select="forTourists/phoneNumber"/>
                                </p>
                                <p class="forTourists-text"> Времетраене на обиколка:
                                    <xsl:value-of select="forTourists/visitTime"/>
                                </p>
                            </div>
                            
                            
                        </xsl:for-each>

                    </xsl:for-each>

                </div>  
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>

package module6;

import java.util.List;

import de.fhpotsdam.unfolding.data.Feature;
import de.fhpotsdam.unfolding.data.PointFeature;
import de.fhpotsdam.unfolding.marker.SimpleLinesMarker;
import processing.core.PConstants;
import processing.core.PGraphics;
import processing.core.PImage;

/** 
 * A class to represent AirportMarkers on a world map.
 *   
 * @author Adam Setters and the UC San Diego Intermediate Software Development
 * MOOC team
 *
 */
public class AirportMarker extends CommonMarker {
	public static List<SimpleLinesMarker> routes;
	
	PImage img;
	
	public AirportMarker(Feature city, PImage _img) {
		super(((PointFeature)city).getLocation(), city.getProperties());
		this.img = _img;
	}
	
	@Override
	public void drawMarker(PGraphics pg, float x, float y) {
		//pg.fill(11);
		//pg.ellipse(x, y, 5, 5);
		pg.image(img, x-15, y-15);
		
	}
	
	@Override
	public void showTitle(PGraphics pg, float x, float y) {
		 // show rectangle with title
		String city = getCity() + ", " + getCountry();
		pg.pushStyle();
		
		pg.rectMode(PConstants.CORNER);
		
		pg.stroke(110);
		pg.fill(255,255,255);
		pg.rect(x, y + 15, pg.textWidth(city) +6, 18, 5);
		
		pg.textAlign(PConstants.LEFT, PConstants.TOP);
		pg.fill(0);
		pg.text(city, x + 3 , y +18);
		
		
		pg.popStyle();
		
	}
	
	public String getCity() {
		return (String) getProperty("city");	
		
	}

	public String getCode() {
		return (String) getProperty("code");	
	}
/*
	public String getId() {
		return (String) getProperty("id");	
	}
	*/
	public String getCountry() {
		return (String) getProperty("country");	
	}

	
}

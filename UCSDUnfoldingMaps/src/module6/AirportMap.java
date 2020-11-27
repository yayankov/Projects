package module6;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

import de.fhpotsdam.unfolding.UnfoldingMap;
import de.fhpotsdam.unfolding.data.PointFeature;
import de.fhpotsdam.unfolding.data.ShapeFeature;
import de.fhpotsdam.unfolding.marker.Marker;
import de.fhpotsdam.unfolding.marker.SimpleLinesMarker;
import de.fhpotsdam.unfolding.utils.MapUtils;
import de.fhpotsdam.unfolding.geo.Location;
import parsing.ParseFeed;
import processing.core.PApplet;
import processing.core.PImage;

/** An applet that shows airports (and routes)
 * on a world map.  
 * @author Adam Setters and the UC San Diego Intermediate Software Development
 * MOOC team
 *
 */
public class AirportMap extends PApplet {
	
	
	
	UnfoldingMap map;
	private List<Marker> airportList;
	List<Marker> routeList;
	
	// NEW IN MODULE 5
	private CommonMarker lastSelected;
	private CommonMarker lastClicked;
	
	PImage img;
	private HashMap<Integer, Location> airports = new HashMap<Integer, Location>();

	public void setup() {
		// setting up PAppler
		size(800,600, OPENGL);
		// setting up map and default events
		map = new UnfoldingMap(this, 50, 50, 750, 550);
		MapUtils.createDefaultEventDispatcher(this, map);
		
		img = loadImage("file:///C:/Users/yanis/Downloads/pngfind.com-airport-png-6003446.png","png");
		img.resize(28, 28);
		
		// get features from airport data
		List<PointFeature> features = ParseFeed.parseAirports(this, "airports.dat");
		
		// list for markers, hashmap for quicker access when matching with routes
		airportList = new ArrayList<Marker>();
		// create markers from features
		for(PointFeature feature : features) {
			AirportMarker m = new AirportMarker(feature, img);
	
			m.setRadius(5);
			airportList.add(m);
			
			// put airport in hashmap with OpenFlights unique id for key
			airports.put(Integer.parseInt(feature.getId()), feature.getLocation());
		
		//	System.out.println(airports);
		}
		
		
		// parse route data
		List<ShapeFeature> routes = ParseFeed.parseRoutes(this, "routes.dat");
		routeList = new ArrayList<Marker>();
		for(ShapeFeature route : routes) {
			
			// get source and destination airportIds
			int source = Integer.parseInt((String)route.getProperty("source"));
			int dest = Integer.parseInt((String)route.getProperty("destination"));
			
			// get locations for airports on route
			if(airports.containsKey(source) && airports.containsKey(dest)) {
				route.addLocation(airports.get(source));
				route.addLocation(airports.get(dest));
			}
			
			SimpleLinesMarker sl = new SimpleLinesMarker(route.getLocations(), route.getProperties());
		
			//System.out.println(sl.getProperties() + " ,    " + sl.getLocations());
			
			//UNCOMMENT IF YOU WANT TO SEE ALL ROUTES
			routeList.add(sl);
			
		}
		
		map.addMarkers(airportList);
		map.addMarkers(routeList);
		
	}
	
	public void draw() {
		background(0);
		map.draw();
	}
	
	@Override
	public void mouseMoved()
	{
		// clear the last selection
		if (lastSelected != null) {
			lastSelected.setSelected(false);
			lastSelected = null;
		
		}
		selectMarkerIfHover(airportList);
		//loop();
	}
	
	// If there is a marker selected 
	private void selectMarkerIfHover(List<Marker> markers)
	{
		// Abort if there's already a marker selected
		if (lastSelected != null) {
			return;
		}
		
		for (Marker m : markers) 
		{
			CommonMarker marker = (CommonMarker)m;
			if (marker.isInside(map,  mouseX, mouseY)) {
				lastSelected = marker;
				
				//System.out.println(lastSelected.getProperties());
				//System.out.println(lastSelected.getProperty("id"));
				
				marker.setSelected(true);
				return;
			}
		}
	}

	/** The event handler for mouse clicks
	 * It will display an earthquake and its threat circle of cities
	 * Or if a city is clicked, it will display all the earthquakes 
	 * where the city is in the threat circle
	 */
	@Override
	public void mouseClicked()
	{
		if (lastClicked != null) {
			unhideMarkers();
			lastClicked = null;
		}
		else if (lastClicked == null) 
		{
			for (Marker m : airportList) {
				AirportMarker marker = (AirportMarker)m;
				
				if (!marker.isHidden() && marker.isInside(map, mouseX, mouseY)) {
					lastClicked = marker;
					Location LocClicked = marker.getLocation();
					//System.out.println(LocClicked);
				//	String lastClickedId = lastClicked.getId();
					
					for (Marker mhide : airportList) {
						if (mhide != lastClicked) {
							mhide.setHidden(true);
						}
					}
					for (Marker r : routeList) {
						SimpleLinesMarker sl = (SimpleLinesMarker)r;
							
						Location LocSource = sl.getLocations().get(0);
						
						
						if (LocSource != LocClicked) {
							r.setHidden(true);
						} else {
							Location LocDest = sl.getLocations().get(1);
							for (Marker markAir : airportList) {
								AirportMarker Amark = (AirportMarker)markAir;
								Location LocClickedDest = Amark.getLocation();
								
								
								if(LocDest == LocClickedDest || markAir == lastClicked) {
									markAir.setHidden(false);
								}
							}
						}
					}/*
					for(Marker r : routeList) {
							
							
							if(locatClicked.equals(LocSource)) {
								System.out.println(LocSource);
								r.setHidden(false);
							} else {
								r.setHidden(true);
							}
						
					}*/
					return;
				}
			}
		}
	}
	// loop over and unhide all markers
	private void unhideMarkers() {
		for(Marker marker : airportList) {
			marker.setHidden(false);
		}
		for(Marker marker2 : routeList) {
			marker2.setHidden(false);
		}
	}
	
	
}

#ifndef CONNECTEDCITIES_H
#define CONNECTEDCITIES_H

#include <ctype.h>  // character manipualtion, e.g. tolower()
#include <stdio.h> 
#include <string>
#include <vector>

using namespace std;

// IMPORTANT: You must NOT use any global variables 

// A city class to store a city vertice / node in the city graph
// You must NOT change this class
class CityNode {
private:     
  string city;
  vector<string> directRoutedCities;
  vector<string> reachableCities;

public:
  CityNode(string city) {
    this->city = city;
  }

  inline string getCity() {
    return city;
  }

  inline vector<string> getDirectRoutedCities() {
    return directRoutedCities;
  }

  inline vector<string> getReachableCities() const {
    return reachableCities;
  }

  inline void addADirectRoutedCity(string city) {
    directRoutedCities.push_back(city);
  }

  inline void addReachableCity(string city) {
    reachableCities.push_back(city);
  }

  inline void setReachableCities(vector<string> rCities) {
    reachableCities = rCities;
  }
};


class ConnectedCities {
    
public:
  
  /**
  * <p>
  * Part A 
  * ---------------------------------------------------------------------------------------
  * For each city in a city list, find the list of reachable cities starting from the city 
  * following the train routes, and sort the cities in the descending order based on the 
  * number of their reachable cities.  
  * 
  * Required specifications - 
  *
  * Given a list of cities, and a list of one-way train routes from one city to another:
  *
  * 1) Create a graph with each node in the graph as an instance of the CityNode class,
  *    the graph can use any STL collection by your choice.
  *
  * 2) Populate the direct routes information to each CityNode's directRoutedCities collection.
  *
  * 3) For each city node in the graph, use Depth First Search algorithm to find all reachable 
  *    cities starting from the city following the train routes and store those reachable cities to 
  *    the CityNode's reachableCities collection. 
  *
  *    IMPORTANT: The reachable cities must include the starting city itself.  
  *
  *    Note: The train route can go from the starting city and stop at several cities 
  *          before reaching the destination city, all cities including the starting city and 
  *          the destination city along the path would be counted as reachable cities from 
  *          the city where the train starts.
  *
  * 4) Sort the cities in the descending order based on the number of their reachable cities,
  *    so that after sorting, starting from the first city in the sorted order, the train can 
  *    reach the greatest number of destination cities following the given one-way routes. 
  *
  * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part to find
  *    all reachable cities from a starting city given the train routes, using an iterative 
  *    approach would result in a 30% penalty to your assignment 4 grade.  
  *
  * 6) You may add necessary helper functions as needed. Follow the comments for hints.
  * 
  * Assumptions - 
  * 1) Each city is represented by a unique two-letter code like "SD", "LA", 
  *    "SF", "SJ", "NY", etc.
  * 2) Each one-way train route is represented by a pair of city codes; for example, 
  *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to 
  *    Los Angeles (LA). 
  *
  * <p>
  * Part B
  * ---------------------------------------------------------------------------------------
  * Show the upper bound of the time complexity of this function would be O(c^2 + c * r) 
  * where:
  * c is the number of cities
  * r is the number of direct routes between cities
  * 
  * ---------------------------------------------------------------------------------------
  * @param  cities  a list of cities with each city identified by a unique two letter code
  * @param  routes  pairs of one-way train routes with each one-way train route represented 
  *                 by a pair of city codes; for example, route {"SD", "LA"} means train 
  *                 can go one-way from San Diego (SD) to Los Angeles (LA).
  *
  *                 NOTE: examples of routes are { {"SD", "LA"},
  *                                                {"LA", "SJ"},
  *                                                {"SJ", "SF"}
  *                                              }   
  *                       refer to driver.cpp for more examples.  
  *
  * @return       A list of CityNodes in descending order of number of reachable cities and 
  *               using ascending alphabetical order of the city code as the tiebreaker.
  * @see         
  */
  static vector<CityNode> citiesSortedByNumOf_Its_ReachableCities_byTrain(
                            vector<string> cities, 
                            vector<pair<string, string>> trainRoutes);

  static string recursivelyGetPath(CityNode node);

  static vector<pair<string, long unsigned int>> sortingFunction (vector<pair<string, long unsigned int>> vect);
};

#endif
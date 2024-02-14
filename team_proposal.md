## Leading Question

If all roads once led to Rome, where do all airports lead to today? This is not a question of which airport is easiest to get to in the world, but which airport you will be most likely to eventually end up at if you travel randomly. We argue that this is similar to the problem which the PageRank algorithm seeks to solve for the interned: which page will a random web user end up on if they click random links (i.e. to which websites do all, or at least the most, links eventually lead). Therefore using data with the possible flight destinations from each of a set of the world's airports and treating these as directed "links" from one airport to another, we can apply the pagerank algorithm to find the most led-to airport. We can apply other algorithms to flight data to and from this "most led-to airport" to determine how important this title actually is: for example, what airport is connected to the "most led-to airport" by the longest and shortest path?

## Dataset Acquisition

We will use publicly available flight and airport data from the Open Flights database.

## Data Format

Open Flights data is available on a public github page in csv format, with the data enclosed in several files. Airports.dat includes data on a large number of airports around the world, which will be the airports included in our pagerank algorithm (after all, even if there are no available routes for an airport, this will appropriately rate the airport very low). Routs.dat includes route data showing the flight routes from an origin airport to a destination. We will include all routes that we can pair with an airport from the airports.dat file, and that pass our data correction checks. These routes will determine the directed edges of our graph, while the airports are nodes. Note that routes with stops are considered to be a route from the starting to ending airport without the stops counted.

## Data Correction

Firstly, we will throw out any route that does not correspond to known airports from the airports.dat file. The minimum data that we need to build an adjacency list is:

From airports.dat:
Openflights Airport ID: a unique identifier assigned to all airports on openflights

From routes.dat:
Openflights Airport ID for both departing and arriving airports (must be unequal)

We will use all route and airport entries from the files that contain these key data.

## Data Storage


We will first load the airport data into an stl map associating each airport id (which are ints) to an empty vector of ints. We will then construct an adjacency list from this map using the route data to assign edges, which will take up O(m+n) space, where m is the number of routes and n is the number of airports. In the worst case, O(m) =O(m+n)=O(n)^2, since this is the case where there is a route from every airport to every airport.

Traversals will be implemented using a stack from the standard template library, which does not affect the total space complexity.

## Algorithm

Pagerank

The main algorithm that will be used to rank airports is pagerank. The idea of pagerank is that it measures the importance of each item in a list. We will use an adjacency list in our page ranking algorithm, the construction of which is partly outlined in the data storage section. In addition, we must weight the edges (flights) so that all values associated with a particular key in the adjacency list add to 1, which also requires that we give any airport with no edges an edge to all other airports with weight 1/n (perhaps suggesting taking another mode of transport to a random location to leave the isolated airport).

This algorithm will have a runtime of O(n + m) with the worst case being O(n^2) where n is the number of edges (routes) and m is the number of vertices (airports). The space complexity is also O(n+m), since we must store all routes and all airports.

The input will include the graph’s adjacency list, and the output will be an std vector containing each airport's weighting based on its relative importance. When called from the command line, we can output the n most important airports according to pagerank.

Dijkstra's Algorithm:

We can use Dijkstra’s algorithm to find the shortest path from the highest ranked airport to an airport entered by the user. Dijkstra’s algorithm takes an adjacency list as the input in addition to the start and destination airports, and takes O(m+nlog(n)) runtime and O(n) space complexity, where m is the number of routes and n is the number of airports. When called from the command line with start and end airports, the function will output the shortest path from the start to the end (which we can store and output from the function as a vector). 

Depth First Search (Traversals)

Depth first search runs in O(n + m) time where n is the number of airports and m is the number of routes. The space complexity is O(n) or the number of airports, since we must store the visited airports which is in the worst case the total number of airports.

We are going to use a depth first search to traverse and check if there is a path from an arbitrary airport that leads to the highest ranking/(possibly arbitrary) airport.

## Timeline - from Monday to Sunday

Week 1: November 7th to November 13th

Meeting: Meet up November 8th - late evening

General functions done by November 9th
 
Most pseudocode is done by November 11th.

(Gonna have some functions we don’t understand)

All pseudocode is done by November 12th.



Week 2: November 14th to November 20th

Assign roles

Implement the code for the algorithms

Week 3: November 21st to November 27th

Room for more time for either thinking about how functions will work or physical code

Week 4: November 28th to December 4th

At this point all code needs to be done

Debug

Week 5: December 5th to December 8th (short week)

Create the writeups and video


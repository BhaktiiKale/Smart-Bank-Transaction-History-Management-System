# Water Pumping Station and Pipeline Route Optimization

## Project Overview
This project uses Dijkstra's Algorithm in C++ to find the minimum-cost route between water pumping stations and a selected distribution point.

## Objectives
- Represent water stations as graph vertices.
- Represent pipelines as weighted edges.
- Find the shortest route between two selected stations.
- Calculate the minimum total distance or transportation cost.

## Features
- Six predefined water stations.
- Source and destination selection.
- Weighted pipeline network.
- Shortest-path calculation using Dijkstra's Algorithm.
- Displays the complete minimum-cost route.
- Displays total distance or cost.
- Validates station numbers.

## Technologies Used
- Programming Language: C++
- Algorithm: Dijkstra's Algorithm
- Data Structure: Weighted Graph
- IDE: Dev-C++

## Water Stations
1. Pump Station A
2. Pump Station B
3. Pump Station C
4. Pump Station D
5. Pump Station E
6. Distribution Point F

## Algorithm
1. Create a weighted graph.
2. Select the source and destination.
3. Initialize distances.
4. Select the unvisited station with minimum distance.
5. Update distances if a shorter path is found.
6. Reconstruct the shortest route.
7. Display the route and total cost.

## Sample Output
Source: Pump Station A

Destination: Distribution Point F

Minimum-Cost Route:
Pump Station A -> Pump Station C -> Pump Station B -> Pump Station D -> Pump Station E -> Distribution Point F

Minimum Total Distance/Cost: 13 units

## Applications
- Water supply network planning
- Pipeline route optimization
- Transportation cost estimation

## Conclusion
This project demonstrates the use of Dijkstra's Algorithm to find a minimum-cost route in a weighted water pipeline network.

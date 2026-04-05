Project Title: Smart Traffic Intersection Simulator
By Amy Castillo, Daren Xu, and Adam Moffat

Project overview:

In this project, we will be implementing a Traffic Intersection simulation. This simulation will model cars on a two-way street with a traffic light. The cars will stop and form a line when the light is red, slow down and stop when the light turns yellow, and drive through the light if it is green. Additionally, if there is an emergency vehicle, it can go through any light and skip the line of vehicles.

Main functionalities:
There will be functions involving the vehicles, traffic lights, and lanes. Additionally, we will have a class that includes interactions among the vehicles, traffic lights, and lanes, using clock functions. To run this program use the following commands below.

g++ main.cpp Vehicle.cpp TrafficLight.cpp Lane.cpp Intersection.cpp SimClock.cpp Stats.cpp Simulator.cpp -o main
./main

OOP design summary:
There are 4 main classes. These classes are the Vehicle class, Traffic Light Class, Lane Class, and Intersection class. The Vehicle Class will create the vehicle and update its speed and position. The traffic light class will update its own lights, allowing vehicles to move. Additionally, functions have been implemented to enable emergency mode, allowing the emergency vehicle to go through the lights. The lane class's main functions are to add vehicles to a queue, update wait times, find the queue length, and count the number of vehicles that have gone through the lights. Finally, the intersection class controls the colors of the lights, ensuring the two traffic lights are synchronized. This class will utilize a clock timer. 

Tools and technologies:
We are using the VS Code application for C++ development. Additionally, if time permits, we will use SFML to simulate our project.

Folder structure:
SRC is a folder containing all the code for the final project. The Docs folder contains documents related to the final project, such as the project schedule.

Project goals:
The overall goal of this project is to properly simulate a basic intersection where vehicles line up when the lights are red or yellow, and continue driving when the light turns green. Additionally, we hope to implement a properly functioning emergency vehicle that can drive through any light color. The team is also looking forward to learning and using simulation tools to test our code. The team is also using this project to deepen our understanding of being a C++ programmer and of OOP concepts.

GitHub repository purpose:
The purpose of this GitHub repository is to keep all related materials for the final project in a sorted, accessible place. Any notes, documents about iteration assignments, and all of the code we use will be pushed to GitHub.

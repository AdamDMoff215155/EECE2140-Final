#include <iostream>
#include "Vehicle.h"
#include "TrafficLight.h"
#include "Lane.h"
using namespace std;

int main() {

   
    Vehicle car("Toyota", "Red", false, 0.0, 5.0);
    car.display();
    car.move(10);
    cout << "Position: " << car.getPosition() << endl;

    Vehicle ambulance("Nissan", "White", true, 0.0, 8.0);
    ambulance.display();
    cout << "It is an emergency vehicle: " << ambulance.isEmergency() << endl;

    TrafficLight light(5, 2, 5);  // green=5, yellow=2, red=5
    cout << "Initial state: " << light.getStateString() << endl;

    for (int i = 0; i < 10; i++) {
        light.update(false);
        cout << "Tick " << i + 1 << ": " << light.getStateString() << endl;
    }

    cout << "Emergency vehicle detected!" << endl;
    light.update(true);
    cout << "State during emergency: " << light.getStateString() << endl;


    return 0;
}
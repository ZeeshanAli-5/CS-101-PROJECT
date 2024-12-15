#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <string>
#include "myLib.h"

using namespace std;

// function prototypes


// main function
int main() {

    int sensors[4]; // array of four distance sensors
    string labels[4]; // array of labels for each sensor

    int dir; // indicates which direction to go next
    srand(time(NULL)); // initialize the random number generator

    labels[0] = "north"; // initialize the sensor labels
    labels[1] = "west";
    labels[2] = "south";
    labels[3] = "east";

    for (int i = 0; i < 5; i++) { // simulate 5 moves by the robot
        getSensors(sensors); // get values for all the sensors
        printSensors(sensors, labels); // print out the sensor values
        dir = furthest(sensors); // find the direction that is furthest from an obstacle
        cout << "moving " << labels[dir] << endl;  // "go"
    }

    return 0;
}

#pragma once

#include "FrontRearWheelDriveCar.h"

class MitsubishiTitan : public AllWheelDriveCar
{
public:
	string getManufacturer(){return "Mitsubishi";}
};

/*

Finally, the customer comes along and asks us to model for them a new experimental four wheel drive buggy that is designed to go on sand and turns with all four wheels.  A two wheel drive buggy is also available (it also turns with all four wheels).

Now we have a problem.  We will obviously be deriving from our four wheel drive class for the four wheel drive model and the two wheel drive class for the two wheel drive model, but we will also have to override our TurnLeft and TurnRight methods in both classes, and the code will be duplicated.

Arggg!  Duplicated code is the enemy of maintainability. The best solution to this problem is to switch our thinking. Instead of inheriting all of our functionality, we should compose our classes from pieces of related functionality.

Next up: a better way to solve the same problem.
*/
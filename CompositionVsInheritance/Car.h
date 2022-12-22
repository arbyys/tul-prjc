#pragma once
#include "BaseCar.h"

class Car : public BaseCar{
protected:
	Car(){
		this->setFrontLeft (new Wheel("Front left"));
		this->setFrontRight(new Wheel("Front right"));
		this->setRearLeft(new Wheel("Rear left"));
		this->setRearRight(new Wheel("Read right"));
	}

public:
	void turnLeft(double degrees)	{
		this->getFrontLeft()->turnLeft(degrees);
		this->getFrontRight()->turnLeft(degrees);
	}

	void turnRight(double degrees)	{
		this->getFrontRight()->turnRight(degrees);
		this->getFrontLeft()->turnRight(degrees);
	}

	void accelerate(double kph)	{
		this->getFrontLeft()->rotate(kph);
		this->getFrontRight()->rotate(kph);
	}
};

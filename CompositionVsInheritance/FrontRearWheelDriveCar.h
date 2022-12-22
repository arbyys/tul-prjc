#pragma once
#include "Car.h"
/*
Two weeks later the customer has come back.  They love what we’ve done and want us to implement HondaCivic and HondaCivicSports classes.  Now we run into our first real problem.  The rear-wheel drive code is actually in the concrete ToyotaCorollaSports class.  What we need to do now is actually refactor our Car class into FrontWheelDriveCar and RearWheelDriveCar.  HondaCivic and ToyotaCorolla can then both inherit from the FrontWheelDriveCar class and the sports editions can both inherit from the RearWheelDriveCar class.
*/
class FrontWheelDriveCar : public Car
{
public:
	void accelerate(double kph)
	{
		this->getFrontLeft()->rotate(kph);
		this->getFrontRight()->rotate(kph);
	}
};


class RearWheelDriveCar : public Car
{
public:
	void accelerate(double kph)
	{
		this->getRearLeft()->rotate(kph);
		this->getRearRight()->rotate(kph);
	}
};

/*

Our customers are very happy with what we have done so far and decide to commission us to create a four wheel drive Mitsubishi Titan.

So we now have to create an AllWheelDriveCar and inherit from that for our Mitsubishi Titan.
*/

class AllWheelDriveCar : public Car
{
public:
	void accelerate(double kph)	{
		this->getFrontLeft()->rotate(kph);
		this->getFrontRight()->rotate(kph);
		this->getRearLeft()->rotate(kph);
		this->getRearRight()->rotate(kph);
	}
};
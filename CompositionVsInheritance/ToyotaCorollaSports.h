#pragma once
#include "ToyotaCar.h"
/*
All fairly straight forward.  We have a nice little inheritance chain that seems to make sense (although perhaps I could have done away with the BaseCar class).

I submit this code to the customer and they are very happy.  They’re so happy that they will pay me more money to add extra features.  They now want me to implement a ToyotaCorollaSports class, which contains a rear-wheel drive version of the car.  In all other aspects it’s the same car, it’s only that the rear wheels are now powering the car.

Simple enough, I can inherit from the ToyotaCorolla and override the accelerate method.  I make the change and submit it to the customer.  They like what they see.

*/
class ToyotaCorollaSports : public ToyotaCorolla{
public:
	void accelerate(double kph)	{
		this->getRearLeft()->rotate(kph);
		this->getRearRight()->rotate(kph);
	}
};
#pragma once
#include <iostream>
#include<string>
using namespace std;

class Wheel {
private:
	string name;
public:
	Wheel(const string _name):name(_name){  }
	void turnLeft(double degrees) { cout << name << " wheel turning left " << degrees << endl; };
	void turnRight(double degrees) { cout << name << " wheel turning right " << degrees << endl; };
	void rotate(double kmsPerHour) { cout << name << " wheel rotating " << kmsPerHour << endl; };
};	

class BaseCar
{
private:
	Wheel *frontLeft;
	Wheel *frontRight;
	Wheel *rearLeft;
	Wheel *rearRight;
	std::string manufacturer;
public:
	Wheel *getFrontLeft() { return frontLeft; }
	Wheel *getFrontRight(){ return frontLeft; }
	Wheel *getRearLeft() { return rearLeft; }
	Wheel *getRearRight() { return rearRight; }

	void setFrontLeft(Wheel *_frontLeft) { frontLeft = _frontLeft; }
	void setFrontRight(Wheel *_frontRight) { frontRight = _frontRight; }
	void setRearLeft(Wheel *_rearLeft) { rearLeft = _rearLeft; }
	void setRearRight(Wheel *_rearRight) { rearRight = _rearRight; }
	void setManufacturer(const string _manufacturer) { manufacturer = _manufacturer; };
	string getManufacturer() { return manufacturer; };
	virtual void turnLeft(double degrees) =0;
	virtual void turnRight(double degrees)=0;
	virtual void accelerate(double kmsPerHour)=0;

	~BaseCar() {
		cout << "Calling BaseCar destructor " << endl;
		delete frontLeft; delete frontRight;
		delete rearLeft; delete rearRight;
	}
};
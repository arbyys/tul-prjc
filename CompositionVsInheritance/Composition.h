#pragma once
#include <string>
#include <iostream>
using namespace std;

/*
Yesterday, the first class that was designed was the BaseCar class, which contained a number of abstract methods which defined our behavior.It also contained our wheels.Today, instead, I am going to look at the behaviors of the car.It seems to me that there are two separate behaviors which are independent of each other.There is steering and there is driving(or accelerating).These behaviors will form the basis for our interface design.A car also has a manufacturer, so we will create an interface for that too.
*/

class IDriving
{
public:
	virtual void accelerate(double kph) = 0;
};

class ISteering
{
public:
	virtual void turnLeft(double degrees) = 0;
	virtual void turnRight(double degrees) = 0;
};

class IManufacturer{
private:
public:
	virtual string getManufacturer() = 0;
};

class CWheel {
private:
	string name;
public:
	CWheel(const string _name) :name(_name) {  }
	void turnLeft(double degrees) { cout << name << " wheel turning left " << degrees << endl; };
	void turnRight(double degrees) { cout << name << " wheel turning right " << degrees << endl; };
	void rotate(double kmsPerHour) { cout << name << " wheel rotating " << kmsPerHour << endl; };
};

/*
There are a couple of ways that we could look at designing the car interface. We could say that an ICar inherits from both ISteering and IDriving, but instead I think we should say that an ICar has both an ISteering and IDriving. This seems to make the most sense.
*/

class ICar {
private:
	CWheel *frontLeft;
	CWheel *frontRight;
	CWheel *rearLeft;
	CWheel *rearRight;
	ISteering *steering;
	IDriving *driving;
	IManufacturer *manufacturer;
public:
	CWheel *getFrontLeft() {	return frontLeft;};
	CWheel *getFrontRight() { return frontRight; };
	CWheel *getRearLeft() { return rearLeft; };
	CWheel *getRearRight() { return rearRight; };

	void setFrontLeft(CWheel *_wheel) { frontLeft = _wheel; };
	void setFrontRight(CWheel *_wheel) { frontRight = _wheel;};
	void setRearLeft(CWheel *_wheel) { rearLeft = _wheel; };
	void setRearRight(CWheel *_wheel) { rearRight = _wheel; };
	
	ISteering *getSteering() { return steering; }
	void setSteering(ISteering * _steering) { steering = _steering; }
	IDriving *getDriving() { return driving; }
	void setDriving(IDriving *_driving) { driving = _driving; }
	IManufacturer *getManufacturer(){ return manufacturer; }
	void setManufacturer(IManufacturer * _manufacturer) { manufacturer = _manufacturer; }

	~ICar() {
		cout << "Calling ICar destructor " << endl;
		delete frontLeft; delete frontRight;
		delete rearLeft; delete rearRight;
		delete steering; delete driving; delete manufacturer;
	}
};

/*
Already we can see that simply by thinking about the components and how they logically relate to each other, 
we have created a different design from before. The interfaces help us think more abstractly than base classes would otherwise had. 
Now that we have designed our interfaces (and the astute reader might have noticed that the Wheel class has now become an 
IWheel interface too, though defining either is beyond the scope of these articles) 
we can get started on defining the functionality of our classes.

First we will create a TwoWheelDrive class which implements the IDriving interface.
*/

class TwoWheelDrive : public IDriving
{
private:
	CWheel *left;
	CWheel *right;

public:
	TwoWheelDrive(CWheel *left, CWheel *right)	{
		this->left = left;
		this->right = right;
	}

	void accelerate(double kph)	{
		this->left->rotate(kph);
		this->right->rotate(kph);
	}
};

/*
Immediately it can be seen that this class can be used for both types of two wheel drive car – front or rear. All we will have to do is pass either the front or rear wheels to it. Next up we’ll implement the two wheel steering functionality in much the same way. Note that in this case, the steering class has to be a “front” steering class or a “rear” steering class, as each type of steering requires the wheels to turn in opposite directions to achieve the same outcome for the driver.
*/

class FrontSteering : public ISteering
{
private:
	CWheel *frontLeft;
	CWheel *frontRight;

public:
	FrontSteering(CWheel *frontLeft, CWheel *frontRight)	{
		this->frontLeft = frontLeft;
		this->frontRight = frontRight;
	}

	void turnLeft(double degrees)	{
		this->frontLeft->turnLeft(degrees);
		this->frontRight->turnLeft(degrees);
	}

	void turnRight(double degrees)	{
		this->frontLeft->turnRight(degrees);
		this->frontRight->turnRight(degrees);
	}
};

/*
And next, my Toyota manufacturer class. I’ve implemented it as a singleton because that will be sufficient for this problem.
*/
class Toyota : public IManufacturer
{
private:
	static IManufacturer *instance;
public:
	Toyota() {}

	string getManufacturer() { return "Toyota"; }
	
	static IManufacturer *getInstance(){
		if (instance == NULL) {
			instance = new Toyota();
		}
		return instance;
	}
};

IManufacturer * Toyota::instance = NULL;


class ToyotaCorollaComp : public ICar
{
public:
	ToyotaCorollaComp()	{
		this->setFrontLeft(new CWheel("Front left"));
		this->setFrontRight(new CWheel("Front right"));
		this->setRearLeft(new CWheel("Rear left"));
		this->setRearRight(new CWheel("Rear right"));
		this->setSteering( new FrontSteering(this->getFrontLeft(), this->getFrontRight()));
		this->setDriving( new TwoWheelDrive(this->getFrontLeft(), this->getFrontRight()));
		this->setManufacturer(Toyota::getInstance());
	}
};
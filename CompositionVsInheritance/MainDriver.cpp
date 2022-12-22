#include "Car.h"
#include "ToyotaCar.h"
#include "ToyotaCorollaSports.h"
#include "MitsubishiTitan.h"

#include "Composition.h"


/*
https://codingdelight.com/2014/01/16/favor-composition-over-inheritance-part-1/
*/

int main() {
	ToyotaCorolla toyotaCorolla;
	toyotaCorolla.accelerate(300);
	toyotaCorolla.turnLeft(30);

	ToyotaCorollaSports toyotaCorollaSports;
	toyotaCorollaSports.accelerate(10);


	MitsubishiTitan mitsubishiTitan;
	mitsubishiTitan.accelerate(854);
	cout << mitsubishiTitan.getManufacturer() << endl;
	cin.get();


	cout << "Composition" << endl;

	ToyotaCorollaComp toyotaCorollaComp;
	toyotaCorollaComp.getSteering()->turnLeft(300);
	cout << toyotaCorollaComp.getManufacturer()->getManufacturer() << endl;
	cin.get();
}
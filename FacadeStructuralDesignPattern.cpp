// FacadeStructuralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Facade is one of the easiest patterns I think... And this is very simple example.

Imagine you set up a smart house where everything is on remote. So to turn the lights on you push lights on button - And same for TV,
AC, Alarm, Music, etc...

When you leave a house you would need to push a 100 buttons to make sure everything is off and are good to go which could be little
annoying if you are lazy like me
so I defined a Facade for leaving and coming back. (Facade functions represent buttons...) So when I come and leave I just make one
call and it takes care of everything...
*/

#include <iostream>
#include <string>

using namespace std;

class Alarm
{
public:
	void alarmOn()
	{
		std::cout << "Alarm is on and house is secured\n";
	}
	void alarmOff()
	{
		std::cout << "Alarm is off and you can go into the house\n";
	}
};
class Ac
{
public:
	void acOn()
	{
		std::cout << "Ac is on\n";
	}
	void acOff()
	{
		std::cout << "Ac is off\n";
	}
};
class Tv
{
public:
	void tvOn()
	{
		std::cout << "Tv is on\n";
	}
	void tvOff()
	{
		std::cout << "Tv is off\n";
	}
};

class HouseFacade
{
private:
	Alarm alarm;
	Ac ac;
	Tv tv;
public:
	HouseFacade() {}

	void goToWork()
	{
		ac.acOff();
		tv.tvOff();
		alarm.alarmOn();
	}
	void comeBackHome()
	{
		alarm.alarmOff();
		ac.acOn();
		tv.tvOn();
	}
};
int main()
{
	HouseFacade houseFacade;

	//Rather than calling 100 different on and off functions thanks to facade I only have 2 functions...
	houseFacade.goToWork();
	houseFacade.comeBackHome();

	return 0;
}


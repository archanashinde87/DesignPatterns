// ObserverBehavioralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Suppose we are developing a weather monitoring application, in which multiple weather stations are responsible for collecting weather data, and we want to create a system where multiple displays can show real-time weather updates. When a weather station collects new data, all registered displays should be updated automatically with the latest information.

#include <iostream>
#include <vector>

// Observer interface
class Observer
{
public:
	virtual void update(double temperature, double humidity, double pressure) = 0;
};
// Subject/Publisher - Weather Station
class WeatherStation
{
private:
	double m_temperature{};
	double m_humidity{};
	double m_pressure{};
	std::vector<Observer*> m_observers;

public:
	void registerObserver(Observer* observer)
	{
		m_observers.push_back(observer);
	}
	void removeObserver(Observer* observer)
	{
		std::vector<Observer*>::iterator it;

		it = m_observers.begin();
		m_observers.erase(it);
	}
	void notifyObservers()
	{
		for (Observer* observer : m_observers)
			observer->update(m_temperature, m_humidity, m_pressure);
	}
	void setMeasurements(double temp, double hum, double press)
	{
		m_temperature = temp;
		m_humidity = hum;
		m_pressure = press;
		notifyObservers();
	}
};

// Concrete Observer
class Display:public Observer
{
public:
	void update(double temperature, double humidity, double pressure) override
	{
		std::cout << "Display: Temperature = " << temperature << "°C, Humidity = " << humidity
			<< "%, Pressure = " << pressure << " hPa" << std::endl;
	}
};
int main()
{
	WeatherStation weatherStation;

	// create displays
	Display display1;
	Display display2;

	// Register displays as observers
	weatherStation.registerObserver(&display1);
	weatherStation.registerObserver(&display2);

	// Simulate weather data updates
	weatherStation.setMeasurements(25.5, 60, 1013.2);
	weatherStation.setMeasurements(24.8, 58, 1014.5);

	return 0;
}


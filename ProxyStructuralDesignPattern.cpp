// ProxyStructuralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//Step 1: Define the Subject Interface
class Image
{
public:
	virtual ~Image() {}
	virtual void display() = 0;
};

// Step 2: Implement the real object
class RealImage : public Image
{
private:
	std::string m_filename{};
public:
	RealImage(const std::string& filename)
		: m_filename{ filename }
	{
		// Simulate loading the image (this can be a resource-intensive operation)
		std::cout << "Loading Image " << m_filename << endl;
	}
	void display() override
	{
		std::cout << "Displaying Image " << m_filename << endl;
	}
};

// Step 3 : Create the Proxy
class ProxyImage : public Image
{
private:
	RealImage* m_realImage{}; // Reference to the real object
	std::string m_filename{};
public:
	ProxyImage(const std::string& filename) : m_filename{ filename }, m_realImage{ nullptr } {}
	void display() override
	{
		if (m_realImage == nullptr)
			m_realImage = new RealImage{ m_filename };
		m_realImage->display();
	}
	~ProxyImage()
	{
		delete m_realImage;
	}
};

int main()
{
	// Create a proxy to an image
	Image* image = new ProxyImage("example.jpg");

	// Display the image (the Proxy will load the Real Object if necessary)
	image->display();

	// Displaying the image again (the Proxy won't reload it)
	image->display();

	delete image; // Clean up

	return 0;

}


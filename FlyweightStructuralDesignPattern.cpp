// FlyweightStructuralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;

// Flyweight class
class Character
{
private:
	char m_intrinsicState{};
public:
	Character(char intrinsicState) : m_intrinsicState{ intrinsicState }
	{}
	void draw(int extrinsicState)
	{
		std::cout << "Drawing Character '" << m_intrinsicState << "' at position " << extrinsicState << endl;
	}
};

// Flyweight Factory
class CharacterFactory
{
private:
	unordered_map<char, Character*> m_characters;
public:
	Character* getCharacter(char key)
	{
		if (m_characters.find(key) == m_characters.end())
			m_characters[key] = new Character(key);
		return m_characters[key];
	}
};

int main()
{
	CharacterFactory characterFactory;

	// Extrinsic state
	int position = 0;

	// Drawing characters 'A', 'B', 'C' at different positions
	characterFactory.getCharacter('A')->draw(position++);
	characterFactory.getCharacter('B')->draw(position++);
	characterFactory.getCharacter('C')->draw(position++);

	return 0;
}


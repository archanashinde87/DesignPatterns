#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;


/** Bullet is the base Prototype */
class Bullet
{
protected:
	string m_bulletName{};
	float m_speed{};
	float m_firePower{};
	float m_damagePower{};
	float m_direction{};

public:
	Bullet(){}
	Bullet(string bulletName, float speed, float firePower, float damagePower) 
	: m_bulletName(bulletName), m_speed(speed), m_firePower(firePower), m_damagePower(damagePower) 
	{}
	virtual ~Bullet() {}
	virtual unique_ptr<Bullet> clone() = 0;
	void fire(float direction)
	{
		m_direction = direction;

		cout << "Name        : " << m_bulletName << endl
		     << "Speed       : " << m_speed << endl
		     << "FirePower   : " << m_firePower << endl
		     << "DamagePower : " << m_damagePower << endl 
		     << "Direction   : " << m_direction << endl << endl;
	}
};

/** SimpleBullet is a Concrete Prototype */
class SimpleBullet : public Bullet
{

public:
	SimpleBullet(string bulletName, float speed, float firePower, float damagePower) :
	Bullet(bulletName, speed, firePower, damagePower)
	{
	}

	unique_ptr<Bullet> clone() override
	{
		return make_unique<SimpleBullet>(*this);
	}
};

/** GoodBullet is the Concrete Prototype */
class GoodBullet : public Bullet
{

public:
	GoodBullet(string bulletName, float speed, float firePower, float damagePower) 
	: Bullet(bulletName, speed, firePower, damagePower) 
	{
	}

	unique_ptr<Bullet> clone() override
	{
		return std::make_unique<GoodBullet>(*this);
	}
};


/** Opaque Bullet type, avoids exposing concrete implementations */
enum BulletType
{
	SIMPLE,
	GOOD
};

/** BulletFactory is the client */
class BulletFactory
{
private:
	unordered_map<BulletType, unique_ptr<Bullet>, hash<int> > m_Bullets;

public:
	BulletFactory()
	{
		m_Bullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
		m_Bullets[GOOD]   = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
	}

	unique_ptr<Bullet> createBullet(BulletType BulletType)
	{
		return m_Bullets[BulletType]->clone();
	}
};

int main()
{
	BulletFactory bulletFactory;

	auto Bullet = bulletFactory.createBullet(SIMPLE);
	Bullet->fire(90);

	Bullet = bulletFactory.createBullet(GOOD);
	Bullet->fire(100);
}
//#include<iostream>
//using namespace std;
//
//#define MIN_TANK_VOLUME 20
//#define MAX_TANK_VOLUME 120
//
//class Tank
//{
//	double fuel_level;
//	const int VOLUME;
//public:
//	const int get_VOLUME()const
//	{
//		return VOLUME;
//	}
//	double get_fuel_level()const
//	{
//		return fuel_level;
//	}
//	void fill(double amount)
//	{
//		if (amount < 0)return;
//		if (fuel_level + amount < VOLUME)fuel_level += amount;
//		else fuel_level = VOLUME;
//	}
//	double give_fuel(double amount)
//	{
//		if (amount < 0)return fuel_level;
//		fuel_level -= amount;
//		if (fuel_level < 0)fuel_level = 0;
//		return fuel_level;
//	}
//	Tank(int volume) :VOLUME
//	(
//		volume < MIN_TANK_VOLUME ? MIN_TANK_VOLUME :
//		volume > MAX_TANK_VOLUME ? MAX_TANK_VOLUME :
//		volume
//	),
//		fuel_level(0)
//	{
//		/*if (volume < MIN_TANK_VOLUME)volume = MIN_TANK_VOLUME;
//		if (volume > MAX_TANK_VOLUME)volume = MAX_TANK_VOLUME;
//		this->VOLUME = volume;*/
//		//this->fuel_level = 0;
//		cout << "Tank is ready " << this << endl;
//	}
//	~Tank() {
//		cout << "Tank is over:";
//	}
//	void info()const
//	{
//		cout << "Tank volume: " << VOLUME << " liters.\n";
//		cout << "Fuel level:  " << fuel_level << " liters.\n";
//	}
//};
//#define MIN_ENGINE_COMPSUMPTION 3
//#define MAX_ENGINE_COMPSUMPTION 30
//class Engine {
//	const double Consumption;
//	double consumptionPS;
//public:
//	double getConsomption()const {
//		return Consumption;
//	}
//	double getconsumptionPS()const {
//		return consumptionPS;
//	}
//	Engine(double consumption) :Consumption(
//		consumption< MIN_ENGINE_COMPSUMPTION ? MIN_ENGINE_COMPSUMPTION :
//		consumption > MAX_ENGINE_COMPSUMPTION ? MAX_ENGINE_COMPSUMPTION :
//		consumption) 
	//{
	//	consumptionPS = Consumption * 3e - 5;
	//	cout << "Engine is ready: " << this << endl;
	//}
//	~Engine() {
//		cout << "Engine not ready: " << this << endl;
//	}
//	void info()const
//	{
//		cout << "Consumption: " << Consumption << " Liters/100km" << endl;
//		cout << "Consumption: " << consumptionPS << " Liters/100km" << endl;
//	}
//};
//
//#define TANK_CHECK
//void main()
//{
//	setlocale(LC_ALL, "");
//#ifdef TANK_CHEK
//
//
//
//	Tank tank(85);
//	int fuel;
//	do
//	{
//		cout << "¬ведите обьем топлива: "; cin >> fuel;
//		tank.fill(fuel);
//		tank.info();
//	} while (fuel > 0);
//#endif //  TANK_CHEK
//	Engine engine(10);
//	engine.info();
//}

#include <iostream>
using namespace std;
#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 120
class Tank
{
    const int VOLUME;
    double fuel_level;
public:
    const int getVOLUME()const
    {
        return VOLUME;
    }
    double getfule_level()const
    {
        return fuel_level;
    }
    Tank(int volume) :VOLUME(volume < MIN_TANK_VOLUME ? MIN_TANK_VOLUME : (volume > MAX_TANK_VOLUME ? MAX_TANK_VOLUME : volume))
    {
        this->fuel_level = 0;
        cout << "Tank is ready\n";
    }
    void fill(double ammount)
    {
        if (ammount < 0)
        {
            return;
        }
        if (fuel_level + ammount < VOLUME)
        {
            fuel_level += ammount;
        }
        else
        {
            fuel_level = VOLUME;
        }
    }
    double give_fuel(double ammount)
    {
        if (ammount < 0)
        {
            return fuel_level;
        }
        if (fuel_level - ammount > 0)
        {
            fuel_level -= ammount;
        }
        else
        {
            fuel_level = 0;
        }
        return fuel_level;
    }
    void info()const
    {
        cout << "Tank volume: " << VOLUME << " liters\n";
        cout << "Fuel level: " << fuel_level << " liters\n";
    }
    ~Tank()
    {
        cout << "Tank is over" << endl;
    }
};
#define MIN_ENGINE_CONSUMPTION 3
#define MAX_ENGINE_CONSUMPTION 30
class Engine
{
    const double CONSUMPTION;
    double consumption_per_second;
    bool is_started;
public:
    double getConsuption()const
    {
        return CONSUMPTION;
    }
    double getConsumption_per_second()const
    {
        return consumption_per_second;
    }
    Engine(double consumption) :CONSUMPTION(consumption<MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION : consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION : consumption)
    {
        consumption_per_second = CONSUMPTION * 3e-5;
        is_started = false;
        cout << "Engine is ready: " << this << endl;
    }
    ~Engine()
    {
        cout << "Engine is over" << endl;
    }
    void start() {
        is_started = true;
    }
    void stop() {
        is_started = false;
    }
    bool started()const
    {
        return is_started;
    }
    void info()const
    {
        cout << "Engine consumption: " << CONSUMPTION << " liters\n";
        cout << "Engine consumption per second: " << consumption_per_second << " liters\n";
        cout << "Engine is " << (is_started ? "started" : "stoped") <<"\n";
    }
};
#define TANK_CHECK
void main()
{
    setlocale(LC_ALL, "");
#ifdef TANK_CHEK



    Tank tank(85);
    int fuel;
    do
    {
        cout << "¬ведите обьем топлива: "; cin >> fuel;
        tank.fill(fuel);
        tank.info();
    } while (fuel > 0);
#endif //  TANK_CHEK

    Engine engine(10);
    engine.info();
}
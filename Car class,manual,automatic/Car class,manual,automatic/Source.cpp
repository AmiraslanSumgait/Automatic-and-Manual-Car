#include <iostream>
#include <vector>
using namespace std;
class Car {
protected:
	string model;
	string color;
	int year;
	int speed;
	double weight;
public:
	Car():year(),speed(),color(),weight()
	{

	}
	Car(string model,string color, int year, int speed, double weight ):model(model),color(color),year(year),speed(speed),weight(weight)
	{

	}
	string GetModel() {
		return model;
	}
	string GetColor() {
		return color;
	}
	int GetYear() {
		return year;
	}
	int GetSpeed() {
		return speed;
	}
	double GetWeight() {
		return weight;
	}
	virtual void show() {
		cout << "Model: " << model << endl;
		cout << "Color: " << color << endl;
		cout << "Year: " << year << endl;
		cout << "Speed: " << speed << endl;
		cout << "Weight: " << weight << endl;
	
	}
};
class Manual :public Car {
protected:
	string inputShaft;
public:
	Manual():inputShaft()
	{

	}
	Manual(string model, string color, int year, int speed, double weight,string inputshaft) :Car(model, color,year,speed,weight)
	{
		this->inputShaft = inputshaft;
	}
	void show() {
		Car::show();
		cout << "Input shaft: " << inputShaft << endl;
	}
	
};
class SubaruWrx :public Manual {
private:
	string _suspension;
public:
	SubaruWrx():_suspension()
	{

	}
	SubaruWrx(string model,string color,int year,int speed,double weight,string inputshaft,string suspension ):Manual(model,color,year,speed,weight,inputshaft)
	{
		_suspension = suspension;
	}
	void show() {
		Manual::show();
		cout << "Suspension: " << _suspension << endl;
	}
};
class Automatic :public Car {
protected:
	string valveBody;
public:
	Automatic() :valveBody()
	{

	}
	Automatic(string model, string color, int year, int speed, double weight, string valvebody) :Car(model, color, year, speed, weight)
	{
		this->valveBody = valvebody;
	}
	void show() {
		Car::show();
		cout << "Valve body: " << valveBody << endl;
	}

};
class HyundaiElentra :public Automatic {
private:
	string _driverAirbag;
public:
	HyundaiElentra() :_driverAirbag()
	{

	}
	HyundaiElentra(string model, string color, int year, int speed, double weight, string valvebody, string driverairbag) :Automatic(model, color, year, speed, weight, valvebody)
	{
		_driverAirbag = driverairbag;
	}
	void show() {
		Automatic::show();
		cout << "Driver AirBag: " << _driverAirbag << endl;
	}
};
void report(Car& car) {
	car.show();
}
void main() {
	SubaruWrx s("Subaru Wrx", "blue", 2005, 280, 1200, "Control shaft", "Track-Tuned");
	//s.show();
	HyundaiElentra h("Hyundai Elentra", "white", 2007, 260, 1500, "Shuttle valve", "Center");
	//h.show();
	vector<Car*>cars;
	cars.push_back(&s);
	cars.push_back(&h);
	for (size_t i = 0; i < cars.size(); i++)
	{
		report(*cars[i]);
	}
}

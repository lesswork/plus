#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define VEG 1
#define NONVEG 2

class Rectangle
{
public:
	virtual void Draw() = 0;
};

class LinuxRectangle : public Rectangle
{
public:
	virtual void Draw(){
		cout << "Linux Draw" << endl;
	}
};

class WindowRectangle : public Rectangle
{
public:
	virtual void Draw(){
		cout << "Window Draw" << endl;
	}
};

class Factory
{
public:
	static Factory* createFactory();
	virtual Rectangle* createRectangle() = 0;
};

class LinuxFactory : public Factory
{
public:
	Rectangle* createRectangle()
	{
		return new LinuxRectangle;
	}
};

class WindowFactory : public Factory
{
public:
	Rectangle* createRectangle()
	{
		return new WindowRectangle;
	}
};

Factory* Factory::createFactory()
{
#ifdef WINDOWS
	return new WindowFactory;
#else
	return new LinuxFactory;
#endif
}

int main()
{
	Factory* pf = Factory::createFactory();

	Rectangle* pr = pf->createRectangle();
	
	pr->Draw();
	return 0;
}

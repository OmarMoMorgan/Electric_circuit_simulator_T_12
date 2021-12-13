#pragma once
#include "Component.h"
#include <sstream>

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(int id,ofstream &MyFile , const string label , int value);
	//virtual void Load(int id, ifstream& MyFile);
};

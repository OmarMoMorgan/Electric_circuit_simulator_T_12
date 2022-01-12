
#pragma once
#include "Component.h"

class Module :public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(int id, ofstream& MyFile, const string label, int value);
};

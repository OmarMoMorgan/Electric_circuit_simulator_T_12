#pragma once
#include "Component.h"
#include <sstream>

class Module :public Component
{
private:
	int R1;
	int R2;
	int R3;
	int R4;
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(int id, ofstream& MyFile, const string label, int value);
	void setValue (string Val);
	//virtual void Load(int id, ifstream& MyFile);
	
};

#pragma once
#include <iostream>
#include <fstream>
#include<string.h>
#include "action.h"
using namespace std;

//Class responsible for adding a new resistor action
class ActionLoad : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp
	//int x1, y1, x2, y2;	//Two corners of the rectangluar area

	string FileName = "test";

public:
	ActionLoad(ApplicationManager* pApp);
	virtual ~ActionLoad(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


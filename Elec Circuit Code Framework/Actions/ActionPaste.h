#pragma once

#include "action.h"
#include <string.h>
#include "..\Components\Battery.h"
#include "..\Components\Bulb.h"
#include "..\Components\Buzzer.h"
#include "..\Components\Fuse.h"
#include "..\Components\Ground.h"
#include "..\Components\Resistor.h"
#include "..\Components\Switch.h"

//Class responsible for adding a new resistor action
class ActionPaste : public Action
{
//private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int ValForCases;

public:
	ActionPaste(ApplicationManager* pApp);
	virtual ~ActionPaste(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

	
};


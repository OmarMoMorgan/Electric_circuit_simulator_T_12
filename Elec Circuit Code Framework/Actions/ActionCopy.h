#pragma once

#include "action.h"
//#include "..\Components\Battery.h"
#include <string.h>

//Class responsible for adding a new resistor action
class ActionCopy : public Action
{
//private:
	//Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp
	//int x1, y1, x2, y2;	//Two corners of the rectangluar area
	/*struct Item_data_for_copy {
		string LabelComp;
		int Compvalue;
	};*/
	//this line won't be needed rember to delete
	//Item_data_for_copy* TheCopiedData;
public:
	ActionCopy(ApplicationManager* pApp);
	virtual ~ActionCopy(void);


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


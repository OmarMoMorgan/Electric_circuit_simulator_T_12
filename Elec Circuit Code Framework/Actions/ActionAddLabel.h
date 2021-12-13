#pragma once
#include "action.h"


//Class responsible for adding a new resistor action
class ActionAddLab : public Action
{

public:
	ActionAddLab(ApplicationManager* pApp);
	virtual ~ActionAddLab(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
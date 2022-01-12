#pragma once

#include "action.h"
class ActionOnOff : public Action
{
private:

	int Cx, Cy;	// coordinates of the point clicked

public:
	ActionOnOff(ApplicationManager* pApp);
	virtual ~ActionOnOff(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
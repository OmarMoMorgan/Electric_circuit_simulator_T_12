#pragma once

#include "action.h"
class ActionAddVolt : public Action
{
private:

	int Cx, Cy;	// coordinates of the point clicked

public:
	ActionAddVolt(ApplicationManager* pApp);
	virtual ~ActionAddVolt(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
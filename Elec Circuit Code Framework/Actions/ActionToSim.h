#pragma once

#include "action.h"
class ActionToSim : public Action
{
private:

	int Cx, Cy;	// coordinates of the point clicked

public:
	ActionToSim(ApplicationManager* pApp);
	virtual ~ActionToSim(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
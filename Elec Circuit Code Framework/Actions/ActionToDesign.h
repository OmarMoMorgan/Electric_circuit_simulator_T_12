#pragma once

#include "action.h"
class ActionToDesign : public Action
{
private:

	int Cx, Cy;	// coordinates of the point clicked

public:
	ActionToDesign(ApplicationManager* pApp);
	virtual ~ActionToDesign(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


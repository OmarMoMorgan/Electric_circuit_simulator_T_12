#pragma once

#include "action.h"
class ActionCurrent : public Action
{
private:

	int Cx, Cy;	// coordinates of the point clicked

public:
	ActionCurrent(ApplicationManager* pApp);
	virtual ~ActionCurrent(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
#pragma once
#include "action.h"
#include "..\Components\Connection.h"
#include "..\UI\UI.h"

class ActionDelete : public Action {

private:
	
	int Cx,Cy, x2, y2;	// Two Points of connection
public:
	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
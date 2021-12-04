#pragma once
#include "action.h"
#include "..\Components\Connection.h"
#include "..\UI\UI.h"

class ActionConnection : public Action {

private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy, Ci, Cj;
	int x1, y1, x2, y2;	// Two Points of connection
public:
	ActionConnection(ApplicationManager* pApp);
	virtual ~ActionConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
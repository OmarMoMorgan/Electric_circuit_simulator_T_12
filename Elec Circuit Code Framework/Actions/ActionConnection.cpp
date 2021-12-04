#include "..\ApplicationManager.h"
#include "ActionConnection.h"
#include "..\Components\Connection.h"
#include "..\UI\UI.h"


ActionConnection::ActionConnection(ApplicationManager* pApp) :Action(pApp)
{
}

ActionConnection::~ActionConnection(void)
{
}

void ActionConnection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new connection : Click anywhere to add");
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	//Get Center point of the area where the Comp should be drawn








	pUI->GetPointClicked(Ci, Cj);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners


	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;

	pGInfo->PointsList[1].x = Ci + compWidth / 2;
	pGInfo->PointsList[1].y = Cj + compHeight / 2;

	Connection* pR = new Connection(pGInfo);
	pManager->AddConnection(pR);
}

void ActionConnection::Undo()
{}

void ActionConnection::Redo()
{}


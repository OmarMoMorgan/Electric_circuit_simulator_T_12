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
	pManager->SetAllFalse();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new connection: Select the first Component");


	pUI->GetPointClicked(Cx, Cy);
	pManager->ExecuteAction(SELECT);
	//pManager->Terminals_Generator();
	int* y = new int[1];
	y = pManager->getTerminalsOfTheComponent();
	pGInfo->PointsList[0].x = y[0];
	pGInfo->PointsList[0].y = y[1];

	Component* cmpt1 = pManager->get_The_Selected_Component(); // to set the first component in the connection


	pManager->SetAllFalse(); // unselect all componets

	pUI->ClearStatusBar();


	pUI->PrintMsg("Adding a new connection: Select the second Component");

	pUI->GetPointClicked(Ci, Cj);
	pManager->ExecuteAction(SELECT);
	//pManager->Terminals_Generator();
	int* z = new int[1];
	z = pManager->getTerminalsOfTheComponent();
	pGInfo->PointsList[1].x = z[0];
	pGInfo->PointsList[1].y = z[1];
	Component* cmpt2 = pManager->get_The_Selected_Component(); // Send the data of second component to connection object


	pManager->SetAllFalse();
	//Clear Status Bar
	pUI->ClearStatusBar();

<<<<<<< HEAD
	pUI->PrintMsg("Label the connection: ");
	string Label = pUI->GetSrting();
	pUI->ClearStatusBar();

	element->set_Graphics_Info(pGInfo); // To set the coordinates to the connection object
	Connection* pR = new Connection(pGInfo);
	pR->setLabel(Label);
=======
	
	
	Connection* pR = new Connection(pGInfo,cmpt1,cmpt2);
>>>>>>> ddd0b009f59b48297b4104a385b71a214efb2921
	pManager->AddConnection(pR);
}

void ActionConnection::Undo()
{}

void ActionConnection::Redo()
{}

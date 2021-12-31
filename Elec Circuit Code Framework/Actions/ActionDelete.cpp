#include "..\ApplicationManager.h"
#include "ActionDelete.h"
#include "..\Components\Connection.h"
#include "..\UI\UI.h"


ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{

}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{
	pManager->SetAllFalse();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Select the object");


	pUI->GetPointClicked(Cx, Cy);
	pManager->ExecuteAction(SELECT);
	
	pManager->Delete_Component();
	//pManager->Delete_Component();
	
	

	
	
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}

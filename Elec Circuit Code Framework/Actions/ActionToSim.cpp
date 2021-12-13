#include "ActionToSim.h"
#include "..\ApplicationManager.h"

ActionToSim::ActionToSim(ApplicationManager* pApp) :Action(pApp)
{
}

ActionToSim::~ActionToSim(void)
{
}

void ActionToSim::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();



	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	pManager->Change_AppMode(false);



}

void ActionToSim::Undo()
{}

void ActionToSim::Redo()
{}
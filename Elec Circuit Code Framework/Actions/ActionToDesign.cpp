#include "ActionToDesign.h"
#include "..\ApplicationManager.h"

ActionToDesign::ActionToDesign(ApplicationManager* pApp) :Action(pApp)
{
}

ActionToDesign::~ActionToDesign(void)
{
}

void ActionToDesign::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();



	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	pManager->Change_AppMode(true);



}

void ActionToDesign::Undo()
{}

void ActionToDesign::Redo()
{}
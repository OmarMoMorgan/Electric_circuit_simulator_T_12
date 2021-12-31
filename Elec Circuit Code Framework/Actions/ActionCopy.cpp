#include "ActionCopy.h"
#include "..\ApplicationManager.h"

ActionCopy::ActionCopy(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCopy::~ActionCopy(void)
{
}

void ActionCopy::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("select the componenet to copy");

	//Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);
	pManager->ExecuteAction(SELECT);

	

	//pManager->GetTheCopyingData();



	pUI->PrintMsg("Item copied");
	//Clear Status Bar
	pUI->ClearStatusBar();

	/*pUI->PrintMsg("Label the battery: ");
	string Label = pUI->GetSrting();
	pUI->ClearStatusBar();
	pUI->PrintMsg("enter the value: ");
	string Value = pUI->GetSrting();
	pUI->ClearStatusBar();*/
	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

}

void ActionCopy::Undo()
{}

void ActionCopy::Redo()
{}


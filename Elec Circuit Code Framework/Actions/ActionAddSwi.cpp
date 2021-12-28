#include "ActionAddSwi.h"
#include "..\ApplicationManager.h"

ActionAddSwi::ActionAddSwi(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddSwi::~ActionAddSwi(void)
{
}

void ActionAddSwi::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Switch: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	/*pUI->PrintMsg("Label the switch: ");
	string Label = pUI->GetSrting();
	pUI->ClearStatusBar();
	pUI->PrintMsg("enter the value: ");
	string Value = pUI->GetSrting();
	pUI->ClearStatusBar();*/

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Switch* pR = new Switch(pGInfo);
	/*pR->setLabel(Label);
	pR->setValue(Value);*/
	pManager->AddComponent(pR);
}

void ActionAddSwi::Undo()
{}

void ActionAddSwi::Redo()
{}


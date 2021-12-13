#include "ActionAddLabel.h"
#include "..\ApplicationManager.h"

ActionAddLab::ActionAddLab(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddLab::~ActionAddLab(void)
{
}

void ActionAddLab::Execute()
{
	pManager->SetAllFalse();
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();



	pUI->PrintMsg("Select the component: ");
	pManager->ExecuteAction(SELECT);
	pUI->ClearStatusBar();
	pUI->PrintMsg("Label the component, then enter the value: ");

	//Get Center point of the area where the Comp should be drawn

	string Label = pUI->GetSrting();

	//Clear Status Bar
	pUI->ClearStatusBar();

	pManager->get_The_Selected_Component()->setLabel(Label); //// The comp selected
	//pManager->get_The_Selected_Connection()->


	string Value = pUI->GetSrting();
	pManager->get_The_Selected_Component()->setValue(Value);
	pUI->ClearLabel(pManager->getCenterOfTheComponent()[0], pManager->getCenterOfTheComponent()[1]);

	pUI->drawtext(pManager->getCenterOfTheComponent()[0], pManager->getCenterOfTheComponent()[1] - 20, Label + ":" + Value);

	pUI->ClearStatusBar();


	pManager->SetAllFalse();



	pManager->get_The_Selected_Connection()->PointsList[0];


	pUI->drawtext(pManager->get_The_Selected_Connection()->PointsList[0].x, pManager->get_The_Selected_Connection()->PointsList[0].y - 20, Label);







}

void ActionAddLab::Undo()
{}

void ActionAddLab::Redo()
{}
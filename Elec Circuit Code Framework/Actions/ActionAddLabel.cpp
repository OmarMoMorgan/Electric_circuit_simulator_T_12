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
	pUI->PrintMsg("Select the object: ");
	


	if (pManager->get_The_Selected_Component())
	{
		pManager->ExecuteAction(SELECT);
		pUI->ClearStatusBar();
		pUI->PrintMsg("Label the component: ");
		string Label = pUI->GetSrting();
		pManager->get_The_Selected_Component()->setLabel(Label);
		pUI->ClearStatusBar();
		pUI->PrintMsg("enter the value: ");
		string Value = pUI->GetSrting();
		pManager->get_The_Selected_Component()->setValue(Value);
		pUI->ClearStatusBar();
		pUI->ClearLabel(pManager->getCenterOfTheComponent()[0], pManager->getCenterOfTheComponent()[1]);
		pUI->drawtext(pManager->getCenterOfTheComponent()[0], pManager->getCenterOfTheComponent()[1] - 20, Label + ":" + Value);
		
	}
	/*else if(pManager->get_The_Selected_Connection())
	{
		pUI->PrintMsg("Label the Connection: ");
		string Label = pUI->GetSrting();
		pManager->get_The_Selected_Connection()->setLabel(Label);
		cout << pManager->get_The_Selected_Connection()->getLabel();
	}*/
	
	pManager->SetAllFalse();



	


	//pUI->drawtext(pManager->get_The_Selected_Connection()->PointsList[0].x, pManager->get_The_Selected_Connection()->PointsList[0].y - 20, Label);







}

void ActionAddLab::Undo()
{}

void ActionAddLab::Redo()
{}
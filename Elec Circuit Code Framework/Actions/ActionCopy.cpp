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

	pManager->SetAllFalse();

	pManager->ExecuteAction(SELECT);

	Component* CompToBeCopied = pManager->get_The_Selected_Component();

	pManager->SetCopiedData(CompToBeCopied);

	pManager->CheckCompType();
	//pManager->GetTheCopyingData();



	pUI->PrintMsg("Item copied");
	//Clear Status Bar
	pUI->ClearStatusBar();

	

}

void ActionCopy::Undo()
{}

void ActionCopy::Redo()
{}


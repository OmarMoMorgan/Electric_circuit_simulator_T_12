#include "ActionCut.h"
#include "..\ApplicationManager.h"

ActionCut::ActionCut(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCut::~ActionCut(void)
{
}

void ActionCut::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("select the componenet to cut");

	pManager->SetAllFalse();

	pManager->ExecuteAction(SELECT);
	
	

	Component* CompToBeCopied = pManager->get_The_Selected_Component();

	pManager->CheckCompType();

	pManager->Delete_Component();

	pManager->SetCopiedData(CompToBeCopied);

	//pManager->GetTheCopyingData();



	pUI->PrintMsg("Item Cutted");
	//Clear Status Bar
	pUI->ClearStatusBar();



}

void ActionCut::Undo()
{}

void ActionCut::Redo()
{}


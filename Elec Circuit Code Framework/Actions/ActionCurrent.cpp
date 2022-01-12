#include "ActionCurrent.h"
#include "..\ApplicationManager.h"

ActionCurrent::ActionCurrent(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCurrent::~ActionCurrent(void)
{
}

void ActionCurrent::Execute()
{
	UI* pUI = pManager->GetUI();
	double current = pManager->Current();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Select the component ");
	pManager->ExecuteAction(SELECT);
	pUI->ClearStatusBar();
	pUI->PrintMsg("The Current is: " + to_string(current));
	pManager->SetAllFalse();
	pUI->GetSrting();
	pUI->ClearStatusBar();


}

void ActionCurrent::Undo()
{}

void ActionCurrent::Redo()
{}
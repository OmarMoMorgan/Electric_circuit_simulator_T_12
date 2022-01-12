#include "ActionOnOff.h"
#include "..\ApplicationManager.h"

ActionOnOff::ActionOnOff(ApplicationManager* pApp) :Action(pApp)
{
}

ActionOnOff::~ActionOnOff(void)
{
}

void ActionOnOff::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select the Switch");
	pManager->ExecuteAction(SELECT);
	pUI->ClearStatusBar();
	pManager->OnOff(pManager->get_The_Selected_Component());

}

void ActionOnOff::Undo()
{}

void ActionOnOff::Redo()
{}
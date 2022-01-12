#include "ActionVoltage.h"
#include "..\ApplicationManager.h"

ActionAddVolt::ActionAddVolt(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddVolt::~ActionAddVolt(void)
{
}

void ActionAddVolt::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Select the component ");
	pManager->ExecuteAction(SELECT);
	double Volt = pManager->Voltage(pManager->get_The_Selected_Component());
	pUI->ClearStatusBar();
	pUI->PrintMsg("The voltage is: " + to_string(Volt));
	pManager->SetAllFalse();
	pUI->GetSrting();
	pUI->ClearStatusBar();
}

void ActionAddVolt::Undo()
{}

void ActionAddVolt::Redo()
{}
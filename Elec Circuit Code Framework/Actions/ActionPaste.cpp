#include "ActionPaste.h"
#include "..\ApplicationManager.h"

ActionPaste::ActionPaste(ApplicationManager* pApp) :Action(pApp)
{
}

ActionPaste::~ActionPaste(void)
{
}

void ActionPaste::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Double click to paste");

	//int num;
	//1 = Battery , 2 = Bulb , 3 = Buzzer , 4 = Fuse , 5 = Ground , 6 = Resistor , 7 = Swtch  
	
	//ValForCases = pManager->CheckCompType();
	ValForCases = pManager->GetTellType();
		switch (ValForCases) {
		case 1:
			pManager->ExecuteAction(ADD_BATTERY);
			//pManager.
			break;
		case 2:
			pManager->ExecuteAction(ADD_BULB);
			break;
		case 3:
			pManager->ExecuteAction(ADD_BUZZER);
			break;
		case 4:
			pManager->ExecuteAction(ADD_FUSE);
			break;
		case 5:
			pManager->ExecuteAction(ADD_GROUND);
			break;
		case 6:
			pManager->ExecuteAction(ADD_RESISTOR);
			break;
		case 7:
			pManager->ExecuteAction(ADD_SWITCH);
			break;
		default:
			break;
		}
		if (ValForCases != 0) {
			pManager->ModifyAfterCreate();
		}
	

	//pManager->GetTheCopyingData();



	pUI->PrintMsg("Item Pasted");
	//Clear Status Bar
	pUI->ClearStatusBar();



}

void ActionPaste::Undo()
{}

void ActionPaste::Redo()
{}


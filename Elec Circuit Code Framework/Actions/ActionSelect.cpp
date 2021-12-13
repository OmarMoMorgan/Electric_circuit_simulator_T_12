#include "ActionSelect.h"
#include "..\ApplicationManager.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}

void ActionSelect::Execute()
{
	Component* list = pManager->GetListComponents();
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("omar is stupiddd");

	//Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	
	int x;
	int y;
	int flag = 0;
	pUI->GetPointClicked(x, y);
	for (int i = 0; i < pManager->GetCompCount(); i++) {
		if (pManager->GetListComponents()[i].GetGraphicsInfo() == nullptr) {
			pUI->PrintMsg("empty space clicked");
		}
		else {
			if (pManager->GetListComponents()[i].GetGraphicsInfo()->PointsList[0].x < x
				&& pManager->GetListComponents()[i].GetGraphicsInfo()->PointsList[1].x > x 
				&& pManager->GetListComponents()[i].GetGraphicsInfo()->PointsList[0].y < y
				&& pManager->GetListComponents()[i].GetGraphicsInfo()->PointsList[1].y > y) {
				pManager->GetListComponents()[i].SetSelection(true);
				pManager->GetListComponents()[i].Draw(pUI);
				pUI->PrintMsg("the condition is working");
				flag = 1;
				break;
			}
		}
	}
	/*if (flag == 0) {
		for (int i = 0; i < pManager->GetCompCount(); i++) {
			pManager->GetListComponents()[i].SetSelection(false);
			pManager->GetListComponents()[i].Draw(pUI);

			pUI->PrintMsg("the empty space is working");
		}*/
	//}
	

	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	/*int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();*/

	/*pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;*/

	//Battery* pR = new Battery(pGInfo);
	//pManager->AddComponent(pR);
}

void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}


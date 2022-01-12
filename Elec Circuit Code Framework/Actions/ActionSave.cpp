#include "ActionSave.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <fstream>
using namespace std;

ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSave::~ActionSave(void)
{
}

void ActionSave::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("saving file");

	string FileNAme = pUI->GetSrting();

	ofstream MyFile(FileNAme);

	pManager->Save(MyFile);

	pUI->PrintMsg("file saved");
	/*for (int i = 0; i < pManager->GetCompCount(); i++) {
		pManager->GetListComponents()[i]->Save(int id, ofstream & MyFile, const string label, int value);
	}*/

	//Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pUI->ClearStatusBar();


	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	////Calculate the rectangle Corners
	//int compWidth = pUI->getCompWidth();
	//int compHeight = pUI->getCompHeight();

	//pGInfo->PointsList[0].x = Cx - compWidth / 2;
	//pGInfo->PointsList[0].y = Cy - compHeight / 2;
	//pGInfo->PointsList[1].x = Cx + compWidth / 2;
	//pGInfo->PointsList[1].y = Cy + compHeight / 2;

	//Battery* pR = new Battery(pGInfo);
	//pManager->AddComponent(pR);
}

void ActionSave::Undo()
{}

void ActionSave::Redo()
{}


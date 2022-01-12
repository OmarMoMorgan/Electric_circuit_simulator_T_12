#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <fstream>

using namespace std;

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}

void ActionLoad::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Loading file ");
	
	int numComp = 0;
	string f;
	string Comptype;
	int id;
	string label;
	int value;
	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	string FileNAme = pUI->GetSrting();

	ifstream MyFile(FileNAme);
	if (!MyFile) {
		pUI->PrintMsg("error couldn't open file");
		
	}
	else {
		//getline(cin, f) >> numComp;
		pManager->Load(MyFile);
		
		
	}

	pUI->PrintMsg("loaded ");

	
	/*for (int i = 0; i < pManager->GetCompCount(); i++) {
		pManager->GetListComponents()[i]->Save(int id, ofstream & MyFile, const string label, int value);
	}*/

	//Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pUI->ClearStatusBar();


	

	

	//Battery* pR = new Battery(pGInfo);
	//pManager->AddComponent(pR);
}

void ActionLoad::Undo()
{}

void ActionLoad::Redo()
{}


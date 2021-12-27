#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBat.h"
#include "Actions\ActionAddSwi.h"
#include "Actions\ActionAddBulb.h"
#include"Actions\ActionAddGRD.h"
#include "Actions\ActionConnection.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionExit.h"
#include "Actions\ActionLoad.h"
#include "Actions/ActionToSim.h"
#include "Actions/ActionToDesign.h"
#include "Actions/ActionAddLabel.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	// for adding connections
	ConnectionCount = 0;

	for (int i = 0; i < MaxConnectionCount; i++)
		ConnectionList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddConnection(Connection* pConnection)
{
	ConnectionList[ConnectionCount++] = pConnection;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	
	int flag = 0;
	
	int flag_1 = 0;
	int flag_2 = 0;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGRD(this);
			break;

		case ADD_BATTERY:
			pAct = new ActionAddBat(this);
			break;

		case ADD_BULB:
			pAct = new ActionAddBulb(this);
			break;


		case ADD_SWITCH:
			pAct = new ActionAddSwi(this);
			break;

		case SELECT:
			pUI->GetPointClicked(x, y);

			for (int i = 0; i < ConnectionCount; i++) {
				if (ConnectionList[i]->Get_The_Data()->PointsList[1].x > ConnectionList[i]->Get_The_Data()->PointsList[0].x) {
					if (ConnectionList[i]->Get_The_Data()->PointsList[1].x >= x && x >= ConnectionList[i]->Get_The_Data()->PointsList[0].x) {
						flag_1 = 1;
					}
					else {
						if (ConnectionList[i]->Get_The_Data()->PointsList[0].x >= x && x >= ConnectionList[i]->Get_The_Data()->PointsList[1].x) {
							flag_1 = 1;
						}
					}


				}
				if (ConnectionList[i]->Get_The_Data()->PointsList[1].y > ConnectionList[i]->Get_The_Data()->PointsList[0].y) {
					if (ConnectionList[i]->Get_The_Data()->PointsList[1].y >= y && y >= ConnectionList[i]->Get_The_Data()->PointsList[0].y) {
						flag_2 = 1;
					}
					else {
						if (ConnectionList[i]->Get_The_Data()->PointsList[0].y >= y && y >= ConnectionList[i]->Get_The_Data()->PointsList[1].y) {
							flag_2 = 1;
						}
					}


				}


				//cout << ConnectionList[i]->Get_The_Data()->PointsList[1].x<< " " << ConnectionList[i]->Get_The_Data()->PointsList[1].y << endl;cout << ConnectionList[i]->Get_The_Data()->PointsList[0].x<< " " << ConnectionList[i]->Get_The_Data()->PointsList[0].y << endl;
				if (flag_1 == 1 && flag_2 == 1) {

					ConnectionList[i]->Set_Selection(true);
					ConnectionList[i]->Draw(pUI);
					pUI->PrintMsg("The Connection is selected");

				}



			}
			for (int i = 0; i < CompCount; i++) {
				if (CompList[i]->GetGraphicsInfo() == nullptr) {

					pUI->PrintMsg("empty space clicked");
				}
				else {
					if (CompList[i]->GetGraphicsInfo()->PointsList[0].x  < x
						&& CompList[i]->GetGraphicsInfo()->PointsList[1].x > x && CompList[i]->GetGraphicsInfo()->PointsList[0].y < y
						&& CompList[i]->GetGraphicsInfo()->PointsList[1].y > y) {



						CompList[i]->SetSelection(true);
						CompList[i]->Draw(pUI);
						pUI->PrintMsg("the condition is working");
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				for (int i = 0; i < CompCount; i++) {
					CompList[i]->SetSelection(false);
					CompList[i]->Draw(pUI);

					pUI->PrintMsg("the empty space is working");
				}
			}
			break;

		case ADD_CONNECTION:
			pAct = new ActionConnection(this);
			//TODO: Create AddConection Action here
			break;

		case SIM_MODE:
			pAct = new ActionToSim(this);
			break;
		case DSN_MODE:
			pAct = new ActionToDesign(this);
			break;
		case ADD_Label:
			pAct = new ActionAddLab(this);
			break;
	
		case SAVE:
			pAct = new ActionSave(this);
			break;

		/*case LOAD:
			pAct = new ActionLoad(this);
			break;*/

		case EXIT:
			///TODO: create ExitAction here
			//pAct = new ActionExit(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////
int* ApplicationManager::getTerminalsOfTheComponent() {
	int* Co = new int[1];

	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelection() == true) {
			if (x > (CompList[i]->GetGraphicsInfo()->PointsList[0].x + pUI->getCompWidth() / 2)) {
				Co[0] = CompList[i]->GetGraphicsInfo()->PointsList[0].x + pUI->getCompWidth();
				Co[1] = CompList[i]->GetGraphicsInfo()->PointsList[0].y + pUI->getCompHeight() / 2;
			}
			else {
				Co[0] = CompList[i]->GetGraphicsInfo()->PointsList[0].x;
				Co[1] = CompList[i]->GetGraphicsInfo()->PointsList[0].y + pUI->getCompHeight() / 2;
			}

		}
	}

	return Co;
}


void ApplicationManager::SetAllFalse() {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelection(false);
		CompList[i]->Draw(pUI);
	}
}
Component* ApplicationManager::get_The_Selected_Component() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelection() == true) {
			return CompList[i];
		}
	}
}
GraphicsInfo* ApplicationManager::get_The_Selected_Connection() {
	for (int i = 0; i < ConnectionCount; i++) {
		if (ConnectionList[i]->Get_Selection() == true) {
			return ConnectionList[i]->Get_The_Data();
		}
	}
}

void ApplicationManager::UpdateInterface()
{

		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);

		for (int i = 0; i < ConnectionCount; i++)
			ConnectionList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	// for deleting connections
	//for (int i = 0; i < ConnectionCount; i++)
	//	delete ConnectionList[i];
	//delete pUI;

	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}
/////////////////////////////////////////////////////////////////////
void ApplicationManager::Save(ofstream &MYFile) {
	MYFile << CompCount << "\n";
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Save(i+1,MYFile , "omar", 1);
		MYFile << "\n";
	}
}
/////////////////////////////////////////////////////////////////////
//void ApplicationManager::Load(ifstream& MYFile) {
//	int Thecompnum = 0;
//	Component* temp;
//	string itemtype;
//	MYFile >> Thecompnum;
//	for (int i = 0; i < Thecompnum; i++) {
//		MYFile >> itemtype;
//		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
//		if (itemtype == "BAT") {
//			Battery* pR = new Battery(pGInfo);
//			AddComponent(pR);
//			pR->Load(i, MYFile);
//		}else if(itemtype == "BUL"){
//			Battery* pR = new Battery(pGInfo);
//			AddComponent(pR);
//			pR->Load(i, MYFile);
//		}
//		else if (itemtype == "SWI") {
//			Battery* pR = new Battery(pGInfo);
//			AddComponent(pR);
//			pR->Load(i, MYFile);
//		}
//		else if (itemtype == "RES") {
//			Battery* pR = new Battery(pGInfo);
//			AddComponent(pR);
//			pR->Load(i, MYFile);
//		}
//		else if (itemtype == "GRO") {
//			Battery* pR = new Battery(pGInfo);
//			AddComponent(pR);
//			pR->Load(i, MYFile);
//		}
//	}
//}
/////////////////////////////////////////////////////////////////////
void ApplicationManager::Exit() {	
	for (int i = 0; i < CompCount; i++) {
		delete CompList[i];
	}
}
/////////////////////////////////////////////////////////////////////
int* ApplicationManager::getCenterOfTheComponent() {
	int* Co = new int[2];
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelection() == true) {
			Co[0] = CompList[i]->GetGraphicsInfo()->PointsList[0].x;
			Co[1] = CompList[i]->GetGraphicsInfo()->PointsList[0].y;
		}
	}

	return Co;
}


void ApplicationManager::Change_AppMode(bool x) {
	pUI->DO(x);

}
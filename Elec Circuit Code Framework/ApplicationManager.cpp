#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBat.h"
#include "Actions\ActionAddSwi.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddGRD.h"
#include "Actions\ActionConnection.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionExit.h"
#include "Actions\ActionLoad.h"
#include "Actions/ActionToSim.h"
#include "Actions/ActionToDesign.h"
#include "Actions/ActionAddLabel.h"

#include "Actions/ActionDelete.h"
#include "Actions/ActionADDMOD.h"

#include "Actions/ActionAddBuzzer.h"
#include "Actions/ActionAddFuse.h"


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

	//pointer to the data fro copying item this is also under test yet
	//Item_data_for_copy* TheCopiedData = new Item_data_for_copy();
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
	//this is for testing purposes
	GraphicsInfo* pGInfo = new GraphicsInfo(2);
	//end of the tesets here

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

		case ADD_BUZZER:
			pAct = new ActionAddBuzzer(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFuse(this);
			break;

		case ADD_SWITCH:
			pAct = new ActionAddSwi(this);
			break;

		case SELECT:
			pUI->GetPointClicked(x, y);

			for (int i = 0; i < ConnectionCount; i++) {
				if (ConnectionList[i]->terminals_getter()[2] > ConnectionList[i]->terminals_getter()[0]) {
					if (ConnectionList[i]->terminals_getter()[2] >= x && x >= ConnectionList[i]->terminals_getter()[0]) {
						flag_1 = 1;
					}
					else {
						if (ConnectionList[i]->terminals_getter()[0] >= x && x >= ConnectionList[i]->terminals_getter()[2]) {
							flag_1 = 1;
						}
					}


				}
				if (ConnectionList[i]->terminals_getter()[3] > ConnectionList[i]->Get_The_Data()->PointsList[0].y) {
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
		case DEL:
			pAct = new ActionDelete(this);
		/*case LOAD:
			pAct = new ActionLoad(this);
			break;*/

		//this is not the final thing this is crently being tested
		case COPY:
			
			/*for (int j = 0; j < CompCount; j++) {
				if (CompList[j]->GetSelection() == true) {
					Battery* pR = new Battery(&(*CompList[j]) , pGInfo);
				}
			}*/
			break;
		case ADD_MODULE:
			pAct = new ActionADDMOD(this);
			break;
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
	int* Co = new int[2];

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
	for (int i = 0; i < ConnectionCount; i++) {
		ConnectionList[i]->Set_Selection(false);
		ConnectionList[i]->Draw(pUI);
	}
}
Component* ApplicationManager::get_The_Selected_Component() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelection() == true) {
			return CompList[i];
		}
	}
}

void ApplicationManager::Delete_selected() {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelection() == true) {
			 CompList[i] = nullptr;
		}
	}
}


Connection* ApplicationManager::get_The_Selected_Connection() {

	for (int i = 0; i < ConnectionCount; i++) {
		if (ConnectionList[i]->Get_Selection() == true) {
			return ConnectionList[i];
		}
	}
}

void ApplicationManager::UpdateInterface()
{

	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			CompList[i]->Draw(pUI);
		}
		
	}
			

	for (int i = 0; i < ConnectionCount; i++) {
		if (ConnectionList[i] != nullptr)
			ConnectionList[i]->Draw(pUI);
	}
			

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
void ApplicationManager::Delete_Component() {
	/*int* t = new int[4];
	t[0] = getCenterOfTheComponent()[0];
	t[1] = getCenterOfTheComponent()[1];
	t[2] = getCenterOfTheComponent()[2];
	t[3] = getCenterOfTheComponent()[3];*/
	//get_The_Selected_Component()->GetGraphicsInfo() = nullptr;
	//get_The_Selected_Component();
	Delete_selected();
	Update_CompList();

	//UpdateInterface();
	//pUI->DrawWhite_component(t);
	
	
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
		if(CompList[i] != nullptr)
			delete CompList[i];
	}
	for (int i = 0; i < ConnectionCount; i++) {
		if (ConnectionList[i] != nullptr)
			delete ConnectionList[i];
	}
}
/////////////////////////////////////////////////////////////////////
int* ApplicationManager::getCenterOfTheComponent() {
	int* Co = new int[4];
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelection() == true) {
			Co[0] = CompList[i]->GetGraphicsInfo()->PointsList[0].x;
			Co[1] = CompList[i]->GetGraphicsInfo()->PointsList[0].y;
			Co[2] = CompList[i]->GetGraphicsInfo()->PointsList[1].x;
			Co[3] = CompList[i]->GetGraphicsInfo()->PointsList[1].y;
		}
	}

	return Co;
}


void ApplicationManager::Change_AppMode(bool x) {
	pUI->DO(x);

}




bool ApplicationManager::Validation() {
	int count = 0;
	int num_of_validtion = 0;
	for (int i = 0; i < CompCount; i++) {
		const Ground* ptrG = dynamic_cast<const Ground*>(CompList[i]);
		if (ptrG != nullptr)
			count++;
		if (CompList[i] != nullptr) {
			int  flag_1 = 0, flag_2 = 0;
			int* Co = new int[2];
			Co[0] = CompList[i]->GetGraphicsInfo()->PointsList[0].x + pUI->getCompWidth();
			
			Co[1] = CompList[i]->GetGraphicsInfo()->PointsList[0].x;

			// There is the heck of randomness

			//let's work on the first terminal
			for (int i = 0; i < ConnectionCount; i++) {

				if (ConnectionList[i]->terminals_getter()[0] == Co[0]) {
					flag_1 += 1;
					cout << "Flag1 is " << flag_1 << endl;
					ConnectionList[i]->Set_Selection(true);
				}

			}
			if (flag_1 == 0) {
				for (int i = 0; i < ConnectionCount; i++) {

					if (ConnectionList[i]->terminals_getter()[2] == Co[0]) {
						flag_1 += 1;
						cout << "Flag1 is " << flag_1 << endl;
						ConnectionList[i]->Set_Selection(true);
					}
				}


			}

			//--------------------------------------------

			//Let's work on the second Terminal



			for (int i = 0; i < ConnectionCount; i++) {
				if (ConnectionList[i]->terminals_getter()[0] == Co[1]) {
					flag_2 += 1;
					cout << "Flag2 is " << flag_2 << endl;
					ConnectionList[i]->Set_Selection(true);

				}
			}
			if (flag_2 == 0) {
				for (int i = 0; i < ConnectionCount; i++) {
					if (ConnectionList[i]->terminals_getter()[2] == Co[1]) {
						flag_2 += 1;
						cout << "Flag2 is " << flag_2 << endl;
						ConnectionList[i]->Set_Selection(true);
					}
				}
			}


			if (flag_1 == 0 || flag_2 == 0) {
				pUI->PrintMsg("This Component is not fully connected");
				CompList[i]->SetSelection(true);

				//pUI->GetSrting();
				return false;
			}                    
			// there is a bit of randomness


			if (flag_1 == 1 && flag_2 == 1)
				num_of_validtion++;

			if (flag_1 > 1 || flag_2 > 1) {
				pUI->PrintMsg("This Component has multiple connections. ");
				CompList[i]->SetSelection(true);
				return false;
			}

				

		}
	}
	if (num_of_validtion == CompCount && count == 1)
		return true;
	
		
	if(count == 0) {
		pUI->PrintMsg("There is no Ground in the circuit. ");
		return false;
	}
	if (count > 1) {
		pUI->PrintMsg("There is more than one Ground in the circuit. ");
		return false;
	}
		
		

	

}
void ApplicationManager::Update_CompList() {
	Component* NewList[200];
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != nullptr) {
			
			NewList[i] = CompList[i];
			NewList[i]->SetGraphicsInfo(CompList[i]->GetGraphicsInfo()) ;
		}	
	}
	/*for (int i = 0; i < CompCount; i++) {
		CompList[i] = nullptr;
		delete CompList[i];

	}*/
	
	for (int i = 0; i < CompCount; i++) {
		CompList[i] = NewList[i];
		CompList[i]->SetGraphicsInfo(NewList[i]->GetGraphicsInfo());
	}

	/*for (int i = 0; i < CompCount; i++) {
		NewList[i] = nullptr;
		delete NewList[i];

	}
	delete[] NewList;*/

	

}

//double ApplicationManager::Current()
//{
//	double resistor = 0;
//	double voltage = 0;
//	for (int i = 0; i < CompCount; i++) {
//		const Resistor* ptrR = dynamic_cast<const Resistor*>(CompList[i]);
//		const Bulb* ptrB = dynamic_cast<const Bulb*>(CompList[i]);
//		const Buzzer* ptrZ = dynamic_cast<const Buzzer*>(CompList[i]);
//		const Battery* ptrBAT = dynamic_cast<const Battery*>(CompList[i]);
//		if (ptrR || ptrB || ptrZ)
//			resistor += double(CompList[i]->getvalue());
//		if (ptrBAT)
//			voltage += double(CompList[i]->getvalue());
//	}
//	return (voltage / resistor);
//}

bool ApplicationManager::SelectFuntion() {
	if (80 < y && y < 600) {
		return true;
	}
	else {
		return false;
	}
		
		
	
}



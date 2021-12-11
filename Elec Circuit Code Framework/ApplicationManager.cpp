#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBat.h"
#include "Actions\ActionAddSwi.h"
#include "Actions\ActionAddBulb.h"
#include"Actions\ActionAddGRD.h"
#include "Actions\ActionConnection.h"


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
	int x = 0;
	int y = 0;
	int flag = 0;
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
			for (int i = 0; i < CompCount; i++) {
				if (CompList[i]->GetGraphicsInfo() == nullptr) {
					pUI->PrintMsg("empty space clicked");
				}
				else {
					if (CompList[i]->GetGraphicsInfo()->PointsList[0].x < x
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
	

		case EXIT:
			///TODO: create ExitAction here
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
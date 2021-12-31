#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\ActionConnection.h"
#include "Actions\ActionSelect.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	
	enum { MaxConnectionCount = 300 }; //Max no of connections
private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	int ConnectionCount;
	Connection* ConnectionList[MaxConnectionCount];

	UI* pUI; //pointer to the UI
	int x, y;

	//these are the data neeeded to copy the componenet
	
	

public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();

	//Getter function for the list of all components
	Component* GetListComponents() { return *CompList; }

	//Getter function for the list of all components
	int GetCompCount() { return CompCount; }
	
	void SetAllFalse();

	Component* get_The_Selected_Component();
	Connection* get_The_Selected_Connection();
	int* getTerminalsOfTheComponent();
	int* getCenterOfTheComponent();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void AddConnection(Connection* pConnection);
	//destructor
	~ApplicationManager();

	void Save(ofstream &MYFile);
	//void Load(ifstream& MYFile);
	void Exit();
	
	
	void Change_AppMode(bool x);
	void SelectFuntion();
	//Item_data_for_copy* GetTheCopyingData() { return TheCopiedData; }
};

#endif
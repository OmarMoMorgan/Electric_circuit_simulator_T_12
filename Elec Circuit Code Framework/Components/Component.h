#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "Connection.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label;
	
	
protected:
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2

	//Each terminal is connected to set of connections
	Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection *term2_connections[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;


	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component

	bool selected_o = false;
	double value;

public:
	Component(GraphicsInfo *r_GfxInfo);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2
	
	virtual void Operate() = 0;	//Calculates the output voltage according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	
	//To get the graphics info 
	GraphicsInfo *GetGraphicsInfo();
	void SetGraphicsInfo(GraphicsInfo* x);
	//virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	//virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	//virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	//getter for the boolean that says is it selected or not
	bool GetSelection() {
		return selected_o;
	}

	//the save function
	virtual void Save(int id, ofstream& MyFile, const string label, int value) = 0;

	//the Load function
	//virtual void Load(int id, ifstream& MyFile) = 0;

	//ITM_Data *AHMEDSAIDSO;

	void SetSelection(bool next) {
		 selected_o = next;
	}

	void setLabel(string text);
	string getLabel();
	void setValue(string v);
	double getvalue();
	Component();	
	
	
	//Destructor must be virtual
	virtual ~Component();

	//test for a new copy constructor to see if that will fix stuff or not
	Component(const Component& , GraphicsInfo* r_GfxInfo);
};

#endif

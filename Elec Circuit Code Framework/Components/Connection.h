#pragma once
#include "../UI/UI.h"

class Component;	//forward class declaration

class Connection 
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
protected:
	bool selected_connection = false;
	string m_label;
public:
	Connection(GraphicsInfo *r_GfxInfo, Component *cmp1=nullptr, Component *cmp2=nullptr);

	virtual void Draw(UI* );	//for connection to Draw itself
	void set_First_Component(Component* pComp);
	void set_Second_Component(Component* pComp);
	Component* Get_First_Component();
	Component* Get_Second_Component();
	GraphicsInfo* Get_The_Data();
	void set_Graphics_Info(GraphicsInfo* pGfxInfo);
	void Set_Selection(bool y);
	bool Get_Selection();
	void setLabel(string text);
	string getLabel();



	int* terminals_getter();

};

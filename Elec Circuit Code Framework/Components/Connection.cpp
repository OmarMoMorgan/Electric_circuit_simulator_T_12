#include "Connection.h"

Connection::Connection(GraphicsInfo *r_GfxInfo, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, selected_connection);
}
void Connection::set_First_Component(Component* pComp) {
	this->Cmpnt1;

}
void Connection::set_Second_Component(Component* pComp) {
	this->Cmpnt2;
}
void Connection::set_Graphics_Info(GraphicsInfo* x) {
	this->pGfxInfo;
}
Component* Connection::Get_First_Component() {
	return Cmpnt1;
}
Component* Connection::Get_Second_Component() {
	return Cmpnt2;
}
GraphicsInfo* Connection::Get_The_Data() {
	return pGfxInfo;
}

void Connection::Set_Selection(bool y) {
	selected_connection = y;
}
bool Connection::Get_Selection() {
	return selected_connection;
}
void Connection::setLabel(string text)
{
	this->m_label;
}
string Connection::getLabel()
{
	return m_label;
}
int* Connection::terminals_getter() {
	int* Co = new int[4];
	Co[0] = pGfxInfo->PointsList[0].x;
	Co[1] = pGfxInfo->PointsList[0].y;
	Co[2] = pGfxInfo->PointsList[1].x;
	Co[3] = pGfxInfo->PointsList[1].y;

	return Co;



}

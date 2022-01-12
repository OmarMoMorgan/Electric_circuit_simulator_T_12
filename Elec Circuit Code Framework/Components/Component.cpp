#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}

GraphicsInfo* Component::GetGraphicsInfo() {
	return m_pGfxInfo;
}

Component::~Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	delete m_pGfxInfo;

}
void Component::setLabel(string text)
{
	this->m_Label = text;
}
string Component::getLabel()
{
	return m_Label;
}
//value
void Component::setValue(string v) //omar edited this make it like this for class modulle
{
	this->value = std::stod(v); //omar edited this make it like this for class modulle
}
double Component::getvalue()
{
	return value;
}

//the implemantion of the copy constructor
Component::Component(const Component& old_comp , GraphicsInfo* r_GfxInfo) {
	m_Label = this->m_Label;
	value = this->value;

	term1_volt = this->term1_volt;
	term2_volt = this->term2_volt;
	Connection* term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection* term2_connections[MAX_CONNS];
	term1_conn_count = 0;
	term2_conn_count = 0;
	m_pGfxInfo = r_GfxInfo;
	selected_o = this->selected_o;

}


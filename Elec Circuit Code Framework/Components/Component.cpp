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
{}
void Component::setLabel(string text)
{
	this->m_Label = text;
}
string Component::getLabel()
{
	return m_Label;
}
//value
void Component::setValue(string v)
{
	this->value = v;
}
string Component::getvalue()
{
	return value;
}


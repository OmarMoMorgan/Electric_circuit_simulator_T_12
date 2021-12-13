#include "Battery.h"

Battery::Battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo , selected_o); //update to draw battery

}

void Battery::Operate()
{

}

void Battery::Save(int id , ofstream &MyFile , const string label , int value) {
	MyFile.width(15);
	MyFile << "BAT" << "\t" << id << "\t" << label << "\t" << value << "\t" << m_pGfxInfo;
}
#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo):Component(r_GfxInfo)
{}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo , selected_o); //update to draw resistor

}

void Switch::Operate()
{

}

void Switch::Save(int id, ofstream& MyFile, const string label, int value) {
	MyFile.width(15);
	MyFile << "SWI" << "\t" << id << "\t" << label << "\t" << value << "\t" << m_pGfxInfo;
}
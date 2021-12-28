#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo, selected_o); //update to draw Buzzer

}

void Buzzer::Operate()
{

}

void Buzzer::Save(int id, ofstream& MyFile, const string label, int value) {
	MyFile.width(15);
	MyFile << "BUZ" << "\t" << id << "\t" << label << "\t" << value << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y;
}
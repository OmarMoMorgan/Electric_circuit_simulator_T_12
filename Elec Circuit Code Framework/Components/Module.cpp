#include "Module.h"

Module::Module(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Module::Draw(UI* pUI)
{
	//Call output class and pass MOD drawing info to it.
	pUI->DrawMOD(*m_pGfxInfo, selected_o); //update to draw mod

}

void Module::Operate()
{


}

void Module::Save(int id, ofstream& MyFile, const string label, int value) {
	MyFile.width(15);
	MyFile << "MOD" << "\t" << id << "\t" << label << "\t" << value << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y;
}
#include "Fuse.h"

Fuse::Fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, selected_o); //update to draw fuse

}

void Fuse::Operate()
{

}

void Fuse::Save(int id, ofstream& MyFile, const string label, int value) {
	MyFile.width(15);
	MyFile << "FUS" << "\t" << id << "\t" << label << "\t" << value << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y;
}
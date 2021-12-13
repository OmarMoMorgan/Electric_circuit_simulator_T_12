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
	MyFile << "BAT" << "\t" << id << "\t" << label << "\t" << value << "\t" << m_pGfxInfo->PointsList[0].x << "\t" << m_pGfxInfo->PointsList[0].y;
}

//void Battery::Load(int id, ifstream& MyFile){
//	//MyFile >> Thecompnum;
//	string dummy;
//	string dum_lab;
//	int value;
//	for (int i = 0; i < 6; i++) {
//		getline(MyFile, dummy ," ");
//		getline(MyFile, id, " ");
//		getline(MyFile, label, " ");
//		getline(MyFile, value, " ");
//		getline(MyFile, m_pGfxInfo->PointsList[0].x, " ");
//		getline(MyFile, m_pGfxInfo->PointsList[0].y, " ");
//	}
//	//MyFile >> dummy >> id >> label >> value >> m_pGfxInfo->PointsList[0].x >> m_pGfxInfo->PointsList[0].y;
//	//m_pGfxInfo->PointsList[1].x + ;
//	//m_pGfxInfo->PointsList[0].y
//}

// the Code is supposed to be true but we have e
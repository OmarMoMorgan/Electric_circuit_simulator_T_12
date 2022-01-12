#include "Module.h"
#include <algorithm>

Module::Module(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Module::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo, selected_o); //update to draw battery

}

void Module::Operate()
{

}

void Module::Save(int id, ofstream& MyFile, const string label, int value) {
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

void Module::setValue(string Val) {
	//char temp1[5];
	//int count = std::count(s.begin(), s.end(), ch);
	try {
		string temp1, temp2, temp3, temp4;
		getline(cin, Val , ' ') >> temp1 >> temp2 >> temp3 >> temp4;
		getline(cin, temp2, ' ') >> temp2;
		getline(cin, temp3, ' ') >> temp3;
		getline(cin, temp4, ' ') >> temp4;
		double R1 = std::stod(temp1);
		double R2 = std::stod(temp2);
		double R3 = std::stod(temp3);
		double R4 = std::stod(temp4);
		value = 1 / (1 / (R1 + R2) + 1 / (R3 + R4));
		
	}
	catch (...) {
		
	}
}
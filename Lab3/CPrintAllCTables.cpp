#include "Utilities.h"
#include "CPrintAllCTables.h"
#include <iostream>
using namespace std;

const string HELP = "Wypisanie wszystkich CTable";

CPrintAllCTables::CPrintAllCTables(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
	s_help = HELP;
}// CPrintAllCTables::CPrintAllCTables(vector<CTable*>* pvObjects)

void CPrintAllCTables::vRunCommand()
{
	vPrintObjectsInfo(*pv_objects);
}// void CPrintAllCTables::vRunCommand()


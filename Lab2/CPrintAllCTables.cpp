#include "Utilities.h"
#include "CPrintAllCTables.h"
#include <iostream>
using namespace std;

CPrintAllCTables::CPrintAllCTables(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
}// CPrintAllCTables::CPrintAllCTables(vector<CTable*>* pvObjects)

void CPrintAllCTables::vRunCommand()
{
	vPrintInfo(*pv_objects);

}// void CPrintAllCTables::vRunCommand()


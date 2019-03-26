#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CPrintAllCTables : public CCommand
{
private:
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CPrintAllCTables(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CPrintAllCTables : public CCommand

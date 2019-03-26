#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
#include <string>
using namespace std;

class CCreateCTable : public CCommand
{
private:
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CCreateCTable(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CCreateCTable : public CCommand

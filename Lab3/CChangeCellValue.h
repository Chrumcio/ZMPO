#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CChangeCellValue : public CCommand
{
private:
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CChangeCellValue(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CChangeCellValue : public CCommand

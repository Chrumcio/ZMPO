#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CChangeTableLength : public CCommand
{
private:
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CChangeTableLength(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CChangeTableLength : public CCommand

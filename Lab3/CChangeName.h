#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CChangeName : public CCommand
{
private:
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CChangeName(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CChangeName : public CCommand

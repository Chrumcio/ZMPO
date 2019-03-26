#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CDeleteAll : public CCommand
{
private:
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CDeleteAll(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CDeleteAll : public CCommand

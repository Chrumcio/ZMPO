#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CCreateCTable : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CCreateCTable(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CCreateCTable : public CCommand
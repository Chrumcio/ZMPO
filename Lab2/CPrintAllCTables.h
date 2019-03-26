#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CPrintAllCTables : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CPrintAllCTables(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CPrintAllCTables : public CCommand
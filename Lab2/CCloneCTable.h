#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CCloneCTable : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CCloneCTable(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CCloneCTable : public CCommand
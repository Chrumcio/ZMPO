#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CDeleteCTable : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CDeleteCTable(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CDeleteCTable : public CCommand
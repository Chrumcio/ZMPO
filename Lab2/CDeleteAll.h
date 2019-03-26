#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CDeleteAll : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CDeleteAll(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CDeleteAll : public CCommand
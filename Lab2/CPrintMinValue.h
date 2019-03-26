#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CPrintMinValue : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CPrintMinValue(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CPrintMinValue : public CCommand

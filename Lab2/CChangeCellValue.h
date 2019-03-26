#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CChangeCellValue : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CChangeCellValue(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CChangeCellValue : public CCommand
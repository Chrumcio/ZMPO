#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CChangeTableLength : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CChangeTableLength(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CChangeTableLength : public CCommand
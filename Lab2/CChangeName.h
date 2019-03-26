#pragma once
#include "CCommand.h"
#include "CTable.h"
#include <vector>
using namespace std;

class CChangeName : public CCommand
{
private:
	vector <CTable*> *pv_objects;
public:
	CChangeName(vector <CTable*> *pvObjects);
	virtual void vRunCommand();
};// class CChangeName : public CCommand
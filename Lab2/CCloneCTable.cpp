#include "Utilities.h"
#include "CCloneCTable.h"
#include <iostream>
#include <stdlib.h>
#include "CVariables.h"

using namespace std;

const string S_CHOOSE_ELEMENT="Wybierz element";

CCloneCTable::CCloneCTable(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
}// CCloneCTable::CCloneCTable(vector<CTable*>* pvObjects)

void CCloneCTable::vRunCommand()
{
	vPrintInfo(*pv_objects);
	cout << S_CHOOSE_ELEMENT;
	string s_element;
	getline(cin, s_element);
	if (bIsInt(s_element))
	{
		int i_element = atoi(s_element.c_str());
		if (i_element > 0 && i_element <= pv_objects->size())
		{
			pv_objects->push_back(new CTable(*(*pv_objects)[i_element - 1]));
		}// if (i_element > 0 && i_element <= v_objects.size())
		else vPrintMissingElement();
	}// if (bIsInt(s_element))
	else vPrintWrong();

}// void CCloneCTable::vRunCommand()


#include "CDeleteCTable.h"
#include "Utilities.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

const string CHOOSE_ELEMENT = "Wybierz element: ";
const string HELP = "Usuwanie CTable";

CDeleteCTable::CDeleteCTable(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
	s_help = HELP;
}// CDeleteCTable::CDeleteCTable(vector<CTable*>* pvObjects)

void CDeleteCTable::vRunCommand()
{
	vPrintObjectsInfo(*pv_objects);
	cout << CHOOSE_ELEMENT;
	string s_element;
	getline(cin, s_element);
	if (bIsInt(s_element))
	{
		int i_element = atoi(s_element.c_str());
		if (i_element > 0 && i_element <= pv_objects->size())
		{
			delete (*pv_objects)[(i_element - 1)];
			pv_objects->erase(pv_objects->begin() + (i_element - 1));
		}// if (i_element > 0 && i_element <= v_objects.size())
		else vPrintMissingElement();
	}// if (bIsInt(s_element))
	else vPrintWrongNumber();

}// void CDeleteCTable::vRunCommand()


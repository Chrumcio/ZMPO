#include "Utilities.h"
#include "CChangeName.h"
#include <iostream>
#include <stdlib.h>
#include "CVariables.h"

using namespace std;

const string S_CHOOSE_ELEMENT="Wybierz element: ";
const string S_ENTER_NAME="Wprowadz nazwe: ";

CChangeName::CChangeName(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
}// CChangeName::CChangeName(vector<CTable*>* pvObjects)

void CChangeName::vRunCommand()
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
			cout << S_ENTER_NAME;
			string s_new_name;
			cin >> s_new_name;
			(*pv_objects)[i_element - 1]->vSetName(s_new_name);
		}// if (i_element > 0 && i_element <= v_objects.size())
		else vPrintMissingElement();
	}// if (bIsInt(s_element))
	else vPrintWrong();

}// void CChangeName::vRunCommand()


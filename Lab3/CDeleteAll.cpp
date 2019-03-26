#include "CDeleteAll.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

const string HELP = "Usuniecie wszystkich elementow CTable";

CDeleteAll::CDeleteAll(vector<CTable*>* pvObjects)
{
	this->pv_objects = pvObjects;
	s_help = HELP;
}// CDeleteAll::CDeleteAll(vector<CTable*>* pvObjects)

void CDeleteAll::vRunCommand()
{
	for (int i = 0; i < pv_objects->size(); i++)
	{
		delete (*pv_objects)[i];
	}// for (int i = 0; i < pv_objects->size(); i++)
	pv_objects->clear();
}// void CDeleteAll::vRunCommand()


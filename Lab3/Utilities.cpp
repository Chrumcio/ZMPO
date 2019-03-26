#include "Utilities.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include <iostream>
#include <vector>
#include <string>

const string WRONG_NUMBER = "Zla liczba";
const string WRONG_ELEMENT = "Zly element";

void vPrintWrongNumber()
{
	cout << WRONG_NUMBER << endl;
}// void vPrintWrongNumber()

void vPrintMissingElement()
{
	cout << WRONG_ELEMENT << endl;
}// void vPrintMissingElement()

void vPrintObjectsInfo(vector <CTable*> vObjects)
{
	for (int i = 0; i < vObjects.size(); i++) {
		cout << i + 1 << ". ";
		cout << vObjects[i]->sGetInfo() << endl;
	}// for (int i = 0; i < objects.size(); i++) {
}// void vPrintObjectsInfo(vector <CTable*> objects)

bool bIsInt(string sInput)
{
	for (int i = 0; i < sInput.length(); i++)
	{
		char c_char = sInput[i];
		if (c_char < '0' || c_char > '9') return false;
	}
	return true;
}// bool bIsInt(string sInput)

void deleteCTables(vector<CTable*> vObjects)
{
	for (int i = 0; i < vObjects.size(); i++)
	{
		delete vObjects[i];
	}// 	for (int i = 0; i < objects.size(); i++)
}// void deleteCTables(vector<CTable*> objects)



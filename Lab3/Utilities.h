#pragma once
#include <vector>
#include "CTable.h"
#include "CMenu.h"

void vPrintWrongNumber();
void vPrintMissingElement();
void vPrintObjectsInfo(vector <CTable*> vObjects);
bool bIsInt(string sInput);
void deleteCTables(vector<CTable*> vObjects);
string sMenuToString(CMenu *pcMenu);
CMenu* cMenuFromString(string sMenuString);
bool bIsValidStringToMenu(string sMenuString);




#include "CBack.h"
#include "CMenu.h"
#include <iostream>
#include <vector>
#include "CTable.h"
#include "Utilities.h"
#include "CVariables.h"

const string S_BACK="Cofnij";

CBack::CBack()
{
	pc_parent = NULL;
	s_help = S_BACK;
}// CBack::CBack()

CBack::CBack(CMenu *pcParent)
{
	pc_parent = pcParent;
	s_help = S_BACK;
}// CBack::CBack(CMenu *pcParent)

CBack::CBack(CMenu *pcParent, CMenu *pcFinalMenu, vector<CTable*> *pvObjects)
{
	this->pc_parent = pcParent;
	this->pc_finalMenu = pcFinalMenu;
	this->pv_objects = pvObjects;
	s_help = S_BACK;
}// CBack::CBack(CMenu *pcParent, CMenu *pcFinalMenu, vector<CTable*> *pvObjects)

void CBack::vRunCommand()
{
	if (pc_parent != NULL)
	{
		pc_parent->bRun();
	}// if (pc_parent != NULL)
	else
	{
		deleteCTables(*pv_objects);
		delete pc_finalMenu;
	}// else
}// void CBack::vRunCommand()


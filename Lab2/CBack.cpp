#include "CBack.h"
#include "CMenu.h"
#include <iostream>
#include <vector>
#include "CTable.h"
#include "Utilities.h"


CBack::CBack()
{
	pc_parent = NULL;
	s_help = "Cofnij";
}// CBack::CBack()

CBack::CBack(CMenu *pcParent)
{
	pc_parent = pcParent;
}// CBack::CBack(CMenu *pcParent)

CBack::CBack(CMenu *pcParent, CMenu *pcFinalMenu, vector<CTable*> *pvObjects)
{
	pc_parent = pcParent;
	pc_finalMenu = pcFinalMenu;
	pv_objects = pvObjects;
}// CBack::CBack(CMenu *pcParent, CMenu *pcFinalMenu, vector<CTable*> *pvObjects)

void CBack::vRunCommand()
{
	if (pc_parent != NULL)
	{
		pc_parent->vRun();
	}// if (pc_parent != NULL)
	else
	{
		vDeleteCTables(*pv_objects);
		delete pc_finalMenu;
	}// else
}// void CBack::vRunCommand()


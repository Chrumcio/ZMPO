#include "CBack.h"
#include "CMenu.h"
#include <iostream>
#include <vector>
#include "CTable.h"
#include "Utilities.h"


CExit::CExit()
{
	pc_parent = NULL;
}// CBack::CBack()

CExit::CExit(CMenu *pcParent)
{
	pc_parent = pcParent;
}// CBack::CBack(CMenu *pcParent)

CExit::CExit(CMenu *pcParent, CMenu *pcFinalMenu, vector<CTable*> *pvObjects)
{
	pc_parent = pcParent;
	pc_finalMenu = pcFinalMenu;
	pv_objects = pvObjects;
}// CBack::CBack(CMenu *pcParent, CMenu *pcFinalMenu, vector<CTable*> *pvObjects)

void CBack::vRunCommand()
{
	// if (pc_parent != NULL)
		vDeleteCTables(*pv_objects);
		delete pc_finalMenu;
		break;
	// else
}// void CBack::vRunCommand()


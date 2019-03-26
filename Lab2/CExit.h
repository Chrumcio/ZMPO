#pragma once
#include "CCommand.h"
#include "CMenu.h"
#include "CTable.h"
#include<vector>

class CExit :public CCommand
{
private:
	CMenu *pc_parent;
	CMenu *pc_finalMenu;
	vector <CTable*> *pv_objects;
public:
	//CExit();
	CExit(CMenu*parent);
	CExit(CMenu*parent, CMenu*finalMenu, vector <CTable*> *objects);
	void vRunCommand();
};// class CBack :public CCommand

#pragma once
#include "CCommand.h"
#include "CMenu.h"
#include "CTable.h"
#include<vector>

class CBack :public CCommand
{
private:
	CMenu *pc_parent;
	CMenu *pc_finalMenu;
	vector <CTable*> *pv_objects;
	string s_help;
public:
	CBack();
	CBack(CMenu*parent);
	CBack(CMenu*parent, CMenu*finalMenu, vector <CTable*> *objects);
	void vRunCommand();
	virtual string sGetHelp() { return s_help; }
};// class CBack :public CCommand

#pragma once
#include "CMenuItem.h"
#include <string>
#include <vector>
using namespace std;

class CMenu : public CMenuItem
{
private:
	CMenu* c_menu_parent;
	vector <CMenuItem*> v_c_menu_items;
	vector <CMenu*> v_c_menu;

public:
	CMenu();
	CMenu(string sName, string sCommand);
	~CMenu();
	virtual void vRun();
	virtual string sGetName();
	virtual string sGetCommand();
	virtual string sHelp(){return NULL;}
	CMenu* cAddSubmenu(string sName, string sCommand);
	void vPrintCommands();
	void vAddToVector(CMenuItem *pcItem);
};

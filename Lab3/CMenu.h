#pragma once
#include "CMenuItem.h"
#include <string>
#include <vector>
using namespace std;

class CMenu : public CMenuItem
{
private:
	vector <CMenuItem*> v_c_menu_items;
    string s_menu_string=string();
public:
	CMenu();
	CMenu(string sName, string sCommand);
	~CMenu();
	virtual bool bRun();
	virtual void vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd);
	virtual string sGetName();
	virtual string sGetCommand();
	CMenu* vAddSubmenu(string sName, string sCommand);
	void vPrintCommands();
	void vAddToVector(CMenuItem *pcItem);
	virtual string sGetHelp() { return std::string(); }
	string sMenuToString(CMenu *pcMenu);
	string sAddBracket(string s_menu);
    CMenu* cMenuFromString(string sMenuString);

};

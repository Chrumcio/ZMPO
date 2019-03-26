#pragma once
#include <string>
#include <vector>
using namespace std;

class CMenuItem
{
protected:
	string s_command;
	string s_name;
	CMenuItem* c_parent;
public:
	virtual bool bRun() = 0;
	virtual string sGetName() = 0;
	virtual string sGetCommand() = 0;
	virtual string sGetHelp() = 0;
	virtual void vSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd) = 0;
	virtual void vStartSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd);
	virtual string sGetPath();
    void vSetParent(CMenuItem *pcParent) { c_parent = pcParent; }
    CMenuItem* cGetParent() { return c_parent; }
};

#include "CMenuItem.h"
const string S_ARROW="->";

void CMenuItem::vStartSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd)
{
	if (c_parent != NULL)
    {
		c_parent->vStartSearch(pcFoundItems, sSearchCmd);
	}
	else
	{
		vSearch(pcFoundItems, sSearchCmd);
	}
} // void CMenuItem::vStartSearch(vector<CMenuItem*>& pcFoundItems, string sSearchCmd)

string CMenuItem::sGetPath()
{
	string s_path;
	if(c_parent != NULL)
	{
		s_path = c_parent->sGetPath() + S_ARROW;
	}
	s_path += s_command;
	return s_path;
} // string CMenuItem::sGetPath()

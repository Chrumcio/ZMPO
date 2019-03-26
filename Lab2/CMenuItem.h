#pragma once
#include <string>
using namespace std;

class CMenuItem
{
protected:
	string s_command;
	string s_name;

public:
    virtual ~CMenuItem(){};
	virtual void vRun() = 0;
	virtual string sGetName() = 0;
	virtual string sGetCommand() = 0;
	virtual string sHelp() = 0;
};

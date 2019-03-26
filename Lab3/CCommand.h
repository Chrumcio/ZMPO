#pragma once
#include <string>
using namespace std;

class CCommand
{
public:
	virtual void vRunCommand() = 0;
	virtual string sGetHelp() = 0;
};// class CCommand

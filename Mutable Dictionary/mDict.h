#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <conio.h>
using namespace std;
class mDict
{
public:
	vector<string> key;
	vector<string> value;
	string m_key,m_value;
	static int count;
	mDict(void);
	~mDict(void);
	
	void    mDict_CreateDict(string, string);

	mDict*  mDict_DisplayandCreateAsObjects();
	string  mDict_DictConvertAsString(mDict*);
	string* mDict_DictKeyArray(mDict*);
	string* mDict_DictKeyofValueArray(mDict*);
	string* mDict_DictKeyandValueArrayWithPostion(mDict*);
	mDict*  mDict_DeleteKeyandValue(string,mDict*);
	mDict*  mDict_DeleteKeyandvalueAtPosition(int,mDict*);

	string  mDict_GetValueofKey(string,mDict*);
	string  mDict_GetKeyandValueUsingPosition(int,mDict*);

	mDict*  mDict_InsertKeyandValue(string, string, mDict*);
	mDict*  mDict_InsertKeyandValueAtPosition(string,string,int,mDict*);

	mDict*  mDict_UpdateKeyandValueAtPosition(string,string,int,mDict*);
	mDict*  mDict_UpdateValueofKeyUsingPosition(string,int,mDict*);
};

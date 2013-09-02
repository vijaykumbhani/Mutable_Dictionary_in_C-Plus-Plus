#include "StdAfx.h"
#include "mDict.h"


mDict::mDict(void)
{
}

mDict::~mDict(void)
{
}

int mDict :: count = 0;

void mDict :: mDict_CreateDict(string dKey,string dValue)
{
	key.push_back(dKey);
	value.push_back(dValue);
}

mDict* mDict :: mDict_DisplayandCreateAsObjects()
{
	mDict objects;
	mDict *obj = NULL;// = new mDict[key.size()];
	obj = new mDict[key.size()];
	int len = key.size();
	for(int i = 0; i < len; i++)
	{
		objects.m_key = key[i];
		objects.m_value = value[i];
		obj[i] = objects;
		mDict::count++;
	} 
	return obj;
}

string mDict :: mDict_DictConvertAsString(mDict* objects)
{
	string result;
	try
	{
		if(objects == NULL)
			throw 1;
		result += "{ ";
		for(int i=0; i<mDict::count; i++)
		{
			string key = objects[i].m_key;
			string value = objects[i].m_value;
			result +=  "\"" +  key + "\" : \" " + value + "\" ";
			if(i == count-1)
			{
				result += "";
			}
			else
			{
				result += ", ";
			}
		}
		result += "}";
		return result;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

mDict* mDict :: mDict_InsertKeyandValueAtPosition(string dKey, string dValue, int position, mDict* objects)
{
	try
	{
		if (mDict::count <= position)
			throw 1;
		if (objects == NULL)
			throw 2;
		mDict *obj = NULL;// = new mDict[key.size()];
		obj = new mDict[mDict::count + 1];
		int length = mDict::count+1;
		for (int i=0; i<length; i++)
		{
			if(i == position)
			{
				mDict temp;
				temp.m_key = dKey;
				temp.m_value = dValue;
				obj[i] = temp;
				mDict::count++;
				continue;
			}
			if(i > position)
			{
				obj[i] = objects[i-1];
			}
			else
			{
				obj[i] = objects[i];
			}
		}
		return obj;
	}
	catch (int i)
	{
		if(i == 1)
		{
			cout<<"\n \t Error : Your Position is not Suitable With Dictionary Length"<<endl;
		}
		if(i == 2)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
		}
		_getch();
		exit(1);
	}
}

string* mDict :: mDict_DictKeyArray(mDict* objects)
{
	try
	{
		if(objects == NULL)
			throw 1;
		string *listKey = NULL;
		listKey = new string[mDict::count];
		for (int i=0; i<mDict::count; i++)
		{
			listKey[i] = objects[i].m_key;
		}
		return listKey;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

string* mDict :: mDict_DictKeyofValueArray(mDict* objects)
{
	try
	{
		if(objects == NULL)
			throw 1;
		string *listValue = NULL;
		listValue = new string[mDict::count];
		for (int i=0; i<mDict::count; i++)
		{
			listValue[i] = objects[i].m_value;
		}
		return listValue;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

string* mDict :: mDict_DictKeyandValueArrayWithPostion(mDict* objects)
{
	try
	{
		if(objects == NULL)
			throw 1;
		string *listKeyandValue = NULL;
		listKeyandValue = new string[mDict::count];
		for (int i=0; i<mDict::count; i++)
		{
			string data;
			stringstream num;
			num << i;
			data = num.str();
			data += " @ \"" + objects[i].m_key + "\"  : \"" + objects[i].m_value +"\"" ;
			listKeyandValue[i] = data;
		}
		return listKeyandValue;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

mDict* mDict :: mDict_UpdateKeyandValueAtPosition(string dKey,string dValue,int position, mDict* objects)
{
	try
	{
		if (mDict::count <= position)
			throw 1;
		if (objects == NULL)
			throw 2;
		mDict *obj = NULL;// = new mDict[key.size()];
		obj = new mDict[mDict::count];
		for(int i=0; i<mDict::count; i++)
		{
			if(i == position)
			{
				mDict temp;
				temp.m_key = dKey;
				temp.m_value = dValue;
				obj[i] = temp;
			}
			else
			{
				obj[i] = objects[i];
			}
		}
		return obj;
	}
	catch (int i)
	{
		if(i == 1)
		{
			cout<<"\n \t Error : Your Position is not Suitable With Dictionary Length"<<endl;
		}
		if(i == 2)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
		}
		_getch();
		exit(1);
	}
}

mDict* mDict :: mDict_DeleteKeyandvalueAtPosition(int position, mDict* objects)
{
	try
	{
		if (mDict::count <= position)
			throw 1;
		if (objects == NULL)
			throw 2;
		mDict *obj = NULL;// = new mDict[key.size()];
		obj = new mDict[mDict::count - 1];
		for(int i=0; i<mDict::count; i++)
		{
			if(i == position)
			{	
				continue;
			}
			if(i > position)
			{
				obj[i-1] = objects[i];
				if(i == count-1)
				{
					mDict::count--;
					break;
				}
			}
			else
			{
				obj[i] = objects[i];
			}
		}
		return obj;
	}
	catch (int i)
	{
		if(i == 1)
		{
			cout<<"\n \t Error : Your Position is not Suitable With Dictionary Length"<<endl;
		}
		if(i == 2)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
		}
		_getch();
		exit(1);
	}
}

string mDict :: mDict_GetValueofKey(string dkey,mDict *objects)
{
	try
	{
		if(objects == NULL)
			throw 1;
		string dValue;
		for(int i=0; i<mDict::count; i++)
		{
			if(dkey == objects[i].m_key)
			{
				dValue = objects[i].m_value;
				break;
			}
		}
		return dValue;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

mDict* mDict :: mDict_InsertKeyandValue(string dKey, string dValue, mDict* objects)
{
	try
	{
		if(objects == NULL)
			throw 1;
		mDict *obj = NULL;// = new mDict[key.size()];
		int len = mDict::count+1;
		obj = new mDict[len];
		for(int i=0; i<len; i++)
		{
			if(i == len-1)
			{
				mDict temp;
				temp.m_key = dKey;
				temp.m_value = dValue;
				obj[i] = temp;
				mDict::count++;
			}
			else
			{
				obj[i] = objects[i];
			}
		}
		return obj;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

mDict* mDict :: mDict_DeleteKeyandValue(string dKey, mDict* objects)
{
	try
	{
		if(objects == NULL)
			throw 1;
		mDict *obj = NULL;// = new mDict[key.size()];
		int len = mDict::count-1;
		obj = new mDict[len];
		for(int i=0; i<mDict::count; i++)
		{
			if(i == len)
			{
				mDict::count--;
			}
			else
			{
				obj[i] = objects[i];
			}
		}
		return obj;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
			_getch();
			exit(0);
		}
	}
}

mDict* mDict :: mDict_UpdateValueofKeyUsingPosition(string dValue,int position, mDict* objects)
{
	try
	{
		if (mDict::count <= position)
			throw 1;
		if (objects == NULL)
			throw 2;
		mDict *obj = NULL;// = new mDict[key.size()];
		int len = mDict::count;
		obj = new mDict[len];
		for(int i=0; i<len; i++)
		{
			if(i == position)
			{
				mDict temp;
				temp.m_key = objects[i].m_key;
				temp.m_value = dValue;
				obj[i] = temp;
			}
			else
			{
				obj[i] = objects[i];
			}
		}
		return obj;
	}
	catch (int i)
	{
		if(i == 1)
		{
			cout<<"\n \t Error : Your Position is not Suitable With Dictionary Length"<<endl;
		}
		if(i == 2)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
		}
		_getch();
		exit(1);
	}
}

string mDict :: mDict_GetKeyandValueUsingPosition(int position, mDict* objects)
{
	try
	{
		if (mDict::count <= position)
			throw 1;
		if (objects == NULL)
			throw 2;
		string keyandvalue;
		for(int i=0; i< mDict::count; i++)
		{
			if(position == i)
			{
				keyandvalue += "\" " + objects[i].m_key + " \" : ";
				keyandvalue += "\" " + objects[i].m_value + " \"";
				break;
			}
		}
		return keyandvalue;
	}
	catch(int i)
	{
		if(i == 1)
		{
			cout<<"\n \t Error : Your Position is not Suitable With Dictionary Length"<<endl;
		}
		if(i == 2)
		{
			cout<<"\n \t can not use Empty Objects"<<endl;
		}
		_getch();
		exit(1);
	}
}
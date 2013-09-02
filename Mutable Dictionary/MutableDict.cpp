
/**************** Developed by : Vijay Kumbhani *******************
  *************** Email : vnkumbhani@gmail.com ********************
  *** Any Query this Library Please contact above Email address ***
  *** given detail to read carefully after use this library *******
  ********** Rules:										***********
  ********** 1. First to read below examples carefully ************
  ********** 2. first to add key and value in dictionary **********
  **********    to use function is one time then to use ***********
  **********    for loop to add multiple key and their values *****
  ********** 3. After all key and value added in dictionary *******
  **********    then first create objects after to use all function 
  **********    (all function rules read completed after) *********
  ********** 4. all position start With Zero (same as array) ******/

#include "stdafx.h"
#include "mDict.h"
#include <conio.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int size;
	string key,value;
	mDict mdict,*mict;
	cout<<"welcome to dictionary:"<<endl;
	cout<<"Enter the Size of dictionary (enter numeric value only ) "<<endl;
	cin>>size;
	cin.ignore(1,'\n');
	for(int i=0; i<size ;i++)
	{
		cout<<"Enter the Key of Dictionary:"<<endl;
		getline(cin,key);
		cout<<"Enter the value of key in Dictionary:"<<endl;
		getline(cin,value);
		// create Dict and add value to dictionary
		// parameter : first key and second Value of key
		// retun type = no 
		// this function is no return type 
		mdict.mDict_CreateDict(key,value);
	}

	// create mutable dict objects 
	// parameter = no
	// return type = mDict pointer objects 
	mict = mdict.mDict_DisplayandCreateAsObjects();

	// display whole dictionary as string 
	// parameter = pass mDict pointer objects
	// return type =  string 
	string wholeResult = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult<<endl;

	// length of dictionary to use static variable count
	int len = mDict::count;
	cout<<"length of dictionary "<<len;

	// display of key array  
	// parameter = pass mDict pointer objects
	// return type =  pointer of string  
	string *allKey = mdict.mDict_DictKeyArray(mict);
	for(int i = 0 ; i<mDict::count; i++)
	{
		cout<< "Key is : \n"<<allKey[i]<<endl;
	}

	// display value of Key array
	// parameter = pass mDict pointer objects
	// return type =  pointer of string   
	string *allValue = mdict.mDict_DictKeyofValueArray(mict);
	for(int i = 0 ; i<mDict::count; i++)
	{
		cout<< "Key is : \n"<<allValue[i]<<endl;
	}

	// display key and value array
	// parameter = pass mDict pointer objects
	// return type =  pointer of string  
	string *KeyandValue = mdict.mDict_DictKeyandValueArrayWithPostion(mict); 
	for(int i = 0 ; i<mDict::count; i++)
	{
		cout<< "Key is : \n"<<KeyandValue[i]<<endl;
	}

	// display Value of entered key 
	// parameter =  string and mDict pointer objects 
	// return type =  string  
	string keyValue = mdict.mDict_GetValueofKey("name",mict);
	cout<<"value of key is :"<<keyValue<<endl;


	// display Value of entered key 
	// parameter =  string and mDict pointer objects 
	// return type =  string  
	string keyandvalue = mdict.mDict_GetKeyandValueUsingPosition(1,mict);
	cout<<keyandvalue<<endl;

	// display Value of entered key 
	// parameter =  key , value and mDict pointer objects 
	// return type =   mDict pointer objects   
	// to display dict , to use this return objects to pass as parameter " mDict_DictConvertAsString "
	mict = mdict.mDict_InsertKeyandValue("city","surat",mict);
	string wholeResult1 = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult1<<endl;

	// insert key and value at specific position because this is mutable dictionary
	// parameter =  key , value , position and mDict pointer objects 
	// return type =   mDict pointer objects   
	// to display dict , to use this return objects to pass as parameter " mDict_DictConvertAsString "
	mict = mdict.mDict_InsertKeyandValueAtPosition("country","India",1,mict);
	string wholeResult2 = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult2<<endl;

	// delete key and value 
	// parameter =  key and mDict pointer objects 
	// return type =   mDict pointer objects
	// to display dict , to use this return objects to pass as parameter " mDict_DictConvertAsString "
	mict = mdict.mDict_DeleteKeyandValue("city",mict);
	string wholeResult3 = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult3<<endl;

	// delete key and value at specific position
	// parameter =  Enter position and mDict pointer objects 
	// return type =   mDict pointer objects
	// to display dict , to use this return objects to pass as parameter " mDict_DictConvertAsString "
	mict = mdict.mDict_DeleteKeyandvalueAtPosition(1,mict);
	string wholeResult4 = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult4<<endl;

	// update key and value at specific position
	// parameter =  key, value , position and mDict pointer objects 
	// return type =   mDict pointer objects
	// to display dict , to use this return objects to pass as parameter " mDict_DictConvertAsString "
	mict = mdict.mDict_UpdateKeyandValueAtPosition("city","hyderabad",1,mict);
	string wholeResult5 = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult5<<endl;

	// update value of key at specific position
	// parameter =  value of key, position and mDict pointer objects 
	// return type =   mDict pointer objects
	// to display dict , to use this return objects to pass as parameter " mDict_DictConvertAsString "
	mict = mdict.mDict_UpdateValueofKeyUsingPosition("surat",1,mict);
	string wholeResult6 = mdict.mDict_DictConvertAsString(mict);
	cout<<wholeResult6<<endl;

	_getch();
	return 0;
}


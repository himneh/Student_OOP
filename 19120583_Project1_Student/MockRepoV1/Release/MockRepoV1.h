#pragma once
#include <vector>
#include <string>
#include <time.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <codecvt>
#include "OopLib.h"

#pragma warning(disable : 4996)

using namespace std;

class Tokenizer {
public:
	static vector<wstring> split(wstring haystack, wstring  needle);
};

class MobileNetwork {
private:
	wstring _name;
	vector<wstring> _prefixes;
public:
	wstring name();
	vector<wstring> prefixes();
	MobileNetwork();
	MobileNetwork(wstring s, vector<wstring> num);
};

class Telephone {
private:
	MobileNetwork _network;
	wstring _prefixes;
	wstring _numbers;
public:
	MobileNetwork network();
	wstring number();
	wstring toString();
	Telephone(MobileNetwork M, wstring s1, wstring s2);
};

class TelephoneMock {
private:
	vector<MobileNetwork> _supportedNetworks;
	Random _rng;
public:
	TelephoneMock();
	Telephone next();
};

class Fullname {
private:
	wstring _firstName;
	wstring _middleName;
	wstring _lastName;
public:
	wstring Getfirstname();
	wstring Getmiddlename();
	wstring Getlastname();
	wstring toString();
	Fullname(wstring first, wstring middle, wstring last);
};

class FullnameMock {
private:
	Random _rng;
	vector<wstring> _femaleMiddleName;
	vector<wstring> _femaleLastName;
	vector<wstring> _maleMiddleName;
	vector<wstring> _maleLastName;
	vector<wstring> _firstName;
public:
	Fullname next(bool male);
	FullnameMock();
};

class EmailMock {
private:
	Random _rng;
	vector<wstring> _domains;
	FullnameMock _nameStore;
public:
	wstring next();
	EmailMock();

	void fixing(wchar_t& k);
	wstring next(Fullname name);
};

class Address {
private: 
	wstring _number;
	wstring _street;
	wstring _ward;
	wstring _district;
	wstring _city;
public:
	wstring getNumber();
	wstring getStreet();
	wstring getWard();
	wstring getDistrict();
	wstring getCity();

	void setNumber(wstring value);
	void setStreet(wstring value);
	void setWard(wstring value);
	void setDistrict(wstring value);
	void setCity(wstring value);

	wstring toString();
	Address(wstring number, wstring street, wstring ward, wstring district, wstring city);
};

class HcmAddressMock {
private:
	Random _rng;
	vector<wstring> _streets;
	vector<wstring> _wards;
	vector<wstring> _districts;
	vector<wstring> _cities;
public:
	HcmAddressMock();
	Address next();
};
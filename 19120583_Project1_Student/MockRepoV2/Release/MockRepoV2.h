#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <codecvt>
#include "OopLib.h"

#pragma warning(disable : 4996)
using namespace std;

class DateTime {
private:
	int _day;
	int _month;
	int _year;
public:
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	wstring toString();
	DateTime(int, int, int);

	static int currentYear();
	static bool isLapYear(int);
};

class BirthDayMock{
private:
	Random _rng;
	int _maxAge;
	int _currentYear;
public:
	int getMaxage();
	int getCurrentYear();

	void setMaxage(int);
	void setCurrentYear(int);

	BirthDayMock();
	DateTime next();
};

class CitizenIdMock {
private:
	Random _rng;
	vector<wstring> _cityCodes;
	vector<wstring> _cities;
	int _maxAge;
	int _currentYear;
public:
	CitizenIdMock();
	wstring next();
	wstring lookupCity(wstring);
};

class StudentIDMock {
private:
	Random _rng;
	vector<wstring> _facultyCodes;
	vector<int> _courseCodes;
	int _currentYear;
	int _maxCourse;
public:
	StudentIDMock();
	wstring next();
};
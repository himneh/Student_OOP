#pragma once

#include "MockRepoV2.h"
#include "MockRepoV1.h"

class Student {
private:
	Random _rng;
	wstring _studentID;
	wstring _studentName;
	wstring _citizenID;
	wstring _telephone;
	wstring _email;
	wstring _address;
	wstring _dob;
public:
	wstring getID();
	wstring getName();
	wstring getcitizenID();
	wstring getTelephone();
	wstring getEmail();
	wstring getAddress();
	wstring getDob();

	Student();

	Student(wstring, wstring, wstring, wstring, wstring, wstring, wstring);

	friend wostream& operator<<(wostream& out, const Student& student); 

};
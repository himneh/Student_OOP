#include "SupeLib.h"

wstring Student::getID() {
	return _studentID;
}

wstring Student::getName() {
	return _studentName;
}

wstring Student::getcitizenID() {
	return _citizenID;
}

wstring Student::getTelephone() {
	return _telephone;
}

wstring Student::getEmail() {
	return _email;
}

wstring Student::getAddress() {
	return _address;
}

wstring Student::getDob() {
	return _dob;
}

Student::Student(wstring ID, wstring name, wstring citizenID, wstring telephone, wstring email, wstring address, wstring dob) {
	_studentID = ID;
	_studentName = name;
	_citizenID = citizenID;
	_telephone = telephone;
	_email = email;
	_address = address;
	_dob = dob;
}

Student::Student() {
	Random _rng;

	StudentIDMock studentIdStore;
	_studentID = studentIdStore.next();

	bool male = true;
	int tmp = _rng.next(0,1);
	if (tmp == 1) male = true;
	else male = false;
	FullnameMock nameStore;

	Fullname names = nameStore.next(male);
	_studentName = names.toString();

	CitizenIdMock citizenIDStore;
	_citizenID = citizenIDStore.next();

	TelephoneMock telStore;
	Telephone tel = telStore.next();
	_telephone = tel.toString();

	EmailMock emailStore;
	_email = emailStore.next(names);

	HcmAddressMock addressStore;
	Address address = addressStore.next();
	_address = address.toString();

	BirthDayMock birthdayStore;
	DateTime dob = birthdayStore.next();
	_dob = dob.toString();

	//Student student(studentID, name, citizenID, telephone, email, add, birthday);
	//return student;
}

wostream& operator<<(wostream& out, const Student& student) {
	out << student._studentID << L" | ";
	out << student._studentName << L" | ";
	out << student._email << L" | ";
	out << student._citizenID << L" | ";
	out << student._telephone << L" | ";
	out << student._address << L" | ";
	out << student._dob << "\n";
	return out;
}
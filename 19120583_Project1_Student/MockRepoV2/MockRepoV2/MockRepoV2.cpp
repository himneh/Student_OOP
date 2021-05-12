#include "MockRepoV2.h"

int DateTime::getDay() {
	return _day;
}

int DateTime::getMonth() {
	return _month;
}

int DateTime::getYear() {
	return _year;
}

void DateTime::setDay(int value) {
	_day = value;
}

void DateTime::setMonth(int value) {
	_month = value;
}

void DateTime::setYear(int value) {
	_year = value;
}

wstring DateTime::toString() {
	wstring result = L"";
	wstringstream builder;

	builder << DateTime::getDay() << L"/" << DateTime::getMonth() << L"/" << DateTime::getYear();
	result = builder.str();
	return result;
}

DateTime::DateTime(int d, int m, int y) {
	DateTime::setDay(d);
	DateTime::setMonth(m);
	DateTime::setYear(y);
}

int DateTime::currentYear() {
	time_t t = time(NULL);
	tm now;
	localtime_s(&now, &t);
	return now.tm_year + 1900;
}

bool DateTime::isLapYear(int k) {
	if (k % 100 == 0 && k % 400 == 0) return true;
	else return false;
}

int BirthDayMock::getCurrentYear() {
	return _currentYear;
}

int BirthDayMock::getMaxage() {
	return _maxAge;
}

void BirthDayMock::setCurrentYear(int value) {
	_currentYear = value;
}

void BirthDayMock::setMaxage(int value) {
	_maxAge = value;
}

BirthDayMock::BirthDayMock() {
	BirthDayMock::setMaxage(120);
	BirthDayMock::setCurrentYear(DateTime::currentYear());
}

DateTime BirthDayMock::next() {
	int year = getCurrentYear() - _rng.next(getMaxage());
	int month = _rng.next(1, 12);
	int days[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (DateTime::isLapYear(year)) days[2] = 29;

	int day = _rng.next(days[month]);

	DateTime dob(day,month,year);
	return dob;
}

CitizenIdMock::CitizenIdMock() {

	int k = 63 * 2;
	wifstream reader("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV2/MockRepoV2/CityCodes.txt");
	reader.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));

	wstring buffer;
	if (!reader.is_open()) cout << "Failed!";
	else {
		for (int i = 0; i < k; i++) {
			getline(reader, buffer);
			if (i % 2 != 0) {
				_cityCodes.push_back(buffer);
			}
			else {
				_cities.push_back(buffer);
			}
		}
		
		reader.close();
	}
	//_cityCodes = { "001","002","003","055","068","079","096","049","051","010" };
	_maxAge = 120;

	_currentYear = DateTime::currentYear();
}

wstring CitizenIdMock::lookupCity(wstring s) {
	int i = 0;
	while (i < 126) {
		if (_cityCodes[i] == s) break;
		i++;
	}
	return _cities[i];
}

wstring CitizenIdMock::next() {
	wstringstream writer;

	//Ma TP
	int i = _rng.next(_cityCodes.size());
	wstring cityCode = _cityCodes[i];

	//Ma the ky
	int century = _currentYear / 100 + 1;

	//Ma gioi tinh
	int male = _rng.next(2);
	int gender = (century - 20) * 2 + male;

	//Nam sinh
	int birthYear = (_currentYear - _rng.next(_maxAge)) % 100;

	writer << cityCode << gender;

	if (birthYear < 10) writer << L"0";

	writer << birthYear;

	//Sinh ngau nhien 6 so cuoi:
	for (int i = 0; i < 6; i++)
		writer << _rng.next(10);
	
	wstring id = writer.str();
	return id;
}

StudentIDMock::StudentIDMock() {
	_facultyCodes = { L"11",L"12",L"13",L"14",L"15",L"16",L"17",L"18",L"19",L"20" };
	
	//Thoi gian dao tao toi da la 6 nam
	_maxCourse = 6;
	int tmp = DateTime::currentYear();

	//tim ra 2 so cuoi cua nam hien tai, VD: nam 2021 thi la K21
	int ans1 = tmp % 10;
	tmp /= 10;
	int ans2 =  tmp % 10;
	int ans = ans2 * 10 + ans1;

	//Sinh vien se co MSSV tu K_now -> K_now-6
	for (int i = 0; i < _maxCourse; i++)
		_courseCodes.push_back(ans - i);
}

wstring StudentIDMock::next() {
	wstringstream writer;

	//Ma khoa hoc
	int i = _rng.next(_courseCodes.size());
	int year = _courseCodes[i];

	//Ma khoa
	i = _rng.next(_facultyCodes.size());
	wstring facultyCode = _facultyCodes[i];

	writer << year << facultyCode;

	//Sinh ngau nhien 4 so cuoi:
	for (int i = 0; i < 4; i++)
		writer << _rng.next(10);

	wstring id = writer.str();
	return id;
}
#include "MockRepoV1.h"

vector<wstring> Tokenizer::split(wstring haystack, wstring  needle) {
	vector<wstring> result;

	int startPos = 0;
	size_t foundPos = 0;
	while (true) {
		foundPos = haystack.find(needle, startPos);

		if (foundPos != wstring::npos) {
			wstring token = haystack.substr(startPos, foundPos - startPos);
			result.push_back(token);
			startPos = foundPos + needle.length();
		}
		else {
			wstring token = haystack.substr(startPos, haystack.length() - startPos);
			result.push_back(token);
			break;
		}
	}
	return result;
}

wstring MobileNetwork::name() {
	wstring res = _name;
	return res;
}


vector<wstring> MobileNetwork::prefixes() {
	return _prefixes;
}

MobileNetwork::MobileNetwork() {
	_name = L"";
	_prefixes = {};
}

MobileNetwork::MobileNetwork(wstring s, vector<wstring> num) {
	_name = s;
	_prefixes = num;
}

MobileNetwork Telephone::network() {
	return _network;
}

wstring Telephone::number() {
	return _numbers;
}

wstring Telephone::toString() {
	return _prefixes + _numbers;
}

Telephone::Telephone(MobileNetwork M, wstring s1, wstring s2) {
	_network = M;
	_prefixes = s1;
	_numbers = s2;
}

TelephoneMock::TelephoneMock() {
	_supportedNetworks.push_back(MobileNetwork(L"Viettel", { L"086",L"096",L"097",L"098",L"032",L"033",L"034",L"035",L"036",L"037",L"038",L"039" }));
	_supportedNetworks.push_back(MobileNetwork(L"Vinaphone", { L"088",L"091",L"094",L"083",L"084",L"085",L"081",L"082" }));
	_supportedNetworks.push_back(MobileNetwork(L"Mobiphone", { L"089",L"090",L"093",L"070",L"079",L"077",L"076",L"078" }));
	_supportedNetworks.push_back(MobileNetwork(L"Vietnamoblie", { L"092",L"056",L"058" }));
	_supportedNetworks.push_back(MobileNetwork(L"GMobile", { L"099",L"059" }));
	_supportedNetworks.push_back(MobileNetwork(L"Itelecom", { L"087" }));
}

Telephone TelephoneMock::next() {
	int index = _rng.next(_supportedNetworks.size());
	MobileNetwork network = _supportedNetworks[index];

	vector<wstring> prefixes = network.prefixes();
	index = _rng.next(prefixes.size());
	wstring prefix = prefixes[index];

	wstringstream writer;
	for (int i = 1; i <= 7; i++)
		writer << _rng.next(10);
	wstring numbers = writer.str();

	Telephone result(network, prefix, numbers);
	return result;
}

wstring Fullname::Getfirstname() {
	return _firstName;
}

wstring Fullname::Getmiddlename() {
	return _middleName;
}

wstring Fullname::Getlastname() {
	return _lastName;
}

wstring Fullname::toString() {
	wstringstream builder;
	builder << Getfirstname() << " " << Getmiddlename() << " " << Getlastname();
	wstring ans = builder.str();
	return ans;
}

Fullname::Fullname(wstring first, wstring middle, wstring last) {
	_firstName = first;
	_middleName = middle;
	_lastName = last;
}

FullnameMock::FullnameMock() {
	
	wifstream reader1("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/FamilyNames.txt");
	reader1.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));
	wstring buffer;
	getline(reader1, buffer);
	if (!reader1.is_open()) cout << "Failed V1!";
	else {
		getline(reader1, buffer);
		_firstName = Tokenizer::split(buffer, L" ");
		reader1.close();
	}

	wifstream reader2("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/MaleMiddleNames.txt");
	reader2.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));

	if (!reader2.is_open()) cout << "Failed V1  Male Middle Names!";
	else {
		getline(reader2, buffer);
		_maleMiddleName = Tokenizer::split(buffer, L" ");
		reader2.close();
	}

	wifstream reader3("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/FemaleMiddleNames.txt");
	reader3.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));

	if (!reader3.is_open()) cout << "Failed V1  Female Middle Names!";
	else {
		getline(reader3, buffer);
		_femaleMiddleName = Tokenizer::split(buffer, L" ");
		reader3.close();
	}

	wifstream reader4("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/MaleNames.txt");
	reader4.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));

	if (!reader4.is_open()) cout << "Failed V1  Male Last Names!";
	else {
		getline(reader4, buffer);
		_maleLastName = Tokenizer::split(buffer, L" ");
		reader4.close();
	}

	wifstream reader5("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/FemaleNames.txt");
	reader5.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));

	if (!reader5.is_open()) cout << "Failed V1  FeMale Last Names!";
	else {
		getline(reader5, buffer);
		_femaleLastName = Tokenizer::split(buffer, L" ");
		reader5.close();
	}
}

Fullname FullnameMock::next(bool male) {
	int i = _rng.next(_firstName.size());
	wstring first = _firstName[i];
	wstring middle = L"";
	wstring last = L"";

	if (male) {
		i = _rng.next(_maleMiddleName.size());
		middle = _maleMiddleName[i];
		i = _rng.next(_maleLastName.size());
		last = _maleLastName[i];
	}
	else {
		i = _rng.next(_femaleMiddleName.size());
		middle = _femaleMiddleName[i];
		i = _rng.next(_femaleLastName.size());
		last = _femaleLastName[i];
	}
	Fullname result(first, middle, last);
	return result;
}

EmailMock::EmailMock(){
	wifstream reader("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/domains.txt");
	reader.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));
	wstring buffer;
	if (!reader.is_open()) cout << "Failed V1  Email!";
	else {
		for (int i = 0; i < 3788; i++) {
			getline(reader, buffer);
			_domains.push_back(buffer);
		}
		reader.close();
	}	
}

void EmailMock::fixing(wchar_t& k) {
	vector<vector<wchar_t>> check = { {L'a', L'á', L'à', L'ã', L'ạ', L'ả', L'ă', L'ắ', L'ặ', L'ẳ', L'ẵ', L'â', L'ẩ', L'ậ', L'ấ', L'ầ', L'ẫ'},
	   {L'A', L'Á', L'À', L'Ã', L'Ạ', L'Ả', L'Ă', L'Ắ', L'Ặ', L'Ẳ', L'Ẵ', L'Â', L'Ẩ', L'Ậ', L'Ấ', L'Ầ', L'Ẫ'},
	   {L'd',L'đ'},{L'D',L'Đ'},{L'e', L'é', L'è', L'ẻ', L'ẽ', L'ẹ', L'ê', L'ế', L'ề', L'ể', L'ễ', L'ệ'},
	   {L'E', L'É', L'È', L'Ẻ', L'Ẽ', L'Ẹ', L'Ê', L'Ế', L'Ề', L'Ể', L'Ễ', L'Ệ'},
	   {L'i', L'ì', L'í', L'ị', L'ĩ', L'ỉ'},
	   {L'I', L'Ì', L'Í', L'Ị', L'Ĩ', L'Ỉ'},
	   {L'o', L'ò', L'ó', L'ỏ', L'õ', L'ọ', L'ô', L'ồ', L'ổ', L'ỗ', L'ộ', L'ố', L'ơ', L'ớ', L'ờ', L'ở', L'ỡ', L'ợ'},
	   {L'O', L'Ò', L'Ó', L'Ỏ', L'Õ', L'Ọ', L'Ô', L'Ồ', L'Ổ', L'Ỗ', L'Ộ', L'Ố', L'Ơ', L'Ớ', L'Ờ', L'Ở', L'Ỡ', L'Ợ'},
	   {L'u', L'ú', L'ù', L'ủ', L'ũ', L'ụ', L'ư', L'ừ', L'ử', L'ữ', L'ự', L'ứ'},
	   {L'U', L'Ú', L'Ù', L'Ủ', L'Ũ', L'Ụ', L'Ư', L'Ừ', L'Ử', L'Ữ', L'Ự', L'Ứ'},
	   {L'y', L'ý', L'ỳ', L'ỷ', L'ỹ', L'ỵ'},
	   {L'Y', L'Ý', L'Ỳ', L'Ỷ', L'Ỹ', L'Ỵ'} };
	for (int i = 0; i < check.size(); i++)
		for (int j = 1; j < check[i].size(); j++) {
			if (k == check[i][j]) {
				k = check[i][0];
				break;
			}
		}
}

wstring EmailMock::next(Fullname name) {
	wstring first = name.Getfirstname().substr(0, 1);
	wstring middle = name.Getmiddlename().substr(0, 1);

	int i = _rng.next(_domains.size());
	wstring domain = _domains[i];

	wstringstream writer;
	wstring last = name.Getlastname();
	
	for (int index = 0; index < last.size(); i++)
		fixing(last[index]);
	fixing(first[0]);
	fixing(middle[0]);
	writer << first << middle << last << "@" << domain;

	wstring email = writer.str();

	return email;
}

wstring EmailMock::next() {
	bool male = _rng.next(2) == 1;

	Fullname name = _nameStore.next(male);

	wstring email = next(name);

	return email;
}

wstring Address::getNumber() {
	return _number;
}

wstring Address::getStreet() {
	return _street;
}
wstring Address::getWard() {
	return _ward;
}

wstring Address::getDistrict() {
	return _district;
}

wstring Address::getCity() {
	return _city;
}


void Address::setNumber(wstring value) {
	_number = value;
}

void Address::setStreet(wstring value) {
	_street = value;
}

void Address::setWard(wstring value) {
	_ward = value;
}

void Address::setDistrict(wstring value) {
	_district = value;
}

void Address::setCity(wstring value) {
	_city = value;
}

wstring Address::toString(){
	wstringstream writer;
	writer << getNumber() << L" " << getStreet() << L", " << getWard() << L", " << getDistrict() << L", " << getCity();
	wstring result = writer.str();
	return result;
}
Address::Address(wstring number, wstring street, wstring ward, wstring district, wstring city) {
	setNumber(number);
	setStreet(street);
	setWard(ward);
	setDistrict(district);
	setCity(city);
}

HcmAddressMock::HcmAddressMock() {

	wifstream readerS("C:/Users/User/source/repos/OOP/19120583_Project1_Student/MockRepoV1/MockRepoV1/hcmAddresses.txt");
	readerS.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));
	wstring buffer;

	int numberOfDistricts = 0, numberOfWards = 0, numberOfStreets = 0;

	//read numberOfDistricts
	readerS >> numberOfDistricts;
	readerS.ignore();

	wstring districtName = L"", wardName = L"", streetName = L"";
	if (!readerS.is_open()) cout << "Failed V1  Addresses!";
	else {
		for (int i = 0; i < numberOfDistricts; i++) {
			

			getline(readerS, districtName);
			_districts.push_back(districtName);

			readerS >> numberOfWards;
			readerS.ignore();

		

			for (int j = 0; j < numberOfWards; j++) {
				getline(readerS, wardName);
				_wards.push_back(wardName);
			}

			readerS >> numberOfStreets;
			readerS.ignore();


			for (int j = 0; j < numberOfStreets; j++) {
				getline(readerS, streetName);
				_streets.push_back(streetName);
			}
		}
		readerS.close();
	}



	//_streets = { "Nguyen Hue","Pham Van Dong","Kha Van Can","Nguyen Huu Canh","Nguyen Van Cu","Nguyen Van Troi","Tran Phu","Nguyen Trai","Ho Tung Mau",
	//	"To Ngoc Van","Le Quy Don", "Phan Dinh Phung", "Truong Sa", "Quang Trung"};
	//_wards = { "Ward 1", "Ward 2", "Ward 3", "Ward 4", "Ward 5", "Linh Trung", "Linh Dong", "Linh Tay","Long Binh","Binh Tho","Hiep Binh Chanh",
	//"Hiep Binh Phuoc","Linh Chieu","Linh Xuan","Tam Binh","Tam Phu" };
	//_districts = { "District 1","District 2", "District 3", "District 4", "District 5", "District 6", "District 7", "District 8",
	//"District 9", "District 10", "District 11", "District 12", "Binh Tan District","Binh Thanh District","Tan Phu District","Tan Binh District","Go Vap District" };
	_cities = { L"Ho Chi Minh city" };
}

Address HcmAddressMock::next() {
	wstring number = to_wstring(_rng.next(100));

	int i = _rng.next(_streets.size());
	wstring street = _streets[i];

	i = _rng.next(_wards.size());
	wstring ward = _wards[i];

	i = _rng.next(_districts.size());
	wstring district = _districts[i];

	i = _rng.next(_cities.size());
	wstring city = _cities[i];

	Address address(number, street, ward, district, city);
	return address;
}
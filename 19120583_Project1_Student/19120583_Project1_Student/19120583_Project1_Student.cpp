// 19120583_Project1_Student.cpp 
#include "SupeLib.h"

vector<wstring> split(wstring haystack, wstring  needle) {
    vector<wstring> result;

    int startPos = 0;
    size_t foundPos = 0;
    while (true) {
        foundPos = haystack.find(needle, startPos);

        if (foundPos != string::npos) {
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

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    Random _rng;
    int n = _rng.next(5, 20);
  
    vector<Student> Students;
   
    for (int i = 0; i < n; i++) {
        Student student;
        Students.push_back(student);
    }
     
    wofstream writer("students.txt");
    writer.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t, 0x10ffff, codecvt_mode(consume_header | generate_header)>));
    writer << n << "\n";
    for (int i = 0; i < n; i++)
       writer << Students[i];

    writer.close();

    wcout << L"\n\nCác sinh viên sinh nhật tháng Hai là: \n";
    for (int i = 0; i < Students.size(); i++){
        wstring birthday = Students[i].getDob();
        if (birthday[2] == '2')
            wcout << Students[i] << endl;  
    }

    wcout << L"\nCác sinh viên sử dụng mạng Viettel:\n";
    vector<wstring> Viettel = { L"086", L"096", L"097", L"098",L"032", L"033", L"034",
        L"035", L"036", L"037", L"038", L"039" };
    for (int i = 0; i < Students.size(); i++) {
        wstring Tel = Students[i].getTelephone();
        wstring prefixes = Tel.substr(0, 3);
        for (int j = 0; j < Viettel.size(); j++)
            if (prefixes == Viettel[j])
               wcout << Students[i] << endl;         
    }

    wcout << L"\n\nSINH VIÊN SỬ DỤNG GMAIL:\n";
    for (int i = 0; i < Students.size(); i++)
    {
        wstring email = Students[i].getEmail();
        vector<wstring> tokens = split(email, L"@");
        wstring s0 = tokens[1];
        if (s0 == L"gmail.com")
        {
            wcout << Students[i];
        }
    }   

    wcout << L"\n\nSinh viên ở Quận 1:\n";

    for (int i = 0; i < Students.size(); i++)
    {
        wstring address = Students[i].getAddress();
        vector<wstring> tokens = split(address, L", ");
        wstring s1 = tokens[2];
        if (s1 == L"District 1")
        {
            wcout << Students[i];
        }

    }
    
    /*Hàm bổ sung
    * 
    * Xuất ra tên tỉnh thành từ mã tỉnh thành căn cước CD
    CitizenIdMock idstore;
    wstring city = L"068";//Nhap ma tinh thanh.
    wstring ans = idstore.lookupCity(city);
    wcout << ans;
    
    */
}

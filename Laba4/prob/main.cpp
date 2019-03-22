#include <iostream>
#include <locale>

int main()
{
 std::locale loc("ru_RU.UTF-8");
 std::locale::global(loc); // установка глобальной локали
 std::wstring ws = L"привет, мир"; // использется "широкая" текстовая константа
 for(wchar_t & wc: ws) {
 wc = toupper(wc,loc);
 }
 std::wcout<<ws.size()<<ws<<std::endl; //вывод в wcout
}

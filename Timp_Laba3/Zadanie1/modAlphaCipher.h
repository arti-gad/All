#pragma once
#include <vector>
#include <string>
#include <map>

class modAlphaCipher
{
private:
 std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
 std::map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
 std::vector <int> key; //ключ
 std::vector<int> convert(const std::string& s); //преобразование строка-вектор
 std::string convert(const std::vector<int>& v); //преобразование вектор-строка
 std::string getValidKey(const std::string & s);
 std::string getValidOpenText(const std::string & s);
 std::string getValidCipherText(const std::string & s);
public:
 modAlphaCipher()=delete; //запретим конструктор без параметров
 modAlphaCipher(const std::string& skey); //конструктор для установки ключа
 std::string encrypt(const std::string& open_text); //зашифрование
 std::string decrypt(const std::string& cipher_text);//расшифрование
};

class cipher_error: public std::invalid_argument {
public:
 explicit cipher_error (const std::string& what_arg):
 std::invalid_argument(what_arg) {}
 explicit cipher_error (const char* what_arg):
 std::invalid_argument(what_arg) {}
};
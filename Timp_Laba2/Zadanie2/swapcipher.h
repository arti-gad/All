#pragma once
#include <vector>
#include <string>
#include <map>

class SwapCipher
{
private:
 int key_stolbec;
 int key_stroka;
 std::wstring real_cp;
 void getValidKey(const int& key);
 std::string getValidOpenText(const std::string & s);
public:
 SwapCipher()=delete; //запретим конструктор без параметров
 SwapCipher(const int key1); //конструктор для установки ключа
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
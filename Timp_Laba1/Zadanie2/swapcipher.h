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
public:
 SwapCipher()=delete; //запретим конструктор без параметров
 SwapCipher(const int key1); //конструктор для установки ключа
 std::string encrypt(const std::string& open_text); //зашифрование
 std::string decrypt(const std::string& cipher_text);//расшифрование
};
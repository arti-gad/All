#pragma once
#include <vector>
#include <string>
#include <map>
/** @file
 * @author Григорьев А.Д.
 * @version 1.0
 * @date 09.06.2019
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Заголовочный файл для модуля Gronsfeld
 */


/** @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */
class modAlphaCipher
{
private:
 std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
 std::map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
 std::vector <int> key; ///< ключ
 std::vector<int> convert(const std::string& s); //преобразование строка-вектор
 std::string convert(const std::vector<int>& v); //преобразование вектор-строка
 std::string getValidKey(const std::string & s);
 std::string getValidOpenText(const std::string & s);
 std::string getValidCipherText(const std::string & s);
public:
 modAlphaCipher()=delete; //запретим конструктор без параметров
 modAlphaCipher(const std::string& skey); //конструктор для установки ключа
 /**
 * @brief Зашифровывание
 * @param [in] open_text Открытый текст. Не должен быть пустой строкой.
 * Строчные символы автоматически преобразуются к
прописным.
 * Все не-буквы удаляются
 * @return Зашифрованная строка
 * @throw cipher_error, если текст пустой
 */

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
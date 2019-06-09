/** @file
 * @author Григорьев А.Д.
 * @version 1.0
 * @date 09.06.2019
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Заголовочный файл для модуля swapcipher
 */

#pragma once
#include <vector>
#include <string>
#include <map>

/** @brief Шифрование методом табличной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */
class SwapCipher
{
private:
    int key_stolbec; ///< ключ(количество столбцов матрицы)
    int key_stroka; ///< количество строк матрицы
    std::wstring real_cp; ///< строка передающаяся в decrypt
    /**
    * @brief Проверка ключа на валидность
    * @details Проверки на все исключения "выбрасываеые"
    конструктором
    * @param [in] key Ключ.
    * @throw cipher_error если ключ - меньше нуля или ноль.
    */
    void getValidKey(const int& key);
    /**
    * @brief Проверка шифруемого текста
    * @details Проверки на все исключения "выбрасываеые" методом
    encrypt
    * @param [in] open_text Открытый текст.
    * @throw cipher_error, если текст пустой
    * если текст еденичной длины
    * если текст содержит пробелы
    */
    std::string getValidOpenText(const std::string & s);
    /**
    * @brief Проверка дешифруемого текста
    * @details Проверки на все исключения "выбрасываеые" методом
    decrypt
    * @param [in] cipher_text Зашифрованный текст.
    * @throw cipher_error, если текст пустой
    * если текст еденичной длины
    * если текст содержит пробелы
    */
    std::string getValidCipherText(const std::string & s);
public:
    SwapCipher()=delete; ///< конструктор без параметров запрещен
    SwapCipher(const int key1); ///< конструктор для установки ключа
    /**
    * @brief Зашифровывание
    * @param [in] open_text Открытый текст. Не должен быть пустой
    строкой.
    * Не должен быть единичной длины
    * Строчные символы автоматически преобразуются к
    прописным.
    * @return Зашифрованная строка
    * @throw cipher_error, если текст пустой
    * если текст еденичной длины
    * если текст содержит пробелы
    */
    std::string encrypt(const std::string& open_text); //зашифрование
    /**
    * @brief Дешифровывание
    * @param [in] open_text Закодированный текст. Не должен быть
    пустой строкой.
    * Не должен быть единичной длины
    * @return Зашифрованная строка
    * @throw cipher_error, если текст пустой
    * если текст еденичной длины
    * если текст содержит пробелы
    */
    std::string decrypt(const std::string& cipher_text);//расшифрование
};

/** @brief Класс для обработки исключений
 * @details Состоит из двух методов.
 * Для вывода исключения использует строку.
 */
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};

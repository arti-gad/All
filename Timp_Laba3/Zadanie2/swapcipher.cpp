#include "swapcipher.h"
#include <locale>
#include <codecvt>
std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;

SwapCipher::SwapCipher(const int key1)
{
    key_stolbec = key1;
    getValidKey(key_stolbec);
}

std::string SwapCipher::encrypt(const std::string& open_text)
{
    std::string result;
    std::wstring ws = codec.from_bytes(getValidOpenText(open_text));
    int i = 0, j = 0;
    key_stroka = ((ws.length() - 1) / key_stolbec) + 1;
    while(ws.length() % key_stroka != 0)
        ws += L'*';
    for (i = key_stolbec - 1; i >= 0; i--) 
        for (j = i; j < key_stolbec*key_stroka; j = j + key_stolbec)
            real_cp += ws[j];
    ws = L"";
    for (i = 0; i < key_stolbec*key_stroka; i++)
		if (((real_cp[i] >= L'А') && (real_cp[i] <= L'Я')) || real_cp[i] == L'Ё')
			ws += real_cp[i];
    result = codec.to_bytes(ws);
    return result;
}

std::string SwapCipher::decrypt(const std::string& cipher_text)
{
    getValidCipherText(cipher_text);
    std::string result;
    std::wstring ws;
    std::wstring ciphertext;
    int i = 0, j = 0;
    for (i = key_stroka; i > 0; i--) 
        for (j = (key_stroka * key_stolbec) - i; j >= 0; j = j - key_stroka)
            ciphertext += real_cp[j];
    for (i = 0; i < key_stolbec*key_stroka; i++)
		if (((ciphertext[i] >= L'А') && (ciphertext[i] <= L'Я')) || ciphertext[i] == L'Ё')
			ws += ciphertext[i];
    result = codec.to_bytes(ws);
    return result;
}

void SwapCipher::getValidKey(const int & key)
{
 if (key <= 0)
     throw cipher_error("Empty key");
}

inline std::string SwapCipher::getValidOpenText(const std::string & s)
{
 std::string result;
 std::wstring tmp;
 std::wstring ws = codec.from_bytes(s);
 for (auto c:ws) {
 if (isalpha(c, loc)) {
 if (islower(c, loc))
 tmp.push_back(toupper(c, loc));
 else
 tmp.push_back(c);
 }
 }
 if (tmp.empty())
 throw cipher_error("Empty open text");
 result = codec.to_bytes(tmp);
 return result;
}

inline std::string SwapCipher::getValidCipherText(const std::string & s)
{
 std::string result;
 std::wstring ws = codec.from_bytes(s);
 if (ws.empty())
 throw cipher_error("Empty cipher text");
 for (auto c:ws) {
 if (!isupper(c, loc))
 throw cipher_error(std::string("Invalid cipher text ")+s);
 }
 result = codec.to_bytes(ws);
 return result;
}
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>

std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
using namespace std;
modAlphaCipher::modAlphaCipher(const std::string& skey)
{
 for (unsigned i=0; i < numAlpha.size(); i++) 
    alphaNum[numAlpha[i]]=i;
 key = convert(getValidKey(skey));
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{
 std::vector<int> work = convert(getValidOpenText(open_text));
 for(unsigned i=0; i < work.size(); i++) 
    work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
 return convert(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
 std::vector<int> work = convert(getValidCipherText(cipher_text));
 for(unsigned i=0; i < work.size(); i++) 
    work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
 return convert(work);
}

inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{
 std::wstring ws = codec.from_bytes(s); // перекодируем из UTF-8 в UTF-32
 std::vector<int> result;
 for(auto c:ws) 
    result.push_back(alphaNum[c]);
 return result;
}

inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
 std::string result;
 std::wstring ws = codec.from_bytes(result); // перекодируем из UTF-8 в UTF-32
 for(auto i:v) 
    ws.push_back(numAlpha[i]);
 result = codec.to_bytes(ws);
 return result;
}

inline std::string modAlphaCipher::getValidKey(const std::string & s)
{
 std::string result;
 std::wstring ws = codec.from_bytes(s);
 if (ws.empty())
 throw cipher_error("Empty key");
 std::wstring tmp(ws);
 for (auto & c:tmp) {
 if (!isalpha(c, loc)) //((c < L'А' && c > L'Я') || (c < L'а' && c > L'я')) - почему это условие не работает???
 throw cipher_error(std::string("Invalid key ") + s);
 if (islower(c, loc)) //(c >= L'а' && c <= L'я')
 c = toupper(c, loc);
 }
 result = codec.to_bytes(tmp);
 return result;
}

inline std::string modAlphaCipher::getValidOpenText(const std::string & s)
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

inline std::string modAlphaCipher::getValidCipherText(const std::string & s)
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

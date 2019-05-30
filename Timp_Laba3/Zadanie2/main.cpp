#include <unittest++/UnitTest++.h>
#include "swapcipher.h"

SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("ВГАОКПЬЬЛТТЕЯЕШЛПЫУ",SwapCipher(7).encrypt("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ"));
    }
    TEST(LongKey) {
        CHECK_EQUAL("ЬТЯЛУГОПЛЕШЫВАКЬТЕП",SwapCipher(100).encrypt("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ"));
    }
    TEST(MinusInKey) {
        CHECK_THROW(SwapCipher cp(-245),cipher_error);
    }
    TEST(ZeroInKey) {
        CHECK_THROW(SwapCipher cp(0),cipher_error);
    }
}

struct KeyB_fixture {
    SwapCipher * p;
    KeyB_fixture() {
        p = new SwapCipher(5);
    }
    ~KeyB_fixture() {
        delete p;
    }
};

SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("КЕУЬШГЬТЫОТЕВПЯПАЛЛ",
                    p->encrypt("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("КЕУЬШГЬТЫОТЕВПЯПАЛЛ",
                    p->encrypt("петькавышелпогулять"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("КЕУЬШГЬТЫОТЕВПЯПАЛЛ",
                    p->encrypt("Петька вышел погулять!!!"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
        CHECK_EQUAL("ЛЛАИИРРРВИБЯКЛСЗ", p->encrypt("Кирилл брился в 2019 раз"));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt(""),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt("1234+8765=9999"),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("ЬТЯЛУГОПЛЕШЫВАКЬТЕП",
                    SwapCipher(23852).encrypt("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ"));
    }
}

SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p->decrypt("кеУЬШГЬСЫОТАВПЯВАЛЛ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
        CHECK_THROW(p->decrypt("КЕУ ЬШГ ЬТЫ ОТЕ ВПЯ ПАЛЛ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, DigitsString) {
        CHECK_THROW(p->decrypt("ЛЛАИИРРРВИБ2019ЯКЛСЗ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, PunctString) {
        CHECK_THROW(p->decrypt("КЕУЬШГ,ЬТЫОТЕВПЯПАЛЛ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(""),cipher_error);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}

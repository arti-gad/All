#include <unittest++/UnitTest++.h>
#include "modAlphaCipher.h"

SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("БЦДБЦ",modAlphaCipher("БЦД").encrypt("ААААА"));
    }
    TEST(LongKey) {
        CHECK_EQUAL("БЦДЕФ",modAlphaCipher("БЦДЕФГШИЖК").encrypt("ААААА"));
    }
    TEST(LowCaseKey) {
        CHECK_EQUAL("БЦДБЦ",modAlphaCipher("бцд").encrypt("ААААА"));
    }
    TEST(DigitsInKey) {
        CHECK_THROW(modAlphaCipher cp("Б1"),cipher_error);
    }
    TEST(PunctuationInKey) {
        CHECK_THROW(modAlphaCipher cp("Б,С"),cipher_error);
    }
    TEST(WhitespaceInKey) {
        CHECK_THROW(modAlphaCipher cp("Б С"),cipher_error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher cp(""),cipher_error);
    }
    TEST(WeakKey) {
        CHECK_THROW(modAlphaCipher cp("ААА"),cipher_error);
    }
}

struct KeyB_fixture {
    modAlphaCipher * p;
    KeyB_fixture() {
        p = new modAlphaCipher("Б");
    }
    ~KeyB_fixture() {
        delete p;
    }
};

SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("РЁУЭЛБГЬЩЁМРПДФМАУЭ",
                    p->encrypt("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("РЁУЭЛБГЬЩЁМРПДФМАУЭ",
                    p->encrypt("петькавышелпогулять"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("РЁУЭЛБГЬЩЁМРПДФМАУЭ",
                    p->encrypt("Петька вышел погулять!!!"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
        CHECK_EQUAL("ЛЙСЙММВСЙМТАГСБИ", p->encrypt("Кирилл брился в 2019 раз"));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt(""),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt("1234+8765=9999"),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("ОДСЫЙЯБЪЧДКОНВТКЮСЫ",
                    modAlphaCipher("Я").encrypt("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ"));
    }
}

SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ",
                    p->decrypt("РЁУЭЛБГЬЩЁМРПДФМАУЭ"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p->decrypt("рёУЭЛБГЬЩЁМРПДФМАУЭ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
        CHECK_THROW(p->decrypt("РЁУ ЭЛБ ГЬЩ ЁМР ПДФ МАУЭ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, DigitsString) {
        CHECK_THROW(p->decrypt("ЛЙСЙММВСЙМ2019ТАГСБИ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, PunctString) {
        CHECK_THROW(p->decrypt("РЁУЭЛБ,ГЬЩЁМРПДФМАУЭ"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(""),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("ПЕТЬКАВЫШЕЛПОГУЛЯТЬ",
                    modAlphaCipher("Я").decrypt("ОДСЫЙЯБЪЧДКОНВТКЮСЫ"));
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}

#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class modBetaCipher
{
private:
    int key1; // кол-во столбцов
public:
    modBetaCipher()=delete; // запрет конструктора без параметров
    modBetaCipher(const int& key) :key1(key) {};
    std::wstring encrypt(const std::wstring& open_text); // зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};

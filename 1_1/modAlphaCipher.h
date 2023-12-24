#pragma once
#include <vector>
#include <string>
#include <map>
#include <locale>
using namespace std;
class modAlphaCipher
{
private:
    wstring numAlpha =L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; //алфавит по порядку
    map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
    vector <int> key; //ключ
    vector<int> convert(const wstring& c); //преобразование строка-вектор
    wstring convert(const vector<int>& w); //преобразование вектор-строка
public:
    modAlphaCipher()=delete; //запретим конструктор без параметров
    modAlphaCipher(const wstring& xkey); //конструктор для установки ключа
    wstring encrypt(const wstring& open_text); //зашифрование
    wstring decrypt(const wstring& cipher_text);//расшифрование
};
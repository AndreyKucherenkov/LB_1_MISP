#include <stdio.h>
#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
using namespace std;
bool isValid(const wstring& s)
{
    for (auto c:s)
        if (!isalpha(c) || !isupper(c))
            return false;
    return true;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;
    wcout<<L"Cipher ready. Input key: ";
    wcin>>key;
    if (!wcin.good()) {
        wcerr<<L"Key not valid\n";
        return 0;
    }

    modBetaCipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"Wrong operation\n";
        } else if (op >0) {
            wcout<<L"Cipher ready. Input text: ";
            wcin>>text;
            if (isValid(text)) {
                if (op==1) {
                    wcout<<L"Encrypted text: "<<cipher.encrypt(text)<<endl;
                } else {
                    wcout<<L"Decrypted text: "<<cipher.decrypt(text)<<endl;
                }
            } else {
                wcout<<L"Operation aborted: Invalid text\n";
            }
        }
    } while (op!=0);
    return 0;
}

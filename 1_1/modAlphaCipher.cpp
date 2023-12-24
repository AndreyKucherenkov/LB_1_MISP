#include "modAlphaCipher.h"
modAlphaCipher::modAlphaCipher(const wstring& xkey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(xkey);
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& c)
{
    vector<int> result;
    for(auto a:c) {
        result.push_back(alphaNum[a]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& w)
{
    wstring result;
    for(auto i:w) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
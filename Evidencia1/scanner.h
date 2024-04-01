#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "reader.h"

// Parte 1 es bool si es malicioso o no
// Parte 2 es, si hay codigo espejeado regresa la posicion donde empieza y termina tanto para transmission 1 y 2
// Parte 3 regresa el substring mas largo entre ambos strings
using namespace std;

struct match {
    string pattern;
    int initindex;
    int endindex;
    //initialize both to -1
    match() {
        this->initindex = -1;
        this->endindex = -1;
        this->pattern = "";
    }
};

class Scanner : public reader {
    public:
        Scanner(string filename) : reader(filename) {
            this->content = reader(filename).getString();
        }
        bool isMalicious(reader mcode);
        void longestCommonSubstring(vector<string> transmissions);
    private:
        string filename;
        string content;
};
// ********** Parte 3 ********** 
// Falta agregar las posiciones de los substrings
void Scanner::longestCommonSubstring(vector<string> transmissions) {
    string result = "";
    string current_substring = "";
    match matchT1, matchT2;
    int n = transmissions.size();
    if (n == 0) {
        return;
    }
    else if (n == 1) {
        for (int i = 0; i < transmissions[0].size(); i++) {
            result += transmissions[0][i];
        }
        cout << matchT1.pattern << endl;
        return;
    }
    sort(transmissions.begin(), transmissions.end());

    int min_length = min(transmissions[0].size(), transmissions[n-1].size());

    string first = transmissions[0];
    string last = transmissions[n-1];
    int i = 0;
    while (i < min_length) {
        if (first[i] == last[i]) {
            current_substring += first[i];
        }
        else {
            if (current_substring.size() > result.size()) {
                result = current_substring;
            }
            current_substring = "";
        }
        i++;
    }
    size_t found = first.find(result);
    if (found != string::npos) {
        matchT1.initindex = found;
        matchT1.endindex = found + result.size();
    }
    found = last.find(result);
    if (found != string::npos) {
        matchT2.initindex = found;
        matchT2.endindex = found + result.size();
    }
    cout << "Pattern found in transmission 1: " << matchT1.initindex << " to " << matchT1.endindex << endl;
    cout << "Pattern found in transmission 2: " << matchT2.initindex << " to " << matchT2.endindex << endl;
    cout << "Pattern is: " << result << endl;
}

// ********** Parte 1 **********

void getLPSarray(string pat, int M, int* lps);

bool Scanner::isMalicious(reader mcode) {
    int M = mcode.getString().size();
    int N = content.size();
 
    if (M > N) {
        // The pattern is longer than the content, so it cannot be found
        return false;
    }

    int lps[M];
    getLPSarray(mcode.getString(), M, lps);

    int i = 0;
    int j = 0; 
    while (i < N) {
        if (mcode.getString()[j] == content[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            cout << "Malicious code found at index " << i - j << endl;
            return true;
        }
 
        else if (i < N && mcode.getString()[j] != content[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    // Pattern not found in the content
    return false;
}

void getLPSarray(string pat, int M, int* lps)
{
    int len = 0;
 
    lps[0] = 0; 
 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {

            if (len != 0) {
                len = lps[len - 1];

            }
            else // (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
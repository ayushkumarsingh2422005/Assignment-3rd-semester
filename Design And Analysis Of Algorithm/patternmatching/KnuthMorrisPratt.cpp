#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeLPSArray(const string &pattern, vector<int> &lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpPatternMatch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m, 0);

    computeLPSArray(pattern, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "KMP Pattern Matching:\n";
    kmpPatternMatch(text, pattern);
    return 0;
}
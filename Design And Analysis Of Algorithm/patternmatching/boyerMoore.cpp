#include <iostream>
#include <string>
#include <vector>
using namespace std;

void preprocessBadCharacter(const string &pattern, vector<int> &badChar) {
    int m = pattern.size();
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[pattern[i]] = i;
}

void boyerMoorePatternMatch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> badChar(256, -1);

    preprocessBadCharacter(pattern, badChar);

    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Boyer-Moore Pattern Matching:\n";
    boyerMoorePatternMatch(text, pattern);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

void bruteForcePatternMatch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout << "Brute Force Pattern Matching:\n";
    bruteForcePatternMatch(text, pattern);
    return 0;
}

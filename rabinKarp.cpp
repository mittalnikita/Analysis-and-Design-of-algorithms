#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RabinKarp {
private:
    int base;     // The base for the hash function (usually a prime number)
    int primeMod; // A large prime number to mod the hash values for consistency

public:
    RabinKarp(int base = 256, int primeMod = 101) : base(base), primeMod(primeMod) {}

    // Function to search the pattern in the given text and return starting indices of matches
    vector<int> search(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<int> result;

        if (m > n) return result; // If pattern is longer than text, return empty result

        int patternHash = 0;   // Hash of the pattern
        int textHash = 0;      // Hash of the current substring of text
        int h = 1;             // The value of base^(m-1)

        // Precompute h = base^(m-1) % primeMod
        for (int i = 0; i < m - 1; i++) {
            h = (h * base) % primeMod;
        }

        // Compute initial hash for pattern and the first substring of text
        for (int i = 0; i < m; i++) {
            patternHash = (base * patternHash + pattern[i]) % primeMod;
            textHash = (base * textHash + text[i]) % primeMod;
        }

        // Slide the pattern over text one character at a time
        for (int i = 0; i <= n - m; i++) {
            // If hash values match, check characters one by one for verification
            if (patternHash == textHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    result.push_back(i); // Match found at index i
                }
            }

            // Calculate hash for the next substring of text
            if (i < n - m) {
                textHash = (base * (textHash - text[i] * h) + text[i + m]) % primeMod;

                // Ensure positive hash value
                if (textHash < 0) {
                    textHash += primeMod;
                }
            }
        }
        return result;
    }
};

int main() {
    RabinKarp rk; // Instantiate RabinKarp object with default base and primeMod
    string text = "ababcabcabababd";
    string pattern = "abab";

    vector<int> matches = rk.search(text, pattern);

    if (matches.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found in the given string at the resultant positions : ";
        for (int index : matches) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}

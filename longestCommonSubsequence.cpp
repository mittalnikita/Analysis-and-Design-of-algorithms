#include <algorithm> // Include this to use std::reverse
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LCS {
private:
    string str1, str2;
    vector<vector<int>> dp; // DP table to store LCS lengths

public:
    LCS(const string &s1, const string &s2) : str1(s1), str2(s2) {
        int n = str1.length();
        int m = str2.length();
        dp.resize(n + 1, vector<int>(m + 1, 0)); // Initialize DP table
    }

    // Function to calculate the length of LCS
    int findLCS() {
        int n = str1.length();
        int m = str2.length();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    // Function to print the LCS
    string getLCS() {
        int i = str1.length(), j = str2.length();
        string lcs;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main() {
    string s1 = "DAYANLORD";
    string s2 = "ANYARO";

    LCS lcs(s1, s2);

    cout << "Length of LCS: " << lcs.findLCS() << endl;
    cout << "LCS: " << lcs.getLCS() << endl;

    return 0;
}

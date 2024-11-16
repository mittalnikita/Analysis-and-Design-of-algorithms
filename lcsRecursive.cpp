#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class LCS {
public:
    string str1, str2;
    vector<vector<int>> dp;

    LCS(string s1, string s2) : str1(s1), str2(s2) {
        dp.resize(str1.length() + 1, vector<int>(str2.length() + 1, -1));
    }

    // Function to calculate LCS length using memoization
    int lcsLength(int i, int j) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (str1[i - 1] == str2[j - 1]) {
            dp[i][j] = 1 + lcsLength(i - 1, j - 1);
        } else {
            dp[i][j] = max(lcsLength(i - 1, j), lcsLength(i, j - 1));
        }
        return dp[i][j];
    }

    // Function to construct the LCS from the DP table
    string getLCS() {
        int i = str1.length(), j = str2.length();
        lcsLength(i, j); // Ensure the dp table is filled
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
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";
    LCS lcsObj(s1, s2);
    cout << "LCS: " << lcsObj.getLCS() << endl;
    return 0;
}

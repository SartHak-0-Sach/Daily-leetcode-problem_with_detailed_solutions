#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() < text2.length()) {
            return LCS(text1, text2);
        }
        return LCS(text2, text1);
    }

    int LCS(string s1, string s2) {
        vector<vector<int>> M(2, vector<int>(s1.length() + 1, 0));

        for (int i = 1; i <= s2.length(); i++) {
            M[i % 2][0] = 0;
            for (int j = 1; j <= s1.length(); j++) {
                if (s1[j - 1] == s2[i - 1]) {
                    M[i % 2][j] = M[(i - 1) % 2][j - 1] + 1;
                } else {
                    M[i % 2][j] = max(M[(i - 1) % 2][j - 1],
                                max(M[(i - 1) % 2][j], M[i % 2][j - 1]));
                }
            }
        }
        return M[s2.length() % 2][s1.length()];
    }
};
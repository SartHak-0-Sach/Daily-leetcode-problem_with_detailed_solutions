#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScores(n + 1, 0); // To store trust scores for each person
        
        // Iterate through the trust relationships and update trust scores
        for (const auto& t : trust) {
            trustScores[t[0]]--; // Decrease trust score for the person who trusts
            trustScores[t[1]]++; // Increase trust score for the person who is trusted
        }
        
        // Check if there is a person who is trusted by everyone (except themselves)
        for (int i = 1; i <= n; ++i) {
            if (trustScores[i] == n - 1) { // If someone's trust score is n-1, they are the judge
                return i;
            }
        }
        
        return -1; // If no such person is found
    }
};
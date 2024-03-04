#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        int count = 0;
        sort(tokens.begin(), tokens.end());
        int left = 0, right = n - 1;
        int maxScore = 0;
        while (left <= right)
        {
            if (tokens[left] <= power)
            {
                power -= tokens[left++];
                count++;
                maxScore = max(maxScore, count);
            }
            else if (count > 0)
            {
                power += tokens[right--];
                count--;
            }
            else
            {
                break;
            }
        }
        return maxScore;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minKBitFlips(std::vector<int>& A, int K) {
        int n = A.size(), flipped = 0, res = 0;
        std::vector<int> isFlipped(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (i >= K)
                flipped ^= isFlipped[i - K];
            if (flipped == A[i]) {
                if (i + K > n)
                    return -1;
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        
        return res;
    }
};
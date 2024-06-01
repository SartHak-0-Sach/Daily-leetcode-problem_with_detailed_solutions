#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefix[i] == prefix[k + 1]) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};
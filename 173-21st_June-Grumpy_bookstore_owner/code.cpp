#include <iostream>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int originalTotal = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (!grumpy[i]) {
                originalTotal += customers[i];
            }
        }

        int l = 0;
        int r = 0;
        int sum = 0;
        int totalSum = 0;
        int maxDiff = 0;

        while (r < customers.size()) {
            if (r - l + 1 < minutes) {
                while (r - l + 1 <= minutes) {
                    if (!grumpy[r]) sum += customers[r];
                    totalSum += customers[r]; // potential total sum;
                    r++;
                } 
                r--; // offset r back
            } else {
                totalSum += customers[r];
                sum += (!grumpy[r]) ? customers[r] : 0;
            }
    
            maxDiff = max(maxDiff, totalSum - sum);
            
            totalSum -= customers[l];
            sum -= (!grumpy[l]) ? customers[l] : 0;
            l++;
            r++;
        }

        return originalTotal + maxDiff;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool fn(std::vector<int>& arr, int m, int mid) {
        int cnt = 1, prev = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - prev >= mid) {
                cnt++;
                prev = arr[i];
            }
        }
        return cnt >= m;
    }

    int maxDistance(std::vector<int>& p, int m) {
        std::sort(p.begin(), p.end());
        int lo = 1, hi = p.back() - p.front();
        while(hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if(fn(p, m, mid)) lo = mid;
            else hi = mid - 1;
        }
        if(fn(p, m, hi)) return hi;
        return lo;
    }
};
#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        uint16_t bitmap = 0;
        uint16_t bitmapcount[2048] = {0};
        bitmapcount[0] = 1;
        
        for (auto &c : word) {
            bitmap ^= 1 << (c & 0b1111);
            bitmapcount[bitmap]++;
        }
        
        uint64_t count = 0;
        uint64_t bmcount;
        
        for (bitmap = 0; bitmap < 2048; bitmap += 2) {
            if (bmcount = bitmapcount[bitmap]) {
                count += bmcount * (
                    bitmapcount[bitmap ^ 0x400] + bitmapcount[bitmap ^ 0x200] +
                    bitmapcount[bitmap ^ 0x100] + bitmapcount[bitmap ^ 0x080] +
                    bitmapcount[bitmap ^ 0x040] + bitmapcount[bitmap ^ 0x020] +
                    bitmapcount[bitmap ^ 0x010] + bitmapcount[bitmap ^ 0x008] +
                    bitmapcount[bitmap ^ 0x004] + bitmapcount[bitmap ^ 0x002] +
                    bmcount
                ) - bmcount;
            }
        }
        
        return count >> 1;
    }
};
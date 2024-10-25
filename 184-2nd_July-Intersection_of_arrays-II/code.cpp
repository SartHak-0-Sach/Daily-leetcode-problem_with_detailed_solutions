#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define nline '\n'
#define sp ' '
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
static int fastIO = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
// Paste the Class here-
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> hashmap;
        vector<int> Res;
        for (int i = 0; i < nums1.size(); i++)
        {
            hashmap[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            int element = nums2[i];
            if (hashmap.find(element) != hashmap.end())
            {
                Res.push_back(element);
                hashmap[element]--;
                if (hashmap[element] == 0)
                {
                    hashmap.erase(element);
                }
            }
        }
        return Res;
    }
};
class Solution
{
public:
    using int2 = array<int, 2>;
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size(), freq[201] = {0};
        for (int x : nums)
        {
            freq[x + 100]++;
        }

        sort(nums.begin(), nums.end(), [&](int x, int y)
             { return (freq[x + 100] == freq[y + 100]) ? x > y : freq[x + 100] < freq[y + 100]; });
        return nums;
    }
};

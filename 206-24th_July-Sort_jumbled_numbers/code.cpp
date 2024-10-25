class Solution
{
private:
    long long mapStringToInt(string num, vector<int> &mapping)
    {
        long long res = 0;

        for (int i = 0; i < num.size(); i++)
        {
            int idx = num[i] - '0';
            res = (res + mapping[idx]) * 10;
        }

        res = res / 10;

        return res;
    }

public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {

        auto lambda = [&](auto first, auto second)
        {
            return mapStringToInt(to_string(first), mapping) < mapStringToInt(to_string(second), mapping);
        };

        sort(nums.begin(), nums.end(), lambda);

        return nums;
    }
};
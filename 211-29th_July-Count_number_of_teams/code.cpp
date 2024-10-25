class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        const int m = rating.size();
        int ans = 0;
        for (int i = 1; i < m - 1; ++i)
        {
            int lowerThanLeft = 0;
            int higherThanLeft = 0;
            int lowerThanRight = 0;
            int higherThanRight = 0;
            for (int j = 0; j < i; ++j)
            {
                if (rating[j] < rating[i])
                {
                    ++lowerThanLeft;
                }
                else if (rating[j] > rating[i])
                {
                    ++higherThanLeft;
                }
            }
            for (int j = i + 1; j < m; ++j)
            {
                if (rating[j] < rating[i])
                {
                    ++lowerThanRight;
                }
                else if (rating[j] > rating[i])
                {
                    ++higherThanRight;
                }
            }
            ans += ((lowerThanLeft * higherThanRight) + (higherThanLeft * lowerThanRight));
        }
        return ans;
    }
};
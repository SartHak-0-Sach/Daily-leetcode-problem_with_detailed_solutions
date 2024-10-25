class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles, curBottles = 0;
        while (true)
        {
            if (numBottles - numExchange < 0)
            {
                ans += curBottles;
                numBottles += curBottles;
                curBottles = 0;
            }
            curBottles++;
            numBottles -= numExchange;
            if (numBottles < 0)
                break;
        }
        return ans;
    }
};
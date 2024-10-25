class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int N = 2 * n - 2, x = time % N;
        return 1 + ((x < n) ? x : N - x);
    }
};
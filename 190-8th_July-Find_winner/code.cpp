class Solution
{
public:
    static int findTheWinner(int n, int k)
    {
        if (n == 1)
            return 1;
        return (findTheWinner(n - 1, k) + (k - 1)) % n + 1;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution
{
public:
    int minimumDeletions(string s)
    {
        vector<int> prefix_b(s.size() + 2, 0), suffix_a(s.size() + 2, 0);
        prefix_b[0] = 0;
        suffix_a[suffix_a.size() - 1] = 0;

        for (int i = 1; i < prefix_b.size() - 1; i++)
        {
            if (s[i - 1] == 'b')
            {
                prefix_b[i + 1] = prefix_b[i] + 1;
            }
            else
            {
                prefix_b[i + 1] = prefix_b[i] + 0;
            }
        }

        for (int i = s.size(); i >= 1; i--)
        {
            if (s[i - 1] == 'a')
            {
                suffix_a[i - 1] = suffix_a[i] + 1;
            }
            else
            {
                suffix_a[i - 1] = suffix_a[i] + 0;
            }
        }

        int mini = INT_MAX;

        for (int i = 0; i < s.size() + 2; i++)
        {
            mini = min(prefix_b[i] + suffix_a[i], mini);
        }

        return mini;
    }
};
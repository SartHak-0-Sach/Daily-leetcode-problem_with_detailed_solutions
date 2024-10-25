class Solution
{
public:
    static string reverseParentheses(string &s)
    {
        string stack, rev;
        for (char c : s)
        {
            if (c != ')')
                stack.push_back(c);
            else
            {
                rev = "";
                char r = stack.back();
                for (; r != '('; r = stack.back())
                {
                    rev += r;
                    stack.pop_back();
                }
                stack.pop_back();
                stack += rev;
            }
        }
        return stack;
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
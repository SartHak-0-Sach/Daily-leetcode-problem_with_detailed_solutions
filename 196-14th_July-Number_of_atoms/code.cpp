class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int n = formula.length();
        vector<int> mult(n, 1);
        stack<int> factors;
        int multFactor = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            char ch = formula[i];
            if (ch == ')')
            {
                string cnt = "";
                int k = i + 1;
                while (k < n && isdigit(formula[k]))
                {
                    cnt += formula[k++];
                }
                if (cnt == "")
                    cnt = "1";
                int digit = stoi(cnt);
                factors.push(digit);
                multFactor *= digit;
            }
            else if (ch == '(')
            {
                int digit = factors.top();
                factors.pop();
                multFactor /= digit;
            }
            else if (isupper(ch))
            {
                mult[i] = multFactor;
            }
            else
                continue;
        }
        map<string, int> res;
        for (int i = 0; i < n; ++i)
        {
            char ch = formula[i];
            if (!isupper(ch))
                continue;
            multFactor = mult[i];
            string ele = "";
            ele += ch;
            int j = i + 1;
            while (j < n && islower(formula[j]))
            {
                ele += formula[j++];
            }
            string cnt = "";
            int k = j;
            while (k < n && isdigit(formula[k]))
            {
                cnt += formula[k++];
            }
            if (cnt == "")
                cnt = "1";
            int digit = stoi(cnt);
            res[ele] += digit * multFactor;
            i = k - 1;
        }
        string ans = "";
        for (auto &[ele, digit] : res)
        {
            string cnt = to_string(digit);
            if (cnt == "1")
                cnt = "";
            ans += ele + cnt;
        }
        return ans;
    }
};
class Solution
{

public:
    int maximumGain(string s, int x, int y)
    {
        int points = 0;
        ;

        auto removePairs = [&](char first, char second, int point)
        {
            string newString;
            int tempPoints = 0;
            for (char ch : s)
            {
                if (!newString.empty() && newString.back() == first && ch == second)
                {
                    tempPoints += point;
                    newString.pop_back();
                }
                else
                {
                    newString.push_back(ch);
                }
            }
            s = newString;
            return tempPoints;
        };
        if (x > y)
        {
            points += removePairs('a', 'b', x);
            points += removePairs('b', 'a', y);
        }
        else
        {
            points += removePairs('b', 'a', y);
            points += removePairs('a', 'b', x);
        }
        return points;
    }
};
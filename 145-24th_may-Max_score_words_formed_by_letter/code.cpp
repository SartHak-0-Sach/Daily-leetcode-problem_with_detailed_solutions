#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        vector<int> cnt(26, 0);
        for (char c : l) cnt[c - 'a']++;
        return dfs(w, s, cnt, 0);
    }
    
private:
    int dfs(vector<string>& w, vector<int>& s, vector<int>& cnt, int i) {
        if (i == w.size()) return 0;
        int skip = dfs(w, s, cnt, i + 1), score = 0;
        bool valid = true;
        for (char c : w[i]) {
            if (--cnt[c - 'a'] < 0) valid = false;
            score += s[c - 'a'];
        }
        int take = valid ? score + dfs(w, s, cnt, i + 1) : 0;
        for (char c : w[i]) cnt[c - 'a']++;
        return max(skip, take);
    }
};
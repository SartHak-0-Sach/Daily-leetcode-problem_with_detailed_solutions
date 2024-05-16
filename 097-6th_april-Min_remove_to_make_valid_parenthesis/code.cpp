#include <iostream>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for(int i = s.length()-1; i>=0; i--) {
            if(s[i]==')')
                open++;
            if(s[i]=='(') {
                if(open==0)
                    s.erase(i, 1);
                else
                    open--;
            }
        }
        
        // Adjust the index when erasing characters
        for(int i = 0; i<s.length(); ) {
            if(open == 0)
                break;
            if(s[i] == ')') {
                s.erase(i, 1);
                open--;
            } else {
                i++;
            }
        }
        return s;
    }
};

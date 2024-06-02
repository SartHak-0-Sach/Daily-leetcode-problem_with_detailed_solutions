#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& str) {
       int s2=0;
  int e=str.size()-1;
  while(s2<e){
      swap(str[s2++],str[e--]);
  }
  //return str; 
    }
};
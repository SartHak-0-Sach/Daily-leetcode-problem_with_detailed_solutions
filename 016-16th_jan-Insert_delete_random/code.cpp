#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
   
    RandomizedSet() {
    }

    bool search(int val){

         if(mp.find(val)!=mp.end())
            return true;
         return false;

    }

    
    bool insert(int val) {

        if(search(val))
            return false;

        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }

    
    bool remove(int val) {

        if(!search(val))
            return false;

       
        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }

   
    int getRandom() {

        return v[rand()%v.size()];
    }
};
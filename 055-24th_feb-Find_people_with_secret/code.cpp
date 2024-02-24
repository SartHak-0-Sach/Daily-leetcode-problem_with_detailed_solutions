#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
        std::set<int> knownSet = {0, firstPerson};
        
        std::vector<std::vector<std::pair<int, int>>> sortedMeetings;
        std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[2] < b[2];
        });

        std::set<int> seenTime;
        
        for (const auto& meeting : meetings) {
            if (seenTime.find(meeting[2]) == seenTime.end()) {
                seenTime.insert(meeting[2]);
                sortedMeetings.push_back({});
            }
            sortedMeetings.back().push_back({meeting[0], meeting[1]});
        }

        for (const auto& meetingGroup : sortedMeetings) {
            std::set<int> peopleKnowSecret;
            std::unordered_map<int, std::vector<int>> graph;
            
            for (const auto& pair : meetingGroup) {
                graph[pair.first].push_back(pair.second);
                graph[pair.second].push_back(pair.first);
                
                if (knownSet.find(pair.first) != knownSet.end()) peopleKnowSecret.insert(pair.first);
                if (knownSet.find(pair.second) != knownSet.end()) peopleKnowSecret.insert(pair.second);
            }
            
            std::queue<int> queue;
            for (int person : peopleKnowSecret) queue.push(person);
        
            while (!queue.empty()) {
                int curr = queue.front();
                queue.pop();
                knownSet.insert(curr);
                for (int neigh : graph[curr]) {
                    if (knownSet.find(neigh) == knownSet.end()) {
                        knownSet.insert(neigh);
                        queue.push(neigh);
                    }
                }
            }
        }

        return std::vector<int>(knownSet.begin(), knownSet.end());
    }
};
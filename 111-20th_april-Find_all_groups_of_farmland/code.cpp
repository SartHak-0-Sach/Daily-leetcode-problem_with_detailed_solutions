#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();
        vector<vector<int>> result;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        set<pair<int, int>> visited;
        
        auto bfs = [&](int start_row, int start_col) -> vector<int> {
            queue<pair<int, int>> q;
            q.push({start_row, start_col});
            visited.insert({start_row, start_col});
            int min_row = start_row, min_col = start_col, max_row = start_row, max_col = start_col;
            
            while (!q.empty()) {
                auto [cur_row, cur_col] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int new_row = cur_row + dr;
                    int new_col = cur_col + dc;
                    
                    if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && visited.find({new_row, new_col}) == visited.end() && land[new_row][new_col] == 1) {
                        visited.insert({new_row, new_col});
                        q.push({new_row, new_col});
                        min_row = min(min_row, new_row);
                        min_col = min(min_col, new_col);
                        max_row = max(max_row, new_row);
                        max_col = max(max_col, new_col);
                    }
                }
            }
            
            return {min_row, min_col, max_row, max_col};
        };
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (land[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                    vector<int> farmland = bfs(i, j);
                    result.push_back(farmland);
                }
            }
        }
        
        return result;
    }
};
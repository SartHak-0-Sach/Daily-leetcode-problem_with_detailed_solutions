class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int prevRow = 0;
        int solution = 0;
        for (auto row : bank) {
            int sum = 0;
            for (auto c : row) {
                int temp = c - '0';
                sum += temp;
            }
            solution += sum * prevRow;
            prevRow = (sum == 0) * prevRow + sum;
        }
        return solution;
    }
};
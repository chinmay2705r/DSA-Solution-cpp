#include<iostream>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int curr_id = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                curr_id++;
            }
            component[i] = curr_id;
        }
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            answer.push_back(component[u] == component[v]);
        }
        
        return answer;
    }
};
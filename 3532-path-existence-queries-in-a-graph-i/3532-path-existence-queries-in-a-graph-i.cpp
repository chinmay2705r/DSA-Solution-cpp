class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Precalculate the connected components IDs
        vector<int> component(n, 0);
        int curr_id = 0;
        
        for (int i = 1; i < n; ++i) {
            // If the step to the next adjacent sorted element is too large, it breaks the path
            if (nums[i] - nums[i - 1] > maxDiff) {
                curr_id++;
            }
            component[i] = curr_id;
        }
        
        // Step 2: Answer each query in O(1) time
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            // Nodes can reach each other if and only if they belong to the same component segment
            answer.push_back(component[u] == component[v]);
        }
        
        return answer;
    }
};
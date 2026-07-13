class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeGroups = 0;

     
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            vector<int> currentGroup;
            queue<int> q;
            
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int person = q.front();
                q.pop();
                currentGroup.push_back(person); 
                for (int friendId : graph[person]) {
                    if (!visited[friendId]) {
                        visited[friendId] = true;
                        q.push(friendId);
                    }
                }
            }

            int groupSize = currentGroup.size();
            bool isPerfect = true;

            for (int person : currentGroup) {
                if (graph[person].size() != groupSize - 1) {
                    isPerfect = false;
                    break;
                }
            }

            if (isPerfect) {
                completeGroups++;
            }
        }

        return completeGroups;
    }
};
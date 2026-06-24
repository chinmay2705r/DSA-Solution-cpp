class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        
        long long MOD = 1e9 + 7;
        
        
        vector<long long> dpUp(r + 1, 0);
        vector<long long> dpDown(r + 1, 0);
        
        
        for (int j = l; j <= r; j++) {
            dpUp[j] = 1;
            dpDown[j] = 1;
        }
        
        
        for (int i = 2; i <= n; i++) {
            vector<long long> nextUp(r + 1, 0);
            vector<long long> nextDown(r + 1, 0);
            
            
            long long runningDownSum = 0;
            for (int j = l; j <= r; j++) {
                nextUp[j] = runningDownSum;
                runningDownSum = (runningDownSum + dpDown[j]) % MOD;
            }
            
            long long runningUpSum = 0;
            for (int j = r; j >= l; j--) {
                nextDown[j] = runningUpSum;
                runningUpSum = (runningUpSum + dpUp[j]) % MOD;
            }
            
            dpUp = move(nextUp);
            dpDown = move(nextDown);
        }
      
        long long totalCount = 0;
        for (int j = l; j <= r; j++) {
            totalCount = (totalCount + dpUp[j] + dpDown[j]) % MOD;
        }
        
        return totalCount;
    }
};
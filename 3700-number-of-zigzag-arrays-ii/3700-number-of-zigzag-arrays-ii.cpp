class Solution {
private:
    long long MOD = 1e9 + 7;

    // Standard matrix multiplication helper
    vector<vector<long long>> multiplyMatrices(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue; // Optimization skip for empty paths
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Binary exponentiation to calculate (Matrix^p) in O(log p) time
    vector<vector<long long>> powerMatrix(vector<vector<long long>> A, long long p) {
        int sz = A.size();
        vector<vector<long long>> result(sz, vector<long long>(sz, 0));
        
        // Initialize as Identity Matrix
        for (int i = 0; i < sz; i++) result[i][i] = 1;
        
        while (p > 0) {
            if (p % 2 == 1) {
                result = multiplyMatrices(result, A);
            }
            A = multiplyMatrices(A, A);
            p /= 2;
        }
        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int numValues = r - l + 1;
        
        // Base cases
        if (n == 1) return numValues;
        if (n == 2) return ((long long)numValues * (numValues - 1)) % MOD;

        // Total states = (number of values) * (2 directions: 0 = UP, 1 = DOWN)
        int totalStates = numValues * 2;

        // Transition matrix T where T[next_state][current_state] = 1 if valid step
        // Fixed the constructor initialization here:
        vector<vector<long long>> T(totalStates, vector<long long>(totalStates, 0));
        
        // Build the movement logic grid
        for (int currV = 0; currV < numValues; currV++) {
            for (int currD = 0; currD < 2; currD++) {
                int currState = currV * 2 + currD;
                
                for (int nextV = 0; nextV < numValues; nextV++) {
                    if (currV == nextV) continue; // Rule 1: No identical adjacent elements
                    
                    int nextD = (nextV > currV) ? 0 : 1; // 0 for UP, 1 for DOWN
                    
                    // Rule 2: Sequence must alternate direction (no 3 elements in same slope)
                    if (currD == nextD) continue; 
                    
                    int nextState = nextV * 2 + nextD;
                    T[nextState][currState] = 1; 
                }
            }
        }

        // Fast forward through remaining array slots (n - 2 operations)
        T = powerMatrix(T, n - 2);

        // Precompute total baseline combinations at array length 2
        vector<long long> baseStates(totalStates, 0);
        for (int i = 0; i < numValues; i++) {
            for (int j = 0; j < numValues; j++) {
                if (i == j) continue;
                int dir = (j > i) ? 0 : 1;
                baseStates[j * 2 + dir]++;
            }
        }

        // Multiply exponentiated transformation map against initial pairs
        long long totalCount = 0;
        for (int i = 0; i < totalStates; i++) {
            for (int j = 0; j < totalStates; j++) {
                totalCount = (totalCount + T[i][j] * baseStates[j]) % MOD;
            }
        }

        return totalCount;
    }
};
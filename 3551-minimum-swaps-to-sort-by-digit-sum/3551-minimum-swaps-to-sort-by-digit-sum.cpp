class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        vector<tuple<int, int, int>> elements(n);
        for (int i = 0; i < n; ++i) {
            elements[i] = {getDigitSum(nums[i]), nums[i], i};
        }
        
        sort(elements.begin(), elements.end());
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            int original_idx = get<2>(elements[i]);
            if (visited[i] || original_idx == i) {
                continue;
            }
            
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = get<2>(elements[curr]);
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};
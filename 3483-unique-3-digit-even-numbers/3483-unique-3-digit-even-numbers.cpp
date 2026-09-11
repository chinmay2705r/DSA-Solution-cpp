class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> available(10, 0);
        for (int d : digits) {
            available[d]++;
        }

        int count = 0;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100; 
            int d2 = (num / 10) % 10; 
            int d3 = num % 10;     

            vector<int> required(10, 0);
            required[d1]++;
            required[d2]++;
            required[d3]++;

            bool canForm = true;
            for (int i = 0; i < 10; ++i) {
                if (required[i] > available[i]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                count++;
            }
        }

        return count;
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        int totalNumbers = 1 << n;
        vector<int> result(totalNumbers);

        for(int i = 0; i < totalNumbers; ++i){
            result[i] = i ^ (i >> 1);
        }
        return result;

    }
};
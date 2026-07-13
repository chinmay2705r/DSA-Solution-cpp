class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;

        for(int l = 2; l <=9;++l){

            for(int start = 0; start <=9 - l;++ start){
                string sub = digits.substr(start,l);
                int  n = stoi(sub);

                if(n >= low && n <= high){
                    result.push_back(n);
                }
            }
        }
        return result;
        
    }
};
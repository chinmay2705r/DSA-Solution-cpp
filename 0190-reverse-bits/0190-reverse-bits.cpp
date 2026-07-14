class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;
        unsigned int unsigned_n = n;

        for(int i= 0;i<32;++i){
            ans<<=1;
            ans|= (unsigned_n & 1);
            unsigned_n >>=1;
        }
        return ans;
        
    }
};
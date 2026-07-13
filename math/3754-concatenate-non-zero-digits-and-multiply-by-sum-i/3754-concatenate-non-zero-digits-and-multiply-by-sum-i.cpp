class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n ==0) return 0;

        long long x = 0;
        long long digit_sum = 0;
        long long multiplier = 1;

        while(n>0){
            int digit = n % 10;

            if(digit!=0){
                x+= digit*multiplier;
                multiplier *= 10;
                digit_sum += digit;
            }
            n/=10;

        }
        return x * digit_sum;
        
    }
};
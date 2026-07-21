class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        int maxZeroGain = 0;
        int prevZeroLen = 0;

        int n = s.length();
        int i = 0;

        while(i<n){
            int j = i;
            while(j < n && s[j]==s[i]){
                j++;
            }

            int len = j - i;
            if(s[i] == '1'){
                totalOnes += len;
            }
            else{
               if (prevZeroLen > 0){
                maxZeroGain = max(maxZeroGain, prevZeroLen + len);
               }
               prevZeroLen = len;
            }
            i = j;
        }
        return totalOnes + maxZeroGain;
    }
};
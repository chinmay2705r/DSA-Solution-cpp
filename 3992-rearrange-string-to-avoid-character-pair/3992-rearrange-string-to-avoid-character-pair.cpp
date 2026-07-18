class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string others, xs, ys;
        for(char c:s){
            if(c==x) xs += c;
            else if(c==y) ys += c;
            else others +=c;
        }
        return others + ys + xs;
    }
};
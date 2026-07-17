#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        
       
        vector<int> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        vector<long long> cnt(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                cnt[i] += freq[j];
            }
        }
        vector<long long> gcd_count(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long total_pairs = (cnt[i] * (cnt[i] - 1)) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                total_pairs -= gcd_count[j];
            }
            gcd_count[i] = total_pairs;
        }
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            pref[i] = pref[i - 1] + gcd_count[i];
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(pref.begin(), pref.end(), q);
            ans.push_back(distance(pref.begin(), it));
        }
        
        return ans;
    }
};
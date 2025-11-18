class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sm = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        int res = 0;
        for(int i : nums) {
            sm += i;
            if(mp.find(sm - k) != mp.end()) res += mp[sm-k];
            mp[sm]++;
        }
        return res;
    }
};

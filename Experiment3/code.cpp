class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        map<int, int> mp;
        for(int i : arr) ++mp[i];
        vector<vector<int>> res;
        for(auto &p : mp) {
            res.push_back({p.first, p.second});
        }
        return res;
    }
};
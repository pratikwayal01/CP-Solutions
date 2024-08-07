class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>>mpp;
      for(auto x:strs){
        string element = x;
        sort(element.begin(),element.end());
        mpp[element].push_back(x);
      }
      vector <vector<string>> arr;
      for(auto pair : mpp){
        arr.push_back(pair.second);
      }
      return arr;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> tbl;
        vector<vector<string>> ans;
        
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            tbl[temp].push_back(strs[i]);
        }
        
        map<string,vector<string>>::iterator it = tbl.begin();
        for(it = tbl.begin(); it != tbl.end(); it++){
            ans.push_back(it->second);
        }
        
        return ans;
    }
};

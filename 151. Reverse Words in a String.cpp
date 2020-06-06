class Solution {
public:
    string reverseWords(string s) {
        string res;
        istringstream is(s);
        string word;
        vector<string> vec;
        while(is >> word){
            vec.push_back(word);
        }
        
        for(int i = vec.size() - 1; i >= 0 ; i--)
        {
            if(i == vec.size() - 1){
                res += vec[i];
            }
            else{
                res += " " + vec[i];
            }
        }
        
        return res;
    }
};
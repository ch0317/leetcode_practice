class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int len = s.size();
        string ip;
        if(s.size() < 4 || s.size() > 12)
            return ans;
        
        for(int i = 0; i < s.size() - 3; i++)
            for(int j = i + 1; j < s.size() - 2; j++)
                for(int k = j + 1; k < s.size() - 1; k++){
                cout << s.substr(0, i + 1) << "." << s.substr(i + 1, j - i) 
                << "."<< s.substr(j + 1, k - j) << "." << s.substr(k + 1, len - k - 1)<<endl;
                string part1 = s.substr(0, i + 1);
                string part2 = s.substr(i + 1, j - i);
                string part3 = s.substr(j + 1, k - j);
                string part4 = s.substr(k + 1, len - k - 1);

                if(isPartValid(part1) && isPartValid(part2) 
                   && isPartValid(part3) && isPartValid(part4)){
                    ip = part1 + "." + part2 + "." + part3 + "." + part4;
                    cout << ip << endl;
                    ans.push_back(ip);
                    }
                }
        return ans;
                    
    }
    
    bool isPartValid(const string & part){
        if(part.size() > 1 && part[0] == '0')
            return false;
        if(stoi(part) <= 255 && stoi(part) >= 0)
            return true;
        else
            return false;
    }
};
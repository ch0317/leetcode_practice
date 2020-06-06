class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        stack<string, vector<string>> st(vec);
        istringstream is(path);
        string s;
        string res;
        while(getline(is, s, '/')) {
            if(s != "." && s != ".." && s != ""){
                st.push(s);
                cout <<"push: " << s << endl;
            }

            if(s == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        
        if(st.empty()){
            res = "/"; 
        }
        
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res;
    }
};
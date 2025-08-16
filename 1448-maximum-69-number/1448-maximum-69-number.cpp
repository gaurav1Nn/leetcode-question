class Solution {
public:
    int maximum69Number (int num) 
    {
        string s = to_string(num);
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '6'){
                string temp = s;
                temp[i] = '9';
                ans.push_back(stoi(temp));
            }
        }
        if(!ans.empty()) return *max_element(ans.begin(), ans.end());
        return num;
    }
};

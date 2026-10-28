class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";

        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            string s = strs[i];
            int index = 0;

            while (index < ans.size() && index < s.size() && ans[index] == s[index]) {
                index++;
            }

            ans = ans.substr(0, index);

            if (ans.empty()) return "";
        }

        return ans;
    }
};
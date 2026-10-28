class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count = 0;

        int ans = 0;

        int check = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                count++;
                check = count;
            }else{
                count = 0;
            }
            
            ans = check;
        }

        return ans;
    }
};
class Solution {
public:
    char repeatedCharacter(string s) {
        
        char ans = '\0';

        unordered_map<char,int> mpp;

        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            if(mpp[s[i]]>1){
                ans=s[i];
                break;
            }
            
        }

        // for(int i=0;i<s.size();i++){
        //     if(mpp[s[i]]==2){
        //         ans=s[i];
        //         break;
        //     }
        // }

        return ans;
    }
};
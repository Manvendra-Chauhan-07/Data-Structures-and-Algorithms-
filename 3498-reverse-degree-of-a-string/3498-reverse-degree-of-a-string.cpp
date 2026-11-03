class Solution {
public:
    int reverseDegree(string s) {
        
        int total = 0;

        for(int i=0;i<s.size();i++){

            int value = 26 - (s[i]-'a');
            total = total + ((i+1)*value);
        }

        return total;

    }
};
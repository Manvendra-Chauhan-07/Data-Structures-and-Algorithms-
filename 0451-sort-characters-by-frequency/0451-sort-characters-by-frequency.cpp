class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mpp;

        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        
        priority_queue<pair<int,char>> q;

        for( auto &it : mpp){
            q.push({it.second,it.first});
        }

        string ans = "";

        while(!q.empty()){

            auto top = q.top();
            q.pop();
            
            char topChar = top.second;
            int value = top.first;

            //Using '+' for concatenate will cause Memory Limit Exceeded.
            
            ans.append(value, topChar);
        }

        return ans;
    }
};
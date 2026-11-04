class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        map<int,string> mpp;

        for(int i=0;i<names.size();i++){
            mpp[heights[i]]=names[i];
        }

        vector<string> ans;

        while(!mpp.empty()){
            ans.push_back(mpp.begin()->second);
            mpp.erase(mpp.begin());
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};
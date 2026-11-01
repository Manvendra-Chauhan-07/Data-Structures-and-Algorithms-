class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> mpp;

        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }

        vector<pair<string,int>> arr;

        for(auto &it : mpp){
            arr.push_back({it.first,it.second});
        }

        auto lambda = [](pair<string,int>& p1, pair<string,int>&p2){
            if(p1.second==p2.second){
                return p1.first<p2.first;
            }
            return p1.second>p2.second;
        };

        sort(arr.begin(),arr.end(),lambda);

        vector<string> ans(k);
        int i=0;

        while(k){
            ans[i]=arr[i].first;
            i++;
            k--;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int ,int> mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>> q;

        for(auto &it : mpp){
            q.push({it.second,it.first});
        }

        vector<int> ans;

        while(!q.empty() && k){

            auto top = q.top();
            q.pop();

            ans.push_back(top.second);
            k--;
        }


        return ans;
    }
};
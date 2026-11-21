class Solution {
public:

    void sub(int index, int n,  set<vector<int>> &set, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans){

        if(index==n){
            if(set.find(arr)==set.end()){
                set.insert(arr);
                ans.push_back(arr);
                return;
            }
            return;
        }

        arr.push_back(nums[index]);
        sub(index+1,n,set,nums,arr,ans);
        arr.pop_back();
        sub(index+1,n,set,nums,arr,ans);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        set<vector<int>> s;

        vector<vector<int>> ans;
        vector<int> arr;

        int n = nums.size();

        sub(0,n,s,nums,arr,ans);

        return ans;
    }
};
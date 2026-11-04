class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int size = nums.size();

        vector<int> ans;

        int start=0;
        int mid=n;

        int i = 0;

        while(start<n || mid<size){
            if(i%2==0){
                ans.push_back(nums[start]);
                start++;
            }else{
                ans.push_back(nums[mid]);
                mid++;
            }
            i++;
        }

        return ans;

    }
};
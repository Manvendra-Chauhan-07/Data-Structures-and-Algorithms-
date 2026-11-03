class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int n = nums.size();

        int pairs = n/2;

        map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        int count = 0;

        for(auto it=mpp.begin(); it!=mpp.end(); it++){

            if(it->second%2!=0){
                return false;
            }
        }

        return true;
    }
};
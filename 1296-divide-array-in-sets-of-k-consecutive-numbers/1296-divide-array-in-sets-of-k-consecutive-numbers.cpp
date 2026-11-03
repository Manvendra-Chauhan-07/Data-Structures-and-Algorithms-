class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(n%k!=0){
            return false;
        }


        map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }


        while(!mpp.empty()){

            int top = mpp.begin()->first;

            for(int j=0;j<k;j++){

                if(mpp[top+j]==0){
                    return false;
                }

                mpp[top+j]--;

                if(mpp[top+j]<1){
                    mpp.erase(top+j);
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if(n%groupSize!=0){
            return false;
        }

        map<int, int> mpp;

        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }

        while(!mpp.empty()){

            int top = mpp.begin()->first;

            for(int j=0;j<groupSize;j++){

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
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> q;

        for(int i=0;i<gifts.size();i++){
            q.push(gifts[i]);
        }

        while(!q.empty() && k){
            
            long long value = q.top();
            q.pop();

            q.push(int(sqrt(value)));

            k--;
        }

        long long ans=0;

        while(!q.empty()){
            ans=ans+q.top();
            q.pop();
        }

        return ans;
    }
};
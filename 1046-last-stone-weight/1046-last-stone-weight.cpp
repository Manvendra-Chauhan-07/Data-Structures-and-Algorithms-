class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> q;

        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }

        int value=0;
        
        while(!q.empty()){

            if(q.size()==1){
                return q.top();
            }

            int x=q.top();
            q.pop();

            int y=q.top();
            q.pop();

            if(x==y){
                continue;
            }
            else{
                value=x-y;
            }

            q.push(value);
        }

        return 0;
    }
};
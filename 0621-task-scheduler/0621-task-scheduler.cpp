class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int time=0;
        vector<int>freq(26);
        
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        
        
        //count - time
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<26;i++){
            if(freq[i]>=1){
                pq.push({freq[i],0});
            }
        }
        
        queue<pair<int,int>>q;
        
        while(!pq.empty() || !q.empty()){
            
            
            if(!q.empty() && time-q.front().second>n){
                pair<int,int>temp=q.front();
                q.pop();
                pq.push(temp);
            }
            
            if(!pq.empty()){
            int count=pq.top().first;
            int t=pq.top().second;
                pq.pop();
            count--;
            if(count>0){
                q.push({count,time});
            }
        }
            time++;
            
        }
        return time;
    }
};
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        
        int i=0;
        int n=tickets.size();
        while(true){
            
            if(tickets[k]==0){
                break;
            }
            if(tickets[i%n]!=0){
                tickets[i%n]-=1;
                time++;
            }
            
            i++;
            
        }
        return time;
    }
};
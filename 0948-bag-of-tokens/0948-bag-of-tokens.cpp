class Solution {
public:
   
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int l=0;
        int h=tokens.size()-1;
        int score=0;
        int maxscore=0;
        while(l<=h){
            if(power>=tokens[l]){
                power-=tokens[l];
                score+=1;
                maxscore=max(maxscore,score);
                l++;
            }
            else if(power<tokens[l] && score>=1){
                power+=tokens[h];
                score--;
                h--;
            }
            else{
                break;
            }
        }
        return maxscore;
        
    }
};
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
//         int count=0;
//         while(start!=0 || goal !=0){
//             if((start & 1)!=(goal&1)){
//                 count++;
//             }
            
//             start=start>>1;
//             goal=goal>>1;
//         }
//         return count;
        
        int num=start^goal;
        int count=0;
        while(num!=0){
            num=num&(num-1);
            count++;
        }
        return count;
        
        
    }
};
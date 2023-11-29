class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t count=0;
         uint32_t mask=1;
        for(int i=0;i<32;i++){
        if(n & mask)count++;
            n=n>>1;
            
        }
        return count;
        
      
    }
};
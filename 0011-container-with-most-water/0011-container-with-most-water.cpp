class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int area;
        int max_area=0;
        while(start<end){
            area=min(height[start],height[end])*(end-start);
            max_area=max(area,max_area);
            if(min(height[start],height[end])==height[start]){
                start++;
            }
            else{
                end--;
            }
            
        }
        return max_area;
    }
};
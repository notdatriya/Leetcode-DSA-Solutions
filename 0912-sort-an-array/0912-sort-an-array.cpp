class Solution {
public:
      void heapify(vector<int>& heap,int n,int i){
int largest=i;
int left=2*i+1;
int right=2*i+2;
if(left<n && heap[left]>heap[largest]){
    largest=left;
}
if(right<n && heap[right]>heap[largest]){
    largest=right;
}

if(largest!=i){
    swap(heap[largest],heap[i]);
    heapify(heap,n,largest);
}
}
    void build_heap(vector<int>&nums){
        int n=nums.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapify(nums,n,i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        build_heap(nums);
        while(n>0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,n,0);
        }
        return nums;
    }
};
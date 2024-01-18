class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
//         vector<int>arr;
        
//         int n1=nums1.size();
//         int n2=nums2.size();
        
//         int i=0;int j=0;
//         while(i<n1 && j<n2){
//             if(nums1[i]<nums2[j]){
//                 arr.push_back(nums1[i++]);
//             }
//             else arr.push_back(nums2[j++]);
//         }
        
//         while(i<n1)arr.push_back(nums1[i++]);
//         while(j<n2)arr.push_back(nums2[j++]);
        
//         int n=n1+n2;
//         if(n%2==1){
//             return arr[n/2];
//         }
//         else{
//             return (double)((double)(arr[n/2]) + (double)(arr[n/2 -1]))/2.0;
//         }
        
        
        //m-2
        
        
        int n1=nums1.size();
        int n2=nums2.size();
                 int n=n1+n2;

        int ind2=n/2;
        int ind1=ind2-1;
        int ind1el=-1;
        int ind2el=-1;
        int count=0;
        
        int i=0;int j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count==ind1)ind1el=nums1[i];
                if(count==ind2)ind2el=nums1[i];
                count++;
                i++;
            }
            else{
                if(count==ind1)ind1el=nums2[j];
                if(count==ind2)ind2el=nums2[j];
                count++;
                j++;
            }
        }
        
        while(i<n1){
            if(count==ind1)ind1el=nums1[i];
                if(count==ind2)ind2el=nums1[i];
                count++;
                i++;
        }
        while(j<n2){
            if(count==ind1)ind1el=nums2[j];
                if(count==ind2)ind2el=nums2[j];
                count++;
                j++;
        }
        
       
        if(n%2==1){
            return ind2el;
        }
        else{
            return (double)((double)(ind1el +ind2el))/2.0;
        }
    }
};
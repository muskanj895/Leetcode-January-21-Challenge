class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int k=0;
    
        int temp[1000005];
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            temp[k++]=nums1[i++];
        }
        else
            temp[k++]=nums2[j++];}
        while(i<m)
        {
            temp[k++]=nums1[i++];
        }
        while(j<n)
        {
            temp[k++]=nums2[j++];
        }
        for(int i=0;i<(m+n);i++)
        {
            nums1[i]=temp[i];
        }
        
    }
};

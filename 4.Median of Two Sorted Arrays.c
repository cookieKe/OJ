double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len1=0;
    int len2=0;
    int *nums3=NULL;
    int total_len=0;
    int len=0;
    
    total_len = nums1Size+nums2Size;
    nums3=(int*)malloc(sizeof(int)*total_len);
    
    while(len1<nums1Size || len2<nums2Size)
    {
        if(len1 == nums1Size)
        {
            nums3[len++]=nums2[len2++];
            continue;
        }
        if(len2 == nums2Size)
        {
            nums3[len++]=nums1[len1++];
            continue;
        }
        if(nums1[len1]<nums2[len2])
        {
            nums3[len++]=nums1[len1++];
        }
        else
        {
            nums3[len++]=nums2[len2++];
        }
        if(len == total_len/2+1)
        {
            break;
        }
    }
    
    int half = total_len/2;
    double res = ((total_len%2==0)?(nums3[half]+nums3[half-1])/2.0:nums3[total_len/2]);
    return res;
}
#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergedSize = nums1Size + nums2Size;
    double median;
    if (mergedSize%2) {
        int sum = 0;
        if ((mergedSize-1)/2 < nums1Size) { 
            sum += nums1[(mergedSize-1)/2];
            if ((mergedSize-1)/2 + 1 < nums1Size) sum+=nums1[(mergedSize-1)/2 + 1];
            else sum+=nums2[(mergedSize-1)/2+1-nums1Size];
        }
        else sum = nums2[(mergedSize-1)/2] + nums2[(mergedSize - 1)/2 + 1];
        median = sum/2.0;        
    }
    else {
        if ((mergedSize-1)/2 < nums1Size) median = (double)nums1[(mergedSize-1)/2];
        else median = (double)nums2[(mergedSize-1)/2-nums1Size];
    }
    return median;
}
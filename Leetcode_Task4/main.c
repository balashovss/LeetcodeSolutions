#include <stdio.h>
#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mergedSize = nums1Size + nums2Size;
    int number_of_tries, flag = 0;
    double median;
    if (mergedSize%2) number_of_tries = (mergedSize)/2+1;
    else {
        number_of_tries = (mergedSize+1)/2;
        flag = 1;
    }
    int* p1 = nums1;
    int* p2 = nums2;
    int *fin = NULL;
    if (!flag) {
    for (int i = 0; i < number_of_tries;i++) {
        if ((p1!=NULL) && (p1 <= nums1+nums1Size-1)){
            if ((p2!=NULL) && (p2 <= nums2+nums2Size-1)) {
                if (*p1 >= *p2) {
                    fin = p2;
                    p2++;
                }
                else {
                    fin = p1;
                    p1++;
                }
            }
            else {
                fin = p1;
                p1++;
            }
        }
        else {
            fin = p2;
            p2++;
        } 
    }
    median = (double)(*fin);
    }
    else {
        for (int i = 0; i < number_of_tries;i++) {
        if ((p1!=NULL) && (p1 <= nums1+nums1Size-1)) {
            if ((p2!=NULL) && (p2 <= nums2+nums2Size-1)) {
                if (*p1 >= *p2) {
                    fin = p2;
                    p2++;
                }
                else {
                    fin = p1;
                    p1++;
                }
            }
            else {
                fin = p1;
                p1++;
            }
        }
        else {
            fin = p2;
            p2++;
        } 
    }
    int *cur;
    if ((p1 != NULL) && (p1 <= nums1+nums1Size-1)) {
        if ((p2 != NULL) && (p2 <= nums2+nums2Size-1)) {
            if (*p1 >= *p2) cur = p2;
            else cur = p1;
        }
        else cur = p1;
    }
    else cur = p2;
    median = (*fin + *cur)/2.0;
    }
    return median;
}
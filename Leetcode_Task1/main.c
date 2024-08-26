#include <stdlib.h>
#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*2);
    int flag = 1;
    for (int i = 0; i < numsSize && flag; i++) {
        for (int j = i+1; j < numsSize && flag; j++) {
            if (nums[i] + nums[j] == target) {
                flag = 0;
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
            }
        }
    }
    return result;
}
int main() {
    int* sumIndices;
    int numsSize, returnSize = 2, target;
    scanf("%d", &numsSize);
    int* nums = (int*)malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d",nums+i);
    }
    scanf("%d", &target);
    sumIndices = twoSum(nums, numsSize, target, &returnSize);
    free(nums);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ",sumIndices[i]);
    }
    free(sumIndices);
    return 0;
}
#include <string.h>
int isPalindrome(char* s, int i, int j) {
    int left = i, right = j, isP = 1;
    while ((left < right) && isP) {
        if (s[left] != s[right]) isP = 0;
        left++;
        right--;
    }
    return isP;
}
char* longestPalindrome(char* s) {
    int flag = 1, left, right;
    for (int i = 0; ((i < strlen(s)) && flag); i++) {
        for (int j = strlen(s); ((j > i) && flag); j--) {
            if (isPalindrome(s,i,j)) {
                flag = 0;
                left = i;
                right = j;
            }
        }
    }
    char *ret = strndup(s+left,right-left);
    return ret;
}

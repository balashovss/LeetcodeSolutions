#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50000
int lengthOfLongestSubstring(char* s) {
    int i = 0, j = 0, max = 0;
    char temp_str[MAX_LEN] = {'\0'};
    while (s[i] != '\0') {
        if (!(strchr(temp_str,s[i]))) {
            temp_str[j] = s[i];
            j++;
            printf("%d\n",i);
            i++;
        }
        else {
            if (j >= max) max = j;
            int len = j;
            while ((j != -1) && (s[i] != temp_str[j])) {
                temp_str[j] = '\0';
                j--;
            }
            i = i - (len-j-1);
            while (j != 0) {
                temp_str[j] = '\0';
                j--;
            }
            temp_str[j] = 0;
            printf("%d\n", i);
        }  
    }
    if (j >= max) {
        max = j;
    }
    return max;
}
int main() {
    char string[MAX_LEN];
    scanf("%s",string);
    printf("%d", lengthOfLongestSubstring(string));
    return 0;
}
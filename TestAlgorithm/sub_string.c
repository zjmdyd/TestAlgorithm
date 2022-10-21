//
//  sub_string.c
//  TestAlgorithm
//
//  Created by issuser on 2022/10/17.
//

#include "sub_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char *s) {
    size_t len = strlen(s);
    printf("len = %zd, size = %zd\n", len, sizeof(char)*len);
    size_t maxLen = 0;
    for (int i = 0; i < len; i++) {
        char *des1 = malloc(sizeof(char)*len);
        int markLen = 0;
        for (int j = i; j < len; j++) {
            char ch = s[j];
            printf("第%d次遍历,遍历到的字符:j = %d, ch = %c\n", i, j, ch);
            if (j == i) {
                des1[j-i] = s[j];
                markLen++;
                printf("des[%d] = %c\n", j-i, ch);
            }else {
                int nextLen = j - i;
                bool hasMatch = false;
                
                while (nextLen > 0) {
                    if (ch != des1[nextLen-1]) {
                        nextLen--;
                    }else {
                        hasMatch = true;
                        break;
                    }
                }
                if (hasMatch) {
                    printf("遇到重复字符串:j = %d, ch = %c\n", j, ch);
                    break;
                }else {
                    des1[j-i] = ch;
                    markLen++;
                    printf("des[%d] = %c\n", j-i, ch);
                }
            }
        }
        if (markLen > maxLen) {
            maxLen = markLen;
        }
        printf("des1.len = %zd\n", strlen(des1));
        printf("\n");
    }
    printf("最长子串len = %zd\n", maxLen);
    
    return 0;
}

int max(int x, int y) {
    if (x > y) {
        return x;
    }
    
    return y;
}

int lengthOfLongestSubstring2(char *s) {
    size_t len = strlen(s);
    printf("len = %zd, size = %zd\n", len, sizeof(char)*len);
    
    char *des1 = malloc(sizeof(char)*len);
    int maxLen = 0;
    int lk = 0;

    for (int i = 0; i < len; i++) {
        if (i != 0) {
            lk++;
        }
        des1[0] = s[i];
        int rk = lk;
        printf("des[0] = %c, i = %d\n", s[i], i);
        while (rk + 1 < len) {
            int nextIndex = rk + 1;
            char ch = s[nextIndex];
            bool hasMatch = false;
            while (nextIndex > i) {
                char before = des1[nextIndex-i-1];
                if (ch != before) {
                    nextIndex--;
                }else {
                    hasMatch = true;
                    break;
                }
            }
            
            if (!hasMatch) {
                rk++;
                des1[rk-i] = ch;
                printf("des[%d] = %c, i = %d\n", rk-i, ch, i);
            }else {
                printf("遇到重复字符串:i = %d, ch = %c, rk = %d\n", i, ch, rk+1);
                break;
            }
        }
        maxLen = max(maxLen, rk - lk + 1);
        
        printf("\n");
    }
    
    printf("最长子串len = %d\n", maxLen);
    
    return 0;
}

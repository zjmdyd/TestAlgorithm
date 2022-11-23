//
//  testCC.c
//  TestC
//
//  Created by issuser on 2021/12/28.
//

#include <stdio.h>
#include <stdbool.h>

void test(void) {
    // insert code here...
    
    int n;  // 计算机总台数
    int m;  // 可互相通信的计算机对数
    int q;  // 查询次数(查询给定的两台计算机编号能否相互通信)
    printf("请输入不超过1000的3个正整数(用空格分隔):");
    scanf("%d %d %d", &n, &m, &q);
    printf("n = %d, m = %d, q = %d\n", n, m, q);
    
    int maxSubAryCount = 500;   // 最多500对两两相互能通信
    int maxElementLen = 1000;   // 最少一个分组，一个分组内最多1000个编号能相互能通信
    int ary[maxSubAryCount][maxElementLen];
    int subAryIndex = -1;        // 子数组的游标
    int subAryElementCounts[maxElementLen]; // 子数组的元素个数
    
    // 为可通信的计算机对数赋值
    for (int i = 0; i < m; i++) {
        int a, b;
        printf("请输入可相互通信的两台计算机编号:");
        scanf("%d %d", &a, &b);
        if (subAryIndex == -1) { // 第一次
            subAryIndex++;
            ary[subAryIndex][0] = a;
            ary[subAryIndex][1] = b;
            subAryElementCounts[subAryIndex] = 2;
        }else {
            bool hasMatch = false;
            for (int j = 0; j < subAryIndex + 1; j++) {
                bool subAryHas_a = false, subAryHas_b = false;      // 判断子数组中是否存在用户该次输入的两个编号

                int elementCount = subAryElementCounts[j];
                printf("elementCount_%d = %d\n", j, elementCount);
                
                for (int tt = 0; tt < elementCount; tt++) {
                    printf("subAry[%d][%d] = %d\n", j, tt, ary[j][tt]);
                }
                
                for (int k = 0; k < elementCount; k++) {
                    int temp = ary[j][k];
                    if (temp == a) {        // 子数组中已有该电脑编号
                        subAryHas_a = true;
                    }
                    if (temp == b) {        // 子数组中已有该电脑编号
                        subAryHas_b = true;
                    }
                }
                
                if (subAryHas_a && subAryHas_b) {       // 子数组包含该次输入的两个编号
                    hasMatch = true;
                    break;
                }else if (subAryHas_a || subAryHas_b) { // 子数组包含该次输入中的某1个编号
                    hasMatch = true;                    // 匹配到可相互通信的子数组
                    if (subAryHas_a) {
                        ary[j][elementCount] = b;
                    }else {
                        ary[j][elementCount] = a;
                    }
                    subAryElementCounts[j] = elementCount + 1;  // 子数组元素个数加1
                }
            }
            
            if (hasMatch == false) {    // 所有子数组中没有该次输入的两个编号
                subAryIndex++;
                ary[subAryIndex][0] = a;
                ary[subAryIndex][1] = b;
                subAryElementCounts[subAryIndex] = 2;
            }
        }
    }
    
    printf("\n");
    printf("合并可互相通信权限前的数组\n");
    printf("subAryIndex = %d\n", subAryIndex);
    
    for (int i = 0; i < subAryIndex + 1; i++) {
        int elementCount = subAryElementCounts[i];
        printf("elementCount_%d = %d\n", i, elementCount);
        for (int j = 0; j < elementCount; j++) {
            printf("a[%d][%d] = %d  ", i, j, ary[i][j]);
        }
        printf("\n");
    }
    
    // 查询q次
    for (int i = 0; i < q; i++) {
        int s, t;
        printf("请输入待查询的两台计算机编号:");
        scanf("%d %d", &s, &t);
        bool hasMatch = false;
        for (int j = 0; j < subAryIndex + 1; j++) {
            bool subAryHas_a = false, subAryHas_b = false;      // 判断子数组中是否存在用户该次输入的两个编号
            int elementCount = subAryElementCounts[j];
            
            for (int k = 0; k < elementCount; k++) {
                int temp = ary[j][k];
                if (temp == s) {        // 子数组中已有该电脑编号
                    subAryHas_a = true;
                }
                if (temp == t) {        // 子数组中已有该电脑编号
                    subAryHas_b = true;
                }
            }
            if (subAryHas_a && subAryHas_b) {   // 如果子数组里面包含查询的两个编号则两台计算机可通信
                hasMatch = true;
                break;
            }
        }

        printf("编号为%d和%d的两台计算机能否互相通信的查询的结果:%d\n", s, t, hasMatch);
    }
}

void test2 (void) {
    int n;  // 计算机总台数
    int m;  // 可互相通信的计算机对数
    int q;  // 查询次数(查询给定的两台计算机能否相互通信)
    printf("请输入不超过1000的3个正整数(用空格分隔):");
    scanf("%d %d %d", &n, &m, &q);
    printf("n = %d, m = %d, q = %d\n", n, m, q);
    
    int maxSubAryCount = 500;   // 最多500对两两相互能通信
    int maxElementLen = 1000;   // 最少一个分组，一个分组内最多1000个编号能相互能通信
    int ary[maxSubAryCount][maxElementLen];
    int subAryIndex = -1;        // 子数组的游标
    int subAryElementCounts[maxElementLen]; // 用数组存放子数组的有效元素个数
    
    // 为可通信的计算机对数赋值
    for (int i = 0; i < m; i++) {
        int a, b;
        printf("请输入可相互通信的两台计算机编号:");
        scanf("%d %d", &a, &b);
        if (subAryIndex == -1) { // 第一次
            subAryIndex++;
            ary[subAryIndex][0] = a;
            ary[subAryIndex][1] = b;
            subAryElementCounts[subAryIndex] = 2;
        }else {
            int matchSubAryTimes = 0;
            int matchSubAryIndexs[2];   // 一次用户输入的匹配操作，最多只会重复匹配两次
            for (int j = 0; j < subAryIndex + 1; j++) {
                bool subAryHas_a = false, subAryHas_b = false;      // 判断子数组中是否存在用户该次输入的两个编号

                int elementCount = subAryElementCounts[j];
                printf("elementCount_%d = %d\n", j, elementCount);
                
                for (int tt = 0; tt < elementCount; tt++) {
                    printf("subAry[%d][%d] = %d\n", j, tt, ary[j][tt]);
                }
                
                for (int k = 0; k < elementCount; k++) {
                    int temp = ary[j][k];
                    if (temp == a) {        // 子数组中已有该电脑编号
                        subAryHas_a = true;
                    }
                    if (temp == b) {        // 子数组中已有该电脑编号
                        subAryHas_b = true;
                    }
                }
                
                if (subAryHas_a && subAryHas_b) {       // 子数组包含该次输入的两个编号
                    matchSubAryTimes++;
                    break;
                }else if (subAryHas_a || subAryHas_b) { // 子数组包含该次输入中的某1个编号
                    if (subAryHas_a) {
                        ary[j][elementCount] = b;
                    }else {
                        ary[j][elementCount] = a;
                    }
                    subAryElementCounts[j] = elementCount + 1;  // 子数组元素个数加1
                    matchSubAryIndexs[matchSubAryTimes] = j;
                    matchSubAryTimes++;                 // 匹配到可相互通信的子数组
                }
            }
            
            if (matchSubAryTimes == 0) {    // 所有子数组中没有该次输入的两个编号
                subAryIndex++;
                ary[subAryIndex][0] = a;
                ary[subAryIndex][1] = b;
                subAryElementCounts[subAryIndex] = 2;
            }else if (matchSubAryTimes > 1) {
                printf("出现两次匹配成功\n");
                
                int idx0 = matchSubAryIndexs[0]; // 匹配到的第一个数组下标
                int idx1 = matchSubAryIndexs[1]; // 匹配到的第二个数组下标
                
                int elementCount0 = subAryElementCounts[idx0];
                int elementCount1 = subAryElementCounts[idx1];
                printf("idx0 = %d, idx1 = %d\n", idx0, idx1);
                printf("elementCount0 = %d, elementCount1 = %d\n", elementCount0, elementCount1);
                int tempValueAry[maxElementLen];
                int newAddCount = 0;
                for (int v = 0; v < elementCount1; v++) {
                    bool has_value = false;
                    
                    int value = ary[idx1][v];
                    
                    // 判断第一个数组是否包含第二个数组中的元素，未包含则加入
                    for (int w = 0; w < elementCount0; w++) {
                        int tt = ary[idx0][w];
                        printf("value = %d, tt = %d\n", value, tt);
                        if (value == tt) {
                            has_value = true;
                            break;
                        }
                    }
                    if (!has_value) {
                        printf("未包含的值为:%d\n", value);
                        tempValueAry[newAddCount] = value;
                        newAddCount++;
                    }
                }
                
                for (int addIdx = 0; addIdx < newAddCount; addIdx++) {
                    ary[idx0][elementCount0+addIdx] = tempValueAry[addIdx];
                }
                subAryElementCounts[idx0] = elementCount0 + newAddCount;        // 修改子数组元素个数
                for (int r = 0; r < elementCount1; r++) {
                    ary[idx1][r] = 0;
                }
            }
        }
    }
    
    printf("\n");
    printf("subAryIndex = %d\n", subAryIndex);
    
    for (int i = 0; i < subAryIndex + 1; i++) {
        int elementCount = subAryElementCounts[i];
        printf("elementCount_%d = %d\n", i, elementCount);
        for (int j = 0; j < elementCount; j++) {
            printf("a[%d][%d] = %d  ", i, j, ary[i][j]);
        }
        printf("\n");
    }
    
    // 查询q次
    for (int i = 0; i < q; i++) {
        int s, t;
        printf("请输入待查询的两台计算机编号:");
        scanf("%d %d", &s, &t);
        bool hasMatch = false;
        for (int j = 0; j < subAryIndex + 1; j++) {
            bool subAryHas_a = false, subAryHas_b = false;      // 判断子数组中是否存在用户该次输入的两个编号
            int elementCount = subAryElementCounts[j];
            
            for (int k = 0; k < elementCount; k++) {
                int temp = ary[j][k];
                if (temp == s) {        // 子数组中已有该电脑编号
                    subAryHas_a = true;
                }
                if (temp == t) {        // 子数组中已有该电脑编号
                    subAryHas_b = true;
                }
            }
            if (subAryHas_a && subAryHas_b) {   // 如果子数组里面包含查询的两个编号则两台计算机可通信
                hasMatch = true;
                break;
            }
        }

        printf("编号为%d和%d的两台计算机能否互相通信的查询的结果:%d\n", s, t, hasMatch);
    }
}

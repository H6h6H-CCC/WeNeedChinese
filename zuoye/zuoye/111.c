#include <stdio.h>

// ================== 2. 百钱百鸡问题 ==================
void hundred_chickens() {
    printf("\n========== 百钱百鸡问题 ==========\n");
    printf("公鸡5文/只，母鸡3文/只，小鸡1文3只，100文买100只\n");
    printf("所有可能的解（公鸡, 母鸡, 小鸡）：\n");
    int gong, mu, xiao;
    int count = 0;
    for (gong = 0; gong <= 20; gong++) {          // 公鸡最多20只
        for (mu = 0; mu <= 33; mu++) {            // 母鸡最多33只
            xiao = 100 - gong - mu;
            if (xiao >= 0 && xiao % 3 == 0) {     // 小鸡数量必须是3的倍数
                if (5 * gong + 3 * mu + xiao / 3 == 100) {
                    printf("  公鸡: %2d, 母鸡: %2d, 小鸡: %2d\n", gong, mu, xiao);
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        printf("  无解\n");
    } else {
        printf("共 %d 组解\n", count);
    }
}

// ================== 3. 斐波那契数列前20项 ==================
void fibonacci() {
    printf("\n========== 斐波那契数列前20项 ==========\n");
    long long f1 = 1, f2 = 1;
    printf("第1项: %lld\n", f1);
    if (20 >= 2) printf("第2项: %lld\n", f2);
    for (int i = 3; i <= 20; i++) {
        long long next = f1 + f2;
        printf("第%2d项: %lld\n", i, next);
        f1 = f2;
        f2 = next;
    }
}

// ================== 主函数 ==================
int main() {
    int choice;
    while (1) {
        printf("\n****************************************\n");
        printf("  请选择功能：\n");
        printf("  1 - 求解百钱百鸡问题\n");
        printf("  2 - 打印斐波那契数列前20项\n");
        printf("  0 - 退出程序\n");
        printf("****************************************\n");
        printf("请输入数字: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: hundred_chickens(); break;
            case 2: fibonacci(); break;
            case 0: printf("程序结束。\n"); return 0;
            default: printf("无效选项，请重新输入！\n");
        }
    }
    return 0;
}
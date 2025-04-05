#include <stdio.h>
#include <stdlib.h>

// 分区函数
int partition(int *a, int left, int right) {
    int pivot = a[right]; // 选择最右边的元素作为基准值
    int i = left - 1;     // i 指向小于等于 pivot 的区域的最后一个元素

    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            // 交换 a[i] 和 a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // 将 pivot 放到正确位置
    int temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;

    return i + 1; // 返回 pivot 的最终位置
}

// 快速选择函数
int quick_select(int *a, int left, int right, int k) {
    if (left <= right) {
        int pivot_index = partition(a, left, right);

        if (pivot_index == k - 1) {
            return a[pivot_index]; // 找到第 k 小的元素
        } else if (pivot_index > k - 1) {
            return quick_select(a, left, pivot_index - 1, k); // 在左半部分查找
        } else {
            return quick_select(a, pivot_index + 1, right, k); // 在右半部分查找
        }
    }
    return -1; // 不应该到达这里
}

int main() {
    int a[7] = {5, 2, 8, 4, 3, 7, 6};
    int k;

    printf("请输入要查找的第 k 小的数 (k 从 1 开始)：\n");
    scanf("%d", &k);

    if (k < 1 || k > 7) {
        printf("输入的 k 超出范围！\n");
        return -1;
    }

    int result = quick_select(a, 0, 6, k);
    printf("数组中第 %d 小的数是：%d\n", k, result);

    return 0;
}
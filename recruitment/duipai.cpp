#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::swap
#include <ctime>     // 用于 time()
#include <cstdlib>   // 用于 rand() 和 srand()

using namespace std;

// --- 辅助方法 ---

// 交换数组中 i 和 j 位置的数
void swapElements(vector<int>& arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 复制数组
vector<int> copyArray(const vector<int>& arr) {
    return vector<int>(arr); // C++ vector 直接赋值或构造即为深拷贝
}

// 判断两个数组是否完全相同
bool sameArray(const vector<int>& arr1, const vector<int>& arr2) {
    if (arr1.size() != arr2.size()) return false;
    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

// 生成随机数组
vector<int> randomArray(int n, int v) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        // rand() % v 得到 0 ~ v-1
        // 加 1 得到 1 ~ v
        arr[i] = (rand() % v) + 1;
    }
    return arr;
}

// --- 排序算法实现 ---

// 选择排序
void selectionSort(vector<int>& arr) {
    if (arr.size() < 2) return;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swapElements(arr, i, minIndex);
    }
}

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    if (arr.size() < 2) return;
    int n = arr.size();
    for (int end = n - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swapElements(arr, i, i + 1);
            }
        }
    }
}

// 插入排序
void insertionSort(vector<int>& arr) {
    if (arr.size() < 2) return;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swapElements(arr, j, j + 1);
        }
    }
}

// --- 主测试程序 (对数器) ---

int main() {
    // 设置随机种子
    srand(time(0));

    int N = 200;         // 最大长度
    int V = 1000;        // 最大值
    int testTimes = 50000; // 测试次数

    cout << "测试开始" << endl;

    for (int i = 0; i < testTimes; i++) {
        // 随机长度 [0, N-1]
        int n = rand() % N;
        vector<int> arr = randomArray(n, V);

        // 拷贝三份
        vector<int> arr1 = copyArray(arr);
        vector<int> arr2 = copyArray(arr);
        vector<int> arr3 = copyArray(arr);

        // 分别运行三种排序
        selectionSort(arr1);
        bubbleSort(arr2);
        insertionSort(arr3);

        // 验证结果
        if (!sameArray(arr1, arr2) || !sameArray(arr1, arr3)) {
            cout << "出错了!" << endl;
            // 如果出错，可以打印 arr 来看具体的错误用例
            return -1;
        }
    }

    cout << "测试结束" << endl;
    return 0;
}
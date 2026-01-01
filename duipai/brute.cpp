/**
 * 暴力解法
 * 从 in.txt 读取输入，输出到 out1.txt
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 重定向输入输出流
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    
    // ============ 根据题目修改此处 ============
    // 示例：暴力排序（冒泡排序）
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 冒泡排序 O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    // ==========================================
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

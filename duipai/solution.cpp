/**
 * 最优解法
 * 从 in.txt 读取输入，输出到 out2.txt
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 重定向输入输出流
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    
    // ============ 根据题目修改此处 ============
    // 示例：最优排序（使用STL sort，O(n log n)）
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 快速排序 O(n log n)
    sort(arr.begin(), arr.end());
    
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

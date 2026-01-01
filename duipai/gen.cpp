/**
 * gen.cpp
 * 生成随机测试数据到 in.txt（写到当前工作目录）
 */
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    srand((unsigned)time(nullptr));

    ofstream fout("in.txt");
    if (!fout) {
        cout << "cannot open in.txt" << endl;
        return 1;
    }

    // ============ 根据题目修改此处 ============
    // 示例：生成一个排序问题的测试数据
    int n = rand() % 100 + 1;  // [1, 100]
    fout << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << (rand() % 1000 + 1); // [1, 1000]
        if (i + 1 < n) fout << ' ';
    }
    fout << '\n';
    // ==========================================

    return 0;
}

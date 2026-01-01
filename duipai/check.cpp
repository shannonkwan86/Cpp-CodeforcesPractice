/**
 * check.cpp
 * 比较 out1.txt 与 out2.txt 是否完全相同（从当前工作目录读取）
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static bool sameFile(const string& a, const string& b) {
    ifstream f1(a, ios::binary);
    ifstream f2(b, ios::binary);
    if (!f1 || !f2) return false;

    string s1((istreambuf_iterator<char>(f1)), istreambuf_iterator<char>());
    string s2((istreambuf_iterator<char>(f2)), istreambuf_iterator<char>());
    return s1 == s2;
}

int main() {
    if (sameFile("out1.txt", "out2.txt")) {
        cout << "OK" << endl;
        return 0;
    }
    cout << "WA" << endl;
    return 1;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int x, y;
    cin >> x >> y;
    if ((x & y) == 0)
    {
        cout << x << " " << y << endl;
        return;
    }
    int p = 0, q = 0;
    int bd = INT_MAX;
    int b = -1;
    // 取第一个冲突位
    for (int i = 30; i >= 0; i--)
    {
        if (((x >> i) & 1) && ((y >> i) & 1))
        {
            b = i;
            break;
        }
    }

    int hix = (x >> (b + 1)) << (b + 1);
    int hiy = (y >> (b + 1)) << (b + 1);

    // 进位法
    int p1 = ((x >> b) + 1) << b;
    int q1 = y & (~p1);
    int d1 = abs(p1 - x) + abs(q1 - y);
    if (d1 < bd)
    {
        p = p1;
        q = q1;
        bd = d1;
    }
    int q2 = ((y >> b) + 1) << b;
    int p2 = x & ~(q2);
    int d2 = abs(p2 - x) + abs(q2 - y);
    if (d2 < bd)
    {
        p = p2;
        q = q2;

        bd = d2;
    }

    // 切分法 
    int p3 = hix + (1 << b);
    int q3 = hiy + (1 << b) - 1;
    int d3 = abs(p3 - x) + abs(q3 - y);
    if (d3 < bd)
    {
        p = p3;
        q = q3;
        bd = d3;
    }
    int p4 = hix + (1 << b) - 1;
    int q4 = hiy + (1 << b);
    int d4 = abs(p4 - x) + abs(q4 - y);
    if (d4 < bd)
    {
        p = p4;
        q = q4;
        bd = d4;
    }
    
    cout << p << " " << q << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
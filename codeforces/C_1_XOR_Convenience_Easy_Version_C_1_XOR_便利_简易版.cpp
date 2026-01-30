#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    if (n == (1 << (__lg(n))))
    {
        cout << -1 << endl;
        return;
    }
    if (n % 2)
    {
        cout << n - 1 << " ";
        for (int i = 2; i < n; i++)
        {
            cout << (i ^ 1) << " ";
        }
        cout << 1 << endl;
    }
    else
    {
        // int f = n;
        // if (f ^ (n - 1) >= n)
        int f = 1;
        vector<int> a;
        a.push_back(n);
        for (int i = 2; i < n; i++)
        {
            a.push_back(i ^ f);
        }
        a.push_back(1);
        int x = n - (1 << __lg(n));
        swap(a[x - 1], a[0]);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        // cout << f << endl;
    }
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
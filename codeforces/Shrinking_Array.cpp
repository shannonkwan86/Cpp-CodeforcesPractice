#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//分类 模拟 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i - 1] - a[i])<=1)
        {
            cout << 0 << endl;
            return;
        }
    }
    // if (n == 2 && abs(a[2] - a[1]) > 1)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // bool fgg = true;
    // bool fgl = true;

    // for (int i = 2; i <= n; i++)
    // {
    //     if (a[i] > a[i - 1])
    //         fgl = false;
    //     if (a[i] < a[i - 1])
    //         fgg = false;
    // }
    // if (fgg)
    // {
    //     for (int i = 2; i <= n; i++)
    //     {
    //         if (a[i] - a[i - 1] <= 1)
    //         {
    //             cout << 0 << endl;
    //             return;
    //         }
    //     }
    //     cout << -1 << endl;
    //     return;
    // }
    // if (fgl)
    // {
    //     for (int i = 2; i <= n; i++)
    //     {
    //         if (a[i - 1] - a[i] <= 1)
    //         {
    //             cout << 0 << endl;
    //             return;
    //         }
    //     }
    //     cout << -1 << endl;
    //     return;
    // }

    // vector<int> fg;
    // vector<int> d;
    // d.push_back(1);
    for (int i = 2; i < n; i++)
    {
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
        {
            cout<<1<<endl;
            return;
        }
    }cout<<-1<<endl;
    // d.push_back(n);
    // int ans = 1145;
    // for (int i = 1; i < d.size() - 1; i++)
    // {
    //     if (a[d[i]] > a[d[i] + 1])
    //     {
            

    //         for (int j = d[i]; j <= d[i + 1]; j++)
    //         {
    //             if (a[j] <= a[d[i] - 1])
    //             {
    //                 ans = min(ans, j - d[i]);
    //                 break;
    //             }
    //         }
    //         for (int j = d[i]; j >= d[i - 1]; j--)
    //         {
    //             if (a[j] <= a[d[i] - 1])
    //             {
    //                 ans = min(ans, d[i] - j);
    //                 break;
    //             }
    //         }
    //     }
    //     if (a[d[i]] < a[d[i] + 1])
    //     {
            
    //         for (int j = d[i]; j <= d[i + 1]; j++)
    //         {
    //             if (a[j] >= a[d[i] - 1])
    //             {
    //                 ans = min(ans, j - d[i]);
    //                 break;
    //             }
    //         }
    //         for (int j = d[i]; j >= d[i - 1]; j--)
    //         {
    //             if (a[j] >= a[d[i] - 1])
    //             {
    //                 ans = min(ans, d[i] - j);
    //                 break;
    //             }
    //         }
    //     }
    // }
    // cout << ans << endl;
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
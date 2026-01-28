#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    // int fg = false;
    int cnt = 1;
    int mx = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i < n; i++)
    {

        if (a[i + 1] - a[i] <= 1)
        {
            if (a[i + 1] - a[i] == 1)
            {
                cnt++;
                // cout << cnt << " ";
            }
        }
        else
        {
            // cout<<endl;
            mx = max(mx, cnt);
            cnt = 1;
        }
        // break;
    }
    mx = max(mx, cnt);
    cout << mx << endl;
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
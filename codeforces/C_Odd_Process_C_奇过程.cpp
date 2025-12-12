#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    vector<int> o;
    vector<int> e;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2)
            o.push_back(a[i]);
        else
            e.push_back(a[i]);
    }
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    int el = e.size();
    int ol = o.size();
    if (ol == 0)
    {
        for (int i = 1; i <= n; i++)
            cout << 0 << " ";
        cout << endl;
        return;
    }
    int l = el + 1;
    vector<int> ans(n + 1);
    ans[1] = o[ol - 1];
    for (int i = 2; i <= l; i++)
    {
        ans[i] = ans[i - 1] + e[el - i + 1];
    }
    for (int i = l + 1; i <= n; i++)
    {
        if ((i - l) % 2 == 0)
            ans[i] = ans[l];
        else
            ans[i] = ans[l - 1];
    }
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    if (s % 2 == 0)
        cout << 0 << " ";
    else
        cout <<  ans[n]<< " ";
    cout << endl;
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
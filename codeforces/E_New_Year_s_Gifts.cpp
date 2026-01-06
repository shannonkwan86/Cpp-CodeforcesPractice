#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> ms;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
    }
    vector<int> x(n + 1);
    vector<int> y(n + 1);
    vector<int> z(n + 1);
    int sum = 0;
    multiset<pair<int, int>, greater<pair<int, int>>> ms3;
    multiset<pair<int, int>> ms2;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        sum += y[i];
        ms3.insert({z[i] - y[i], i});
    }
    k -= sum;
    int cnt = 0;

    while (!ms3.empty())
    {
        auto it = ms3.begin();
        auto res = ms.lower_bound(x[it->second]);
        if (res != ms.end())
        {
            cnt++;
            ms.erase(res);
        }
        else
        {
            ms2.insert(*it);
        }
        ms3.erase(it);
    }

    while (!ms2.empty())
    {
        if (k >= ms2.begin()->first)
        {
            cnt++;
            k -= ms2.begin()->first;
            ms2.erase(ms2.begin());
        }
        else
            break;
    }
    cout << cnt << endl;
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
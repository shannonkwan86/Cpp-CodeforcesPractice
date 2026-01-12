#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int mex = -1;
    for (int i = 0; i <= n + 1; i++)
    {
        if (mp[i] == 0)
        {
            mex = i;
            break;
        }
    }
    // cout<<114<<endl;
    // cout << mex << endl;
    if (mex >= k - 1)
        cout << k - 1 << endl;
    else
    {
        cout << mex << endl;
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
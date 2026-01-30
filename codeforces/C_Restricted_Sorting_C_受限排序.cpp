#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());
    vector<int> c;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != a[i])
            c.push_back(i);
    }
    if (c.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    int mx = b[n];
    int mn = b[1];
    int ans=INT_MAX;
    for(int i:c){
        ans=min(ans,max(abs(mx-a[i]),abs(mn-a[i])));
    }
    cout<<ans<<endl;
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
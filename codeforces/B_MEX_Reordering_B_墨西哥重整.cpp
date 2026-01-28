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
    for (int i = 1; i < n; i++)
    {

        set<int> st1(a.begin() + 1, a.begin() + i+1);
        int mex1 = 0;
        // cout<<st1.count(mex1)<<endl;
        while (st1.count(mex1))
        {
            ++mex1;
        }
        set<int> st2(a.begin() + i + 1, a.end());
        int mex2 = 0;
        while (st2.count(mex2))
        {
            ++mex2;
        }
        // cout<<mex1<<" "<<mex2<<endl;
        if (mex1 == mex2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
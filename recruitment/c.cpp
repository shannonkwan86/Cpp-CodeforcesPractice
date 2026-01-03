#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
void solve()
{
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    int cnt = 0;
    struct p
    {
        int nex, ney, hax, hay, idx;
    };
    struct cmp1
    {
        bool operator()(const p &a, const p &b)
        {
            return a.nex > b.nex;
        }
    };
    struct cmp2
    {
        bool operator()(const p &a, const p &b)
        {
            return a.ney > b.ney;
        }
    };

    vector<p> po(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> po[i].nex >> po[i].ney >> po[i].hax >> po[i].hay;
        po[i].idx = i;
    }
    priority_queue<p, vector<p>, cmp1> pq1;
    priority_queue<p, vector<p>, cmp2> pq2;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        pq1.push(po[i]);
    }
    while (1)
    {
        while (!pq1.empty() && pq1.top().nex <= x0)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        if (!pq2.empty() && pq2.top().ney <= y0)
        {
            cnt++;
            x0 += pq2.top().hax;
            y0 += pq2.top().hay;
            ans.push_back(pq2.top().idx);
            pq2.pop();
        }
        else
            break;
    }
    if (cnt == n)
    {
        cout << "YES" << endl;
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
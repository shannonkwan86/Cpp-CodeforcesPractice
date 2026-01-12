#include <bits/stdc++.h>
using namespace std;


const int MAXN = 200005;
vector<int> adj[MAXN];
int dist[MAXN];
int cnt[MAXN];
int childCnt[MAXN];

void bfs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
        childCnt[i] = 0;
        cnt[i] = 0;
    }
    cnt[0] = 0;

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt[dist[u]]++;

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                childCnt[u]++;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(n);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        ans = max(ans, cnt[dist[i]]);

        ans = max(ans, 1 + childCnt[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
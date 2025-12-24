#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 4e5 + 5;
int a[N];
int val[N];
int k;
map<int, int> cnt;
int sum[N * 4];
int tcnt[N * 4];

struct Op
{
    int typ;
    ll p, l, r;
} ops[200005];

void up(int i)
{
    tcnt[i] = tcnt[i * 2] + tcnt[i * 2 + 1];
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}

void build(int l, int r, int i)
{
    if (l == r)
    {
        tcnt[i] = cnt[val[l]];
        sum[i] = tcnt[i] * val[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * i);
    build(mid + 1, r, 2 * i + 1);
    up(i);
}

void mfy(int l, int r, int i, int pos, int v)
{
    if (l == r)
    {
        tcnt[i] += v;
        sum[i] += v * val[l];
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        mfy(l, mid, i * 2, pos, v);
    else
        mfy(mid + 1, r, i * 2 + 1, pos, v);
    up(i);
}

int que(int jobl, int jobr, int l, int r, int i)
{
    if (jobl > jobr)
        return 0;
    if (jobl <= l && r <= jobr)
    {
        return sum[i];
    }
    int mid = (l + r) / 2;
    int ans = 0;
    if (jobl <= mid)
    {
        ans += que(jobl, jobr, l, mid, i * 2);
    }
    if (jobr >= mid + 1)
    {
        ans += que(jobl, jobr, mid + 1, r, i * 2 + 1);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[j];
        cnt[a[j]]++;
        j++;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> ops[i].typ;
        if (ops[i].typ == 1 || ops[i].typ == 2)
        {
            cin >> ops[i].p;
            a[j++] = ops[i].p;
        }
        else
        {
            cin >> ops[i].l >> ops[i].r;
        }
    }

    sort(a + 1, a + j);
    k = 0;
    for (int i = 1; i < j; i++)
    {
        if (i == 1 || a[i] != a[i - 1])
        {
            val[++k] = a[i];
        }
    }

    build(1, k, 1);

    for (int i = 1; i <= q; i++)
    {
        if (ops[i].typ == 1)
        {
            int pt = lower_bound(val + 1, val + k + 1, ops[i].p) - val;
            mfy(1, k, 1, pt, 1);
        }
        else if (ops[i].typ == 2)
        {
            int pt = lower_bound(val + 1, val + k + 1, ops[i].p) - val;
            mfy(1, k, 1, pt, -1);
        }
        else if (ops[i].typ == 3)
        {
            int jl = lower_bound(val + 1, val + k + 1, ops[i].l) - val;
            int jr = upper_bound(val + 1, val + k + 1, ops[i].r) - val - 1;
            cout << que(jl, jr, 1, k, 1) << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
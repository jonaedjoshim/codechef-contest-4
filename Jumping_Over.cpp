#include <bits/stdc++.h>
using namespace std;

struct fenwick
{
    int n;
    vector<long long> bit;

    fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int x)
    {
        while (x <= n)
        {
            bit[x]++;
            x += x & -x;
        }
    }

    long long get(int x)
    {
        long long sum = 0;

        while (x > 0)
        {
            sum += bit[x];
            x -= x & -x;
        }

        return sum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        vector<int> pos(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            pos[p[i]] = i;
        }

        vector<long long> left(n + 1, 0);
        vector<long long> right(n + 2, 0);

        fenwick f1(n);

        long long inv = 0;

        for (int x = 1; x <= n; x++)
        {
            long long smaller = f1.get(pos[x]);
            long long total = x - 1;

            inv += total - smaller;
            left[x] = left[x - 1] + smaller;

            f1.add(pos[x]);
        }

        fenwick f2(n);

        for (int x = n; x >= 1; x--)
        {
            long long smaller_pos = f2.get(pos[x] - 1);
            long long total = n - x;
            long long noninv = total - smaller_pos;

            right[x] = right[x + 1] + noninv;

            f2.add(pos[x]);
        }

        long long ans = (long long)4e18;

        int l = 1;

        while (l <= n)
        {
            int r = l;

            while (r < n && pos[r] < pos[r + 1])
            {
                r++;
            }

            long long cost = inv + 2 * left[l - 1] + 2 * right[r + 1];

            ans = min(ans, cost);

            l = r + 1;
        }

        cout << ans << endl;
    }

    return 0;
}
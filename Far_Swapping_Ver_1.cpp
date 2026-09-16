#include <bits/stdc++.h>
using namespace std;

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

        vector<int> p(n);

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (p[j] > p[j + 1] && abs(p[j] - p[j + 1]) > 1)
                {
                    swap(p[j], p[j + 1]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << p[i];

            if (i + 1 < n)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
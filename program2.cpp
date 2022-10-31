#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 3e3 + 3;
int n, m, up[N][N], las[N][N];
int tp, sta[N];
LL ans;
char a[N][N];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", a[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] -= '0';
    ++m;
    for (int i = 0; i <= m; ++i)
        up[0][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 1)
                up[i][j] = up[i - 1][j];
            else
                up[i][j] = i + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 1)
                las[i][j] = las[i][j - 1];
            else
                las[i][j] = j;
    for (int i = 0; i <= n; ++i)
        up[i][0] = i + 1;
    for (int i = 1; i <= m; ++i)
        las[n + 1][i] = i;
    for (int i = n; i; --i)
    {
        sta[tp = 1] = 0;
        for (int j = 1; j <= m; ++j)
        {
            while (tp && up[i][sta[tp]] < up[i][j])
            {

                if (las[i + 1][j - 1] >= sta[tp - 1] + 1)
                    ++ans;
                --tp;
            }
            if (up[i][sta[tp]] == up[i][j])
                --tp;
            sta[++tp] = j;
        }
    }
    cout << ans << endl;
    return 0;
}
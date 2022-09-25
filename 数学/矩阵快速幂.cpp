// Problem: P3390 【模板】矩阵快速幂
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3390
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
#define endl '\n'
struct Matrix
{
    ll a[100][100];
    int h, w;
    Matrix(int x, int y)
    {
        h = x, w = y;
        memset(a, 0, sizeof(a));
    }
    void identityMatrix()
    {
        for (int i = 0; i < h; i++)
        {
            a[i][i] = 1;
        }
    }
    void read()
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cin >> a[i][j];
        }
    }
    void print()
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
};
Matrix operator*(Matrix &x, Matrix &y)
{
    int h = x.h, w = y.w, n = x.w;
    Matrix ans(h, w);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    Matrix a(n, n), ans(n, n);
    a.read();
    ans.identityMatrix();
    while (k)
    {
        if (k & 1)
            ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    ans.print();
    return 0;
}

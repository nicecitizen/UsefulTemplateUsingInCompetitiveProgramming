#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
#define endl '\n'
struct Matrix
{
    int a[100][100];
    int h, w;
    Matrix(int x, int y)
    {
        h = x, w = y;
        memset(a, 0, sizeof(a));
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
                (ans.a)[i][j] += (x.a)[i][k] * (y.a)[k][j];
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    struct Matrix p(a, b);
    struct Matrix q(c, d);
    p.read(), q.read();
    struct Matrix ans = p * q;
    ans.print();
    return 0;
}

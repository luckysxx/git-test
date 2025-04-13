#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n, m;
    vector<pair<pair<int, int>, int>> boom(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, width;
        cin >> x >> y >> width;
        pair<int, int> p(x, y);
        boom[i] = make_pair(p, width);
    }
    vector<pair<pair<int, int>, int>> TNT(m);
    for (int i = 0; i < n; i++)
    {
        int x, y, width;
        cin >> x >> y >> width;
        pair<int, int> p(x, y);
        TNT[i] = make_pair(p, width);
    }
}
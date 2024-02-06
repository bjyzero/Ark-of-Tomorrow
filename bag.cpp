// 动态规划中的 01 背包

// 你有 n 个物品，价值为 w_i, 体积为 v_i, 背包的总容积为 V， 在装物品不超过背包总容量的前提下， 尽可能让价值和最大
//  f[i][j] 表示花了 j 的容量装前 i 个物品中的一些物品，且价值之和最大的价值之和
// 一方面，我不装第 i 个物品， f[i - 1][j]
// 另一方面，我装了第 i 个物品， f[i - 1][j - v[i]] + w[i]
// f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i]] + w[i]) --> 可以发现第一维度没用
// 时间复杂度 O( nV )， 空间可以压缩到 O( V )
// 如果把 f[i] 称作 f， f[i - 1] 称作 g
// 则转移式变成 f[j] = max( g[i] , g[j - v[i]] + w[i])
// 然后令 g = f，可以递推下一轮

// 动态规划的本质是对状态空间的压缩
#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;
#define inf 1'000'000'000

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, b;
    cin >> n >> m >> b;
    vector<Pair> a(n);
    for (auto &t : a)
        cin >> t.first >> t.second;
    int mx = 0;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
    }

    vector<int> f(b + 1, 0);
    f[0] = 0; // 背包初始化，零块钱什么都买不了，所以攻击性为 0
    // 其余花费都是不合法的
    for (auto &t : a)
    {
        for (int i = b; i >= t.second; --i)
        {
            f[i] = max(f[i], f[i - t.second] + t.first);
        }
    }
    
    int Mx = *max_element(f.begin(), f.end());
     if (Mx == 0) // 所有干员的价格都大于 b
    {
        cout << "-1\n";
        return 0;
    }
    //上取整
    cout << (mx + Mx - 1) / Mx << '\n';
    return 0;
}
// ��̬�滮�е� 01 ����

// ���� n ����Ʒ����ֵΪ w_i, ���Ϊ v_i, ���������ݻ�Ϊ V�� ��װ��Ʒ������������������ǰ���£� �������ü�ֵ�����
//  f[i][j] ��ʾ���� j ������װǰ i ����Ʒ�е�һЩ��Ʒ���Ҽ�ֵ֮�����ļ�ֵ֮��
// һ���棬�Ҳ�װ�� i ����Ʒ�� f[i - 1][j]
// ��һ���棬��װ�˵� i ����Ʒ�� f[i - 1][j - v[i]] + w[i]
// f[i][j] = max(f[i - 1][j] , f[i - 1][j - v[i]] + w[i]) --> ���Է��ֵ�һά��û��
// ʱ�临�Ӷ� O( nV )�� �ռ����ѹ���� O( V )
// ����� f[i] ���� f�� f[i - 1] ���� g
// ��ת��ʽ��� f[j] = max( g[i] , g[j - v[i]] + w[i])
// Ȼ���� g = f�����Ե�����һ��

// ��̬�滮�ı����Ƕ�״̬�ռ��ѹ��
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
    f[0] = 0; // ������ʼ�������Ǯʲô�����ˣ����Թ�����Ϊ 0
    // ���໨�Ѷ��ǲ��Ϸ���
    for (auto &t : a)
    {
        for (int i = b; i >= t.second; --i)
        {
            f[i] = max(f[i], f[i - t.second] + t.first);
        }
    }
    
    int Mx = *max_element(f.begin(), f.end());
     if (Mx == 0) // ���и�Ա�ļ۸񶼴��� b
    {
        cout << "-1\n";
        return 0;
    }
    //��ȡ��
    cout << (mx + Mx - 1) / Mx << '\n';
    return 0;
}
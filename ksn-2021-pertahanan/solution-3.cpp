#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MOD = 1e9+7;
int n, m, k;
string s;
int memo[N][N][2];

char toVitamin(int cur) {
  return cur == 0 ? 'A' : 'B';
}

int dp(int n, int k, int cur) {
  if(n == 0) return (k == 0) ? 1 : 0;
  int &ret = memo[n][k][cur];
  if(ret != -1) return ret;
  ret = 0;
  for(int i = 1; i <= n && max(0, i-m+1) <= k; i++) {
    if(s[n-i] == toVitamin(cur^1)) break;
    ret += dp(n-i, k-max(0, i-m+1), cur^1);
    if(ret >= MOD) ret -= MOD;
  }
  return ret;
}

int main() {
  cin >> n >> m >> k;
  cin >> s;
  memset(memo, -1, sizeof memo);
  int ans = dp(n, k, 0) + dp(n, k, 1);
  if(ans >= MOD) ans -= MOD;
  cout << ans << '\n';
  return 0;
}

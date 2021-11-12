#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MOD = 1e9+7;
int n, m, k;
string s;
int dp[N][N][2];
int sum_hor[N][N][2], sum_diag[N][N][2];

char toVitamin(int cur) {
  return cur == 0 ? 'A' : 'B';
}

int main() {
  cin >> n >> m >> k;
  cin >> s;

  memset(dp, -1, sizeof dp);
  dp[0][0][0] = dp[0][0][1] = 1;
  for(int j = 1; j <= k; j++) {
    dp[0][j][0] = dp[0][j][1] = 0;
  }

  sum_hor[0][0][0] = sum_hor[0][0][1] = 1;
  for(int j = 1; j <= k; j++) {
    sum_hor[0][j][0] = sum_hor[0][j][1] = 0;
  }

  sum_diag[0][0][0] = sum_diag[0][0][1] = 1;
  for(int j = 1; j <= k; j++) {
    sum_diag[0][j][0] = sum_diag[0][j][1] = 0;
  }

  int lst[2] = {-1, -1};
  for(int idx = 1; idx <= n; idx++) {
    if(s[idx-1] == 'A') lst[0] = idx-1;
    if(s[idx-1] == 'B') lst[1] = idx-1;
    for(int need = 0; need <= k; need++) {
      for(int cur = 0; cur < 2; cur++) {
        dp[idx][need][cur] = 0;
        bool ok = 1;
        int idx_limit = lst[cur^1];
        int l, r;

        l = max(idx-min(idx, m-1), idx_limit+1), r = idx-1;
        if(l <= r) {
          dp[idx][need][cur] += sum_hor[r][need][cur^1];
          dp[idx][need][cur] %= MOD;
          if(l > 0) {
            dp[idx][need][cur] -= sum_hor[l-1][need][cur^1];
            dp[idx][need][cur] += MOD;
            dp[idx][need][cur] %= MOD;
          }
        }
        if(l == idx_limit+1) {
          ok = 0;
        }

        if(ok) {
          l = max(idx-min(idx, need+m-1), idx_limit+1), r = idx-m;
          if(l <= r) {
            dp[idx][need][cur] += sum_diag[r][need-1][cur^1];
            dp[idx][need][cur] %= MOD;
            if(l > 0 && need-(r-l+1)-1 >= 0) {
              dp[idx][need][cur] -= sum_diag[l-1][need-(r-l+1)-1][cur^1];
              dp[idx][need][cur] += MOD;
              dp[idx][need][cur] %= MOD;
            }
          }
        }

        sum_hor[idx][need][cur] = dp[idx][need][cur];
        sum_hor[idx][need][cur] += sum_hor[idx-1][need][cur];
        sum_hor[idx][need][cur] %= MOD;

        sum_diag[idx][need][cur] = dp[idx][need][cur];
        if(need > 0) {
          sum_diag[idx][need][cur] += sum_diag[idx-1][need-1][cur];
          sum_diag[idx][need][cur] %= MOD;
        }
      }
    }
  }

  int ans = dp[n][k][0] + dp[n][k][1];
  if(ans >= MOD) {
    ans -= MOD;
  }
  cout << ans << '\n';
  return 0;
}

// O(NM)

#include <cstdio>
#include <vector>

const int kMod = 1000000007;

void solve() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  char S[N + 5];
  scanf("%s", S + 1);

  std::vector<int> dp0(N + 1), dp1(N + 1);
  dp0[0] = dp1[0] = 1;

  for (int i = 1; i <= N; ++i) {
    bool okay0 = (S[i] != 'B'), okay1 = (S[i] != 'A');
    for (int j = 1; j < M; ++j) {
      if (i - j < 0) break;
      if (okay0) dp0[i] = (dp0[i] + dp1[i - j]) % kMod;
      if (okay1) dp1[i] = (dp1[i] + dp0[i - j]) % kMod;
      if (S[i - j] == 'B') okay0 = false;
      if (S[i - j] == 'A') okay1 = false;
    }
  }

  int ans = (dp0[N] + dp1[N]) % kMod;
  printf("%d\n", ans);
}

int main() {
  solve();
  return 0;
}

// O(N)

#include <cstdio>
#include <functional>
#include <vector>

const int kMod = 1000000007;

void solve() {
  int N;
  scanf("%d", &N);
  std::vector<int> P(N), iP(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &P[i]);
    iP[--P[i]] = i;
  }

  std::vector<bool> hasLeft(N), hasRight(N);

  std::vector<int> stack;
  for (int i = 0; i < N; ++i) {
    while (!stack.empty() && stack.back() > P[i]) {
      stack.pop_back();
    }
    hasLeft[i] = !stack.empty();
    stack.push_back(P[i]);
  }

  stack.clear();
  for (int i = N - 1; i >= 0; --i) {
    while (!stack.empty() && stack.back() > P[i]) {
      stack.pop_back();
    }
    hasRight[i] = !stack.empty();
    stack.push_back(P[i]);
  }

  std::vector<int> lft(N), rgt(N), par(N + 1, N);
  std::function<int(int)> root = [&](int u) {
    return par[u] = (u == par[u] ? u : root(par[u]));
  };
  for (int val = N - 1; val >= 0; --val) {
    int i = iP[val];
    lft[i] = (i > 0 ? root(i - 1) : N);
    rgt[i] = root(i + 1);
    if (lft[i] < N) par[lft[i]] = i;
    if (rgt[i] < N) par[rgt[i]] = i;
    par[i] = i;
  }

  std::vector<int> dp(N + 1);
  dp[N] = 1;

  for (int val = N - 1; val >= 0; --val) {
    int i = iP[val];
    dp[i] = 1LL * (dp[lft[i]] + hasLeft[i]) * (dp[rgt[i]] + hasRight[i]) % kMod;
    if (hasLeft[i] && hasRight[i]) dp[i] = (dp[i] + kMod - 2) % kMod;
  }

  printf("%d\n", dp[iP[0]]);
}

int main() {
  solve();
  return 0;
}

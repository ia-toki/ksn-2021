#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N, A[MAXN], nextSmaller[MAXN];
long long sum = 1;
long long start_dp[MAXN];

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void findNextSmaller() {
  vector<pair<int, int>> stac;
  nextSmaller[N] = N + 1;
  stac.emplace_back(A[N], N);
  for (int i = N - 1; i >= 1; i--) {
    while (!stac.empty() && stac.back().first > A[i]) {
      stac.pop_back();
    }
    nextSmaller[i] = (stac.empty() ? N + 1 : stac.back().second);
    stac.emplace_back(A[i], i);
  }

  int smallest = A[1];
  for (int i = 1; i <= N; i++) {
    if (A[i] <= smallest) start_dp[i]++;
    smallest = min(smallest, A[i]);
  }
}

long long prefix_diff[MAXN];
long long tree_sum[MAXN];

void solve() {
  long long ans = 0, endSum = 0;
  long long diffSum = 0;
  for (int i = 1; i <= N; i++) {
    diffSum += prefix_diff[i];
    endSum = (endSum + tree_sum[i] + start_dp[i] + diffSum) % MOD;

    prefix_diff[i+2] += endSum;
    prefix_diff[nextSmaller[i]] -= endSum;

    tree_sum[nextSmaller[i]] += tree_sum[i] + endSum;

    if (nextSmaller[i] == N + 1) {
      ans += endSum;
    }
  }
  cout << ans % MOD << "\n";
}

int main() {
  input();
  findNextSmaller();
  solve();
}

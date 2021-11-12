#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5;
const int MOD = 1e9 + 7;

int N;
int A[MAX_N + 5];
int L[MAX_N + 5], R[MAX_N + 5];
int LL[MAX_N + 5], RR[MAX_N + 5];

long long dp[MAX_N + 5];

namespace min_query_BIT {
  int tree[MAX_N * 4];

  void build(int n, int l, int r) {
    if (l == r) {
      tree[n] = A[l];
      return;
    }
    int mid = (l + r) / 2;
    build(n*2, l, mid);
    build(n*2+1, mid+1, r);
    tree[n] = min(tree[n*2], tree[n*2+1]);
  }

  int query(int n, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || l > r || ql > qr) return N+1;
    if (ql <= l && r <= qr) {
      return tree[n];
    }
    int mid = (l + r) / 2;
    int res1 = query(n*2, l, mid, ql, qr);
    int res2 = query(n*2+1, mid+1, r, ql, qr);
    return min(res1, res2);
  }

  int query(int ql, int qr) {
    return query(1, 1, N, ql, qr);
  }
}


void precompute() {
  min_query_BIT::build(1, 1, N);

  vector<int> stac;
  
  for (int i = 1; i <= N; i++) {
    while (!stac.empty() && A[stac.back()] > A[i]) 
      stac.pop_back();
    
    LL[A[i]] = !stac.empty();
    L[A[i]] = min_query_BIT::query(stac.empty() ? 1 : stac.back()+1, i-1); 

    stac.emplace_back(i);
  }

  stac.clear();
  for (int i = N; i >= 1; i--) {
    while (!stac.empty() && A[stac.back()] > A[i])
      stac.pop_back();
    
    RR[A[i]] = !stac.empty();
    R[A[i]] = min_query_BIT::query(i+1, stac.empty() ? N : stac.back()-1); 


    stac.emplace_back(i);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  precompute();

  dp[N+1] = 1;
  for (int i = N; i >= 1; i--) {
		dp[i] = dp[L[i]] * dp[R[i]];
		if (LL[i]) dp[i] += dp[R[i]];
		if (RR[i]) dp[i] += dp[L[i]];
		if (LL[i] && RR[i]) dp[i] += MOD-1;
		dp[i] %= MOD;
	}

  cout << dp[1] << "\n";
}
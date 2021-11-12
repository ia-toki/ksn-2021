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
  int A[MAX_N + 5];
  int left[MAX_N + 5];
  int right[MAX_N + 5];

  void init() {
    memset(left, 0x3f3f3f3f, sizeof(left));
    memset(right, 0x3f3f3f3f, sizeof(right));
  }

  void update(int idx, int cost) {
    A[idx] = cost;
    for (int i = idx; i <= MAX_N; i += (i & -i)) {
      left[i] = min(left[i], cost);
    }
    for (int i = idx; i > 0; i -= (i & -i)) {
      right[i] = min(right[i], cost);
    }
  }

  int query(int l, int r) {
    if (l > r) return N+1;  
    int res = 0x3f3f3f3f;
    int i;
    for (i = l; i + (i & -i) <= r; i += (i & -i)) {
      res = min(res, right[i]);
    }
    res = min(res, A[i]);
    for (i = r; i - (i & -i) >= l; i -= (i & -i)) {
      res = min(res, left[i]);
    }
    return res;
  }
}


void precompute() {
  min_query_BIT::init();
  for (int i = 1; i <= N; i++) {
    min_query_BIT::update(i, A[i]);
    R[i] = L[i] = N+1;
  }

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
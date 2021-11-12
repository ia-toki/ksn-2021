#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1E5;

int n;
long long a[MAXN+10], b[MAXN+10];
long long ans[MAXN+10];

void solve() {
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += b[i];
  
  bool all_same = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != a[0]) {
      all_same = false;
      break;
    }
  }
  
  if (all_same) {
    for (int i = 0; i < n; i++) ans[i] = b[i];
  }
  else {
    for (int i = 0; i < n; i++) ans[i] = sum;
  }
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
}

void output() {
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  input();
  solve();
  output();
  return 0;
}

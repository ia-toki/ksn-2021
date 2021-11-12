#include <bits/stdc++.h>
using namespace std;

int Q, K, C;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>Q>>K;
  for (int i=1;i<=Q;i++) {
    cin>>C;
    cout<<((K|C)==C?C:-1)<<'\n';
  }
}

#include <bits/stdc++.h>
using namespace std;

int Q, K, C;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>Q>>K;
  for (int i=1;i<=Q;i++) {
    cin>>C;
    for (int P=0;1;P++) {
      if (P>C) {
        cout<<"-1\n";
        break;
      }
      if ((P|K)==C) {
        cout<<P<<'\n';
        break;
      }
    }
  }
}

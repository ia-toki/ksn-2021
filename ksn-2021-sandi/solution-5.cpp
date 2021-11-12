#include <bits/stdc++.h>
using namespace std;

const int MAXK=1<<20;
int Q, K, C, P[MAXK];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>Q>>K;
  memset(P,-1,sizeof(P));
  for (int i=0;i<MAXK;i++) {
    P[i|K]=i;
  }
  for (int i=1;i<=Q;i++) {
    cin>>C;
    cout<<P[C]<<'\n';
  }
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
const long long INF=1e10;

int N, Q, M, S, T, D;
int H[MAXN];
long long DP[2][MAXN];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>N;
  for (int i=1;i<=N;i++) {
    cin>>H[i];
    M=max(M,H[i]);
  }
  if (M>=MAXN) {
    return 0;
  }
  cin>>Q;
  for (int i=1;i<=Q;i++) {
    cin>>S>>T;
    for (int j=0;j<=M;j++) {
      DP[0][j]=j<H[S]?INF:4*(j-H[S]);
    }
    D=S<T?1:-1;
    for (int j=S+D;1;j+=D) {
      for (int k=H[j];k<=M;k++) {
        DP[1][k]=min(DP[0][k]+2,DP[0][k-1]+4);
        if (k<M) DP[1][k]=min(DP[1][k],DP[0][k+1]+1);
      }
      for (int k=1;k<=M;k++) {
        DP[0][k]=k<H[j]?INF:min(DP[1][k],DP[0][k-1]+4);
      }
      for (int k=M;k>H[j];k--) {
        DP[0][k-1]=min(DP[0][k-1],DP[0][k]+1);
      }
      if (j==T) break;
    }
    cout<<DP[0][H[T]]<<'\n';
  }
}

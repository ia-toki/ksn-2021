#include <bits/stdc++.h>
using namespace std;

const int MAXN=3e5+5;
const long long MOD=1e9+7;

int N;
int A[MAXN];
int L[MAXN], R[MAXN];
bool LL[MAXN], RR[MAXN];
long long DP[MAXN];

int main () {
  cin>>N;
  for (int i=1;i<=N;i++) {
    cin>>A[i];
  }
  
  for (int i=1;i<=N;i++) {
    L[A[i]]=N+1;
    for (int j=i-1;j>=1;j--) {
      LL[A[i]]=(A[j]<A[i]);
      if (LL[A[i]]) break;
      L[A[i]]=min(L[A[i]],A[j]);
    }
    R[A[i]]=N+1;
    for (int j=i+1;j<=N;j++) {
      RR[A[i]]=(A[j]<A[i]);
      if (RR[A[i]]) break;
      R[A[i]]=min(R[A[i]],A[j]);
    }
  }
  
  DP[N+1]=1;
  for (int i=N;i>=1;i--) {
    DP[i]=DP[L[i]]*DP[R[i]];
    if (LL[i]) DP[i]+=DP[R[i]];
    if (RR[i]) DP[i]+=DP[L[i]];
    if (LL[i]&&RR[i]) DP[i]+=MOD-1;
    DP[i]%=MOD;
  }
  cout<<DP[1]<<'\n';
}

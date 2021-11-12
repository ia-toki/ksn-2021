#include <bits/stdc++.h>
using namespace std;

const int MAXN=3e5+5;
const long long MOD=1e9+7;

int N;
int A[MAXN];
int L, R;
bool LL, RR;
long long DP[MAXN];
int pos[MAXN], par[MAXN];

int find(int x) {
  if (par[x]!=x) {
    par[x]=find(par[x]);
  }
  return par[x];
}

void merge(int x,int y) {
  x=find(x);
  y=find(y);
  par[max(x,y)]=min(x,y);
}

int main () {
  cin>>N;
  for (int i=1;i<=N;i++) {
    cin>>A[i];
    pos[A[i]]=i;
  }
  
  DP[0]=1;
  for (int i=N;i>=1;i--) {
    L=find(A[pos[i]-1]);
    R=find(A[pos[i]+1]);
    LL=pos[i]!=1&&(!L||find(A[1])!=L);
    RR=pos[i]!=N&&(!R||find(A[N])!=R);
    DP[i]=DP[L]*DP[R];
    if (LL) DP[i]+=DP[R];
    if (RR) DP[i]+=DP[L];
    if (LL&&RR) DP[i]+=MOD-1;
    DP[i]%=MOD;
    par[i]=i;
    if (L) merge(L,i);
    if (R) merge(R,i);
  }
  cout<<DP[1]<<'\n';
}

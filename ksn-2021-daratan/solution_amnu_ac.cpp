#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5, LOG=30;

int N, X;
int A[MAXN], P[MAXN];
long long B[MAXN];
vector <int> V[LOG];

int find(int x) {
  if (P[x]!=x) {
    P[x]=find(P[x]);
  }
  return P[x];
}

void merge(int x,int y) {
  x=find(x);
  y=find(y);
  if (x!=y) {
    P[x]=y;
    B[y]+=B[x];
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>N;
  
  for (int i=1;i<=N;i++) {
    cin>>X;
    A[i]=X;
    P[i]=i;
    for (int j=0;1;j++) {
      X=X>>1;
      if (!X) {
        V[j].push_back(i);
        break;
      }
    }
  }
  
  for (int i=1;i<=N;i++) {
    cin>>X;
    B[find(i)]+=X;
    for (int j=0;A[i]>>j;j++) {
      if ((A[i]>>j)&1^1) {
        for (int k:V[j]) {
          merge(i,k);
        }
        if (!V[j].empty()) {
          V[j].resize(1);
        }
      }
    }
  }
  
  for (int i=1;i<=N;i++) {
    cout<<B[find(i)]<<"\n";
  }
  
  return 0;
}

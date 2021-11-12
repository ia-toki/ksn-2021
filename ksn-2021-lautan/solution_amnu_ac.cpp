#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int A, B, C, D;

inline bool land(int x,int y) {
  if (x<0||y<0) return 0;
  return !(x&y);
}

inline int prefix(int x,int y) {
  if (y<0) return y;
  if (!x) return x;
  x+=x&-x,x=-x;
  int ret=0;
  for (int i=29;i>=0;i--) {
    if (x>>i&1) ret=ret<<1|(y>>i&1);
    else if (y>>i&1) y|=(1<<i)-1;
  }
  return ret;
}

inline int segment(int x,int l,int r) {
  return prefix(x,r)-prefix(x,l-1)+(land(x,l-1)&land(x,l));
}

inline int corner(int a,int b,int c,int d) {
  return segment(a,b,d)+segment(b,a,c)-land(a,b);
}

int main () {
  cin>>N>>M>>Q;
  for (int i=1;i<=Q;i++) {
    cin>>A>>B>>C>>D;
    cout<<corner(A,B,C,D)<<'\n';
  }
}

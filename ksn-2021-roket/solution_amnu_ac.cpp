#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
const long long INF=1e10;

int N, Q, S, T;
int H[MAXN];

struct answer {
  int A, B, C;
  
  void build(int x) {
    A=H[x];
    B=H[x]-x;
    C=H[x]+x;
  }
  
  answer operator + (answer x) {
    x.A=max(x.A,A);
    x.B=max(x.B,B);
    x.C=max(x.C,C);
    return x;
  }
  
  long long ans() {
    return A+2LL*(B+C);
  }
}
blank;

struct tree {
  int L, R;
  answer val;
  tree *lef, *rig;
  
  void build(int l,int r) {
    L=l, R=r;
    if (L==R) {
      val.build(L);
      return;
    }
    int mid=(L+R)/2;
    lef=new tree;
    rig=new tree;
    lef->build(L,mid);
    rig->build(mid+1,R);
    val=lef->val+rig->val;
  }
  
  answer query(int l,int r) {
    if (L>r||R<l) {
      return blank;
    }
    if (L>=l&&R<=r) {
      return val;
    }
    return lef->query(l,r)+rig->query(l,r);
  }
}
root;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>N;
  for (int i=1;i<=N;i++) {
    cin>>H[i];
  }
  H[0]=-N;
  blank.build(0);
  root.build(1,N);
  cin>>Q;
  for (int i=1;i<=Q;i++) {
    cin>>S>>T;
    cout<<root.query(min(S,T),max(S,T)).ans()-4LL*H[S]-H[T]<<'\n';
  }
}

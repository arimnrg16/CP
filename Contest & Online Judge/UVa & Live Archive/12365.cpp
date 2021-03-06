#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cassert>
#define makmu using
#define ndasmu namespace
#define gundulmu std

makmu ndasmu gundulmu;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<string,string> pss;
typedef pair<int,double> pid;
typedef pair<int,LL> pil;
typedef pair<LL,LL> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define TIE cin.tie(0)
#define INF 1000000000
#define INFLL 4000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
#define DEBUG puts("DEBUG")

#ifdef _WIN32
#define getchar_unlocked getchar
#endif

#define g getchar_unlocked

int dx8[8]={-1,-1,0,1,1,1,0,-1},dx4[4]={-1,0,1,0};
int dy8[8]={0,-1,-1,-1,0,1,1,1},dy4[4]={0,-1,0,1};

inline void open(string name){
 freopen((name+".in").c_str(),"r",stdin);
 freopen((name+".out").c_str(),"w",stdout);
}

inline void close(){
 fclose(stdin);
 fclose(stdout);
}

inline int io(){
 register char c;
 while(1){
  c=g();
  if(c!='\n' && c!=' ') break;
 }
 int res=0,sign=1;
 if(c=='-') sign=-1;
 else       res=c-'0';
 while(1){
  c=g();
  if(c==' ' || c=='\n' || c==EOF) break;
  res=(res<<3)+(res<<1)+c-'0';
 }
 return res*sign;
}

///////////////////////////////////////////////////
//////            End of Template            /////
/////////////////////////////////////////////////

LL b,p;
int n,m;
LL power[100005];
int last[100005];
LL BIT[100005];
char op[5];
int a,d;

inline void Update(int x,int y){
 for(; x<=n ; x+= x&-x){
  BIT[x]+=y;
  if(BIT[x] >= p) BIT[x]-=p;
  if(BIT[x] < 0) BIT[x]+=p;
 } 
}

inline int Query(int x){
 int ret=0;
 for(; x>0 ; x-= x&-x){
  ret+=BIT[x];
  if(ret >= p) ret-=p;
 } 
 return ret;
}

inline int modpow(LL base,int po){
 LL ret=1;
 while(po){
  if(po&1) ret=(ret*base)%p;
  base=(base*base)%p;
  po>>=1;
 }
 return ret;
}

int main(){
 scanf("%lld %lld %d %d",&b,&p,&n,&m);
 power[0]=1;
 while(b|p|n|m){
 for(int i=1; i<=n ; i++){
  power[i]=(power[i-1]*b)%p;
  last[i]=0;
  BIT[i]=0;
 }
 while(m--){
  scanf("%s %d %d",op,&a,&d);
  if(op[0]=='E'){
   Update(a,(power[n-a]*(LL)(d-last[a])) % p);
   last[a]=d;
  } 
  else{
   LL ret=Query(d) - Query(a-1);
   ret=(ret * modpow(power[n-d],p-2)) % p;
   if(ret < 0) ret+=p;
   printf("%lld\n",ret);
  } 
 }
 puts("-"); 
 scanf("%lld %lld %d %d",&b,&p,&n,&m); 
 }
 //puts("ganteng");
 return 0;
}


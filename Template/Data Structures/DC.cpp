#include<bits/stdc++.h>

using namespace std;

#define    pf               printf
#define    PF(a)            printf("%d\n",(a))
#define    PF2(a,b)         printf("%d %d\n",(a), (b))
#define    PF3(a,b,c)       printf("%d %d %d\n",(a), (b), (c))
#define    PFL(a)           printf("%lld\n",(a))
#define    PFL2(a,b)        printf("%lld %lld\n",(a), (b))
#define    PFL3(a,b,c)      printf("%lld %lld %lld\n",(a), (b), (c))
#define    get(a)           cin>>a
#define    sf               scanf
#define    SF(a)            scanf("%d",&a)
#define    SF2(a,b)         scanf("%d %d",&a, &b)
#define    SF3(a,b,c)       scanf("%d %d %d",&a, &b, &c)
#define    SFL(a)           scanf("%lld",&a)
#define    SFL2(a,b)        scanf("%lld %lld",&a, &b)
#define    SFL3(a,b,c)      scanf("%lld %lld %lld",&a, &b, &c)
#define    gl(a)            getline(cin,(a))
#define    gc()             getchar()
#define    pb               push_back
#define    m_p              make_pair
#define    pc()             printf("Case %d: ",tt++)
#define    tc()             cout<<"Case "<<tt++<<": "
#define    dbg(x)           cout << #x << " -> " << x << endl;
#define    SZ(a)            (int)(a).size()
#define    all(a)           a.begin(),a.end()
#define    FF               first
#define    SS               second
#define    MAX              2134567891
#define    MOD              1000000007
#define    MM               200005
#define    PI               2*acos(0.0)
#define    cond(n,m)        (xx>=0 && xx<(n) && yy>=0 && yy<(m))

#define    mem(a)           memset((a),0,sizeof (a))
#define    SET(a)           memset((a),-1,sizeof (a))
#define    output           freopen("connect.out","w",stdout);
#define    input            freopen("connect.in","r",stdin);
#define    I_O              ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define    rep(a)           for(int i=0;i<(a);i++)
#define    FOR(a,b)         for(int i=(a);i<(b);i++)
#define    REP(a)           for(int j=0;j<(a);j++)
#define    rev(a)           for(int i=(a);i>=0;i--)
#define    fr(i,n)          for(i=0;i<n;i++)
#define    fr1(i,n,m)       for(i=n;i<m;i++)

int dx[]  = {0, 0, 1, -1};
int dy[]  = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};

typedef long long ll;
typedef unsigned long long llu;
typedef priority_queue < int > PQ;
typedef pair < int , int > pi;
typedef pair < pi , int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < string > vs;

ll bigmod(ll a, ll b, ll c)
{
    if(b==0)return 1%c;ll x=bigmod(a,b/2,c);x=(x*x)%c;
    if(b%2==1)x=(x*a)%c;return x;
}

ll poww(ll a, ll b)
{
    if(b==0)return 1;ll x=poww(a,b/2);x=x*x;if(b%2==1)x=(x*a);return x;
}
ll mod_inverse(ll a, ll mod){return bigmod(a,mod-2,mod);}

/*
//FUNCTION//

ll LCM(ll a, ll b){ return a*b/ __gcd(a,b);}

int pr = 1000002;
vi primelist;
bool pa[MM*10];
void seive( )
{
    int i,j,k=sqrt(pr);
    pa[1]=1;
    primelist.pb(2);
    for(i=4;i<=pr;i+=2)pa[i]=1;
    for(i=3;i<=k;i+=2)if(!pa[i])for(j=i*i;j<=pr;j+=2*i)pa[j]=1;
    for(i=3;i<=pr;i+=2)if(!pa[i])primelist.pb(i);
}
int phi[MM];
void calculatePhi() {
  for (int i = 1; i < MM; i++) {
    phi[i] = i;
  }
  for (int p = 2; p < MM; p++) {
    if (phi[p] == p) { // p is a prime
      for (int k = p; k < MM; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }
}

ll fact_divs( ll n, ll p)
{
    ll cnt=0;while(p<=n){cnt += n/p;n /= p;}return cnt;
}
struct point{double x, y;};
double area( point A, point B, point C){
return 0.5*(A.x*(B.y-C.y) - A.y*(B.x-C.x) + B.x*C.y - C.x*B.y);
}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

//*/
const int M = 300005;
map < pi, int > mp;
vector < int >  qr;
vector < pi > vec[M*4];
int par[M], dsz[M], comp, res[M], vis[M];
stack < int > stq;
void init(int n){
    for(int i=1; i<=n; i++){
        par[i] = i;
        dsz[i] = 1;
    }
    comp = n;
    while(stq.size()) stq.pop();
}
ll unfn(int u){
    while(par[u] != u) u = par[u];
    return u;
}
void mergee(int x, int y){
    int u = unfn(x);
    int v = unfn(y);
    if( u == v ) return;
    --comp;
    if(dsz[u] > dsz[v]) swap(u, v);
    stq.push(u);
    dsz[v] += dsz[u];
    par[u] = v;
}
void rollback(int cur){
    while(stq.size() > cur){
        int u = stq.top(); stq.pop();
        dsz[par[u]] -= dsz[u];
        par[u] = u;
        ++comp;
    }
}
void update(int l, int r, int k, int L, int R, pi &p){
    if(l > R || r < L) return;
    if(l>=L && r<=R) {
        vec[k].pb(p);
        return;
    }
    int mid = (l + r)/2;
    update(l, mid, k*2, L, R, p);
    update(mid+1, r, k*2+1, L, R, p);
}
void dfs(int l, int r, int k){
    int sz = stq.size();
    for(auto x : vec[k]){
        mergee(x.first, x.second);
    }
    if(l == r){
        if(vis[l]) cout<<comp<<endl;
        rollback(sz);
        return;
    }
    int mid = (l + r)/2;
    dfs(l, mid, k*2);
    dfs(mid+1, r, k*2+1);
    rollback(sz);
}
int main(){
    I_O;
    freopen("connect.out","w",stdout);
    freopen("connect.in","r",stdin);
    int n, m;
    cin>>n>>m;
    init(n);
    for(int i=1; i<=m; i++){
        string ch;
        cin>>ch;
        if(ch == "?"){
            vis[i] = 1;
            continue;
        }
        int u, v; cin>>u>>v;
        if(u > v) swap(u, v);
        pi p = {u, v};
        if(ch == "+"){
            mp[p] = i;
        }
        else {
            update(1, m, 1, mp[p], i, p);
            mp.erase(p);
        }
    }
    for(auto x:mp){
        pi p = x.first;
        update(1, m, 1, x.second, m, p);
    }
    dfs(1, max(1, m), 1);



	return 0;
}

/*




*/

#include        "iostream"
#include        "algorithm"
#include        "cstring"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

using namespace std;

#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)2e5+5
#define          pb push_back
#define          mod 1000000007
#define          sz(x) x.size()
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vc vector<char>
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long int
#define          pii pair<int,int>
#define          vs vector<string>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          mst(a,v,n) fo(i,0,n) a[i]=v
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          rev(x) reverse(begin(x),end(x))
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

inline void printA( int _a[] , int _to, int _from = 0 )
{
	for( int _i = _from; _i < _to; _i++ ) cout << _a[ _i ] << ' ';
	cout << endl;
}

inline void printV( vi _a , int _to, int _from = 0)
{
	for( int _i = _from; _i < _to; _i++ ) cout << _a[ _i ] << ' ';
	cout << endl;
}

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,tt,mx = 0 ,q;
string s;
int vis[N],par[N];
pii a[N];
int dp[N],ans[N];

void go()
{
	dp[0] = 1;

	fo(i,1,mx + 1 )
	{
		if( i < k ) dp[i] = 1;
		else dp[i] = ( dp[i-1]%mod + dp[i-k]%mod )%mod;
	}

	fo(i,1,mx+1)
	{
		ans[i] = ( ans[i]%mod + ans[i-1]%mod + dp[i]%mod )%mod;
		ans[i] %= mod;
	}
}

int32_t main()
{
	INP(); 
	FAST; 
	int t =1;    
	cin>>t>>k;
	tt = t;
	int j = 0;
	test(t)
	{
		cin>>a[j].f>>a[j].sc;
		mx = max( a[j].sc , mx );
		j++;
		// db(mx);
	}
	go();

	fo(i,0,tt) cout << (ans[ a[i].sc ] - ans[ a[i].f - 1] + mod)%mod << endl;
}
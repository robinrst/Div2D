#include        "iostream"
#include        "algorithm"
#include		"numeric"
#include        "cstring"
#include        "math.h"
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
#define          N (int)3e3+5
#define          pb push_back
#define          mod 1000000007
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long int
#define          pii pair<int,int>
#define          pq priority_queue
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          db(x) cout<<#x <<" : "<< x <<endl;
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define          PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
vi adj[N],radj[N];
int vis[N];

int count( int u , int v )
{
	for( auto i : adj[u] ) vis[i] = 1;

	int cn = 0;

	for( auto j : radj[v] ) cn += vis[j];

	for( auto i : adj[u] ) vis[i] = 0;

	return (cn) * (cn-1)/2;
}

void go()
{
	cin>>n>>m;

	fo(i,0,m)
	{
		int u , v;
		cin>>u>>v;

		adj[u].pb(v);
		radj[v].pb(u);
	}

	int ans = 0;

	fo(i,1,n+1)
	{
		fo(j,1,n+1)
		{
			if( i != j )
			{
				ans += count( i , j );
			}
		}
	}

	cout << ans << endl;
	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}
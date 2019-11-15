#include        "iostream"
#include        "algorithm"
#include  		"numeric"
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
#define          N (int)2e6+5
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

int n,m,k,q,nn;
string s;
int vis[N],par[N],a[N];

int segTree[4*N];

int combine( int i , int j , int level )
{
	if( level ) return ( segTree[i] | segTree[j] );
	return ( segTree[i] ^ segTree[j] );
}

void build(int level ,int v = 1, int tl = 0 , int tr = n-1)
{
    if(tl == tr )
    {
        segTree[v] = a[tl];
        return;
    }

     int tm = (tl+tr)>>1;
 
     build( level^1, 2*v, tl, tm);
     build( level^1, 2*v+1 , tm+1, tr);

     segTree[ v ] = combine( 2*v , 2*v+1 , level);
}
 
int query(int l, int r ,int level, int v = 1, int tl = 0, int tr = n-1 )
{
    if( l > tr || r < tl) return 0;
    if( tl >= l and tr <= r )
    {
        return segTree[v];
    }

    int tm = (tl+tr)/2;
 
    int aa = query( l , r, level^1,  2*v , tl , tm );
    int bb = query( l , r, level^1,  2*v + 1 , tm+1, tr );

   	return ( level&1 ) ? aa | bb : aa ^ bb;
 
}

void update(int pos, int val, int level, int v = 1, int tl = 0 , int tr = n - 1)
{

	if( tl == tr )
	{
		segTree[ v ] = val;
		return;
	}

	int tm = (tl + tr)>>1;

	if( pos <= tm )
		update( pos, val, level^1, 2*v , tl , tm );
	else 
		update( pos , val ,level^1 , 2*v+1 , tm+1, tr);
		
	segTree[ v ] = combine( 2*v , 2*v+1 ,level);

}

void go()
{
	cin>>n>>m;
	nn = n;
	n = (1<<n);

	fo(i,0,n) cin>>a[i];

	build( (nn&1) );

	while( m-- )
	{
		int x, y;
		cin>>x>>y;
		--x;
		update( x, y,(nn&1));

		cout << segTree[1] << endl;
	}


}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}
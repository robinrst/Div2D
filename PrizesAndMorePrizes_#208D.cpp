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

int n,m,k,q,mug,tow,bicy,car,bag;
string s;
int vis[N],par[N],a[N];

struct P
{
	int mg = 0, tw = 0, bg  = 0, bi = 0 , cr = 0;
};

pair < P,int > getPrize(int po)
{
	int cr = po/ car;
	po -= max( 0LL, cr*car );
	int bi = po/bicy;
	po -= max( 0LL, bi*bicy );
	int bg = po/ bag;
	po -= max( 0LL, bg*bag );
	int tw = po/ tow;
	po -= max( 0LL, tw*tow );
	int mg = po/ mug;
	po -= max( 0LL, mg*mug );

	return { { cr , bi , bg , tw, mg } , po };

}

void go()
{
	cin>>n;

	P ans;

	fo(i,0,n) cin>>a[i];

	cin>>mug>>tow>>bag>>bicy>>car;

	int pre = 0;

	fo(i,0,n)
	{
		int points = a[i] + pre;
		// db(points);
		pair< P,int> p = getPrize(points);

		ans.cr += p.f.cr;
		ans.bi += p.f.bi;
		ans.bg += p.f.bg;
		ans.tw += p.f.tw;
		ans.mg += p.f.mg;

		pre = max( 0LL, p.sc );
	}

	cout << ans.cr << ' ' << ans.bi << ' ' << ans.bg <<' ' <<ans.tw << ' '  << ans.mg << endl;
	cout << pre << endl;
	
}

int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}
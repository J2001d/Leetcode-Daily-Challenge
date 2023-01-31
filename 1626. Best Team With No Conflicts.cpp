void __print(int x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << x; }
void __print(const char *x) { cout << x; }
void __print(const string &x) { cout << x; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) {
	cout << '{';
	__print(x.first);
	cout << ", ";
	__print(x.second);
	cout << '}';
}
template<typename T>
void __print(const T &x) {
	int f = 0;
	cout << '{';
	for (auto &i : x) {
		cout << (f++ ? ", " : "");
		__print(i);
	}
	cout << "}";
}
void _print() {
	cout << "]\n";
}
template<typename T, typename... V>
void _print(T t, V... v) {
	__print(t);
	if (sizeof...(v)) {
		cout << ", ";
	}
	_print(v...);
}

#define watch(x...) cout << "[" << #x << "] = ["; _print(x)
#define ll 				  long long
#define lld               long double
#define INF               1000000000000000000
#define pb                push_back
#define all(x)            x.begin(),x.end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define sz(x)             (int)((x).size())
#define f1                first
#define s2                second
#define fix(x)            fixed << setprecision(x)
#define endl              "\n"
#define bigprime          1000000007
#define MOD               1000000007
#define gcd(a,b)          __gcd((a),(b))
#define lcm(a,b)          (a/gcd(a,b))*b
#define scanvec(a,n)      rep(i,0,n){cin>>a[i];}
#define fast              ios_base::sync_with_stdio(false);cin.tie(NULL);
#define makeuniq(v)       v.resize(unique(all(v)) - v.begin());

/*
#define int long long
#undef int
*/

class Solution {
public:
    int dp[1005][1005];
	int helper(vector<pair<int, int>> &a, int i, pair<int, int> curr) {

		
		if (i >= sz(a)) {
			return 0;
		}
        
        if(dp[i][curr.f1] != -1){
            return dp[i][curr.f1];
        }
		int op1 = 0;

        if (a[i].f1 > curr.f1 && a[i].s2 >= curr.s2) {
			op1 = a[i].s2 + helper(a, i + 1, {max(curr.f1, a[i].f1),max(curr.s2, a[i].s2)});

		}
        
		int op2 = helper(a, i + 1, {0,0});


		return dp[i][curr.f1] = max(op1, op2);

	}

	int bestTeamScore(vector<int>& scores, vector<int>& ages) {

		// mx_age and score of curr Team members
		pair<int, int> curr = {0, 0};
        memset(dp,-1,sizeof(dp));
        
		vector<pair<int, int>> a;
        
        map<int,int> g;
        rep(i,0,sz(scores)){
            g[ages[i]] += scores[i];
        }
        for(auto x:g){
           a.pb({x.f1,x.s2}); 
        }
        watch(a);
		return helper(a, 0, curr);
	}
};

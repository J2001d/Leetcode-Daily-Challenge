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
    int dp[400][400];
    int find_next(vector<int> &days,int dayCovered){
        int n = sz(days);
        for(int i = 0;i<n;i++){
            if(days[i] > dayCovered){
                return i;
            }
        }
        return n;
    }
    
    int helper(vector<int> &days,vector<int> &costs,int dayCovered){
        int n = sz(days);
        int index = find_next(days,dayCovered);
        if(index == n){
            return 0;
        }
        if(dp[dayCovered][index] != -1){
            return dp[dayCovered][index];
        }
         
        int op1 = costs[0] + helper(days,costs,days[index]+1 - 1);
        int op2 = costs[1] + helper(days,costs,days[index]+7 - 1);
        int op3 = costs[2] + helper(days,costs,days[index]+30 - 1);
        
        return dp[dayCovered][index] = min(op1,min(op2,op3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(days,costs,0);
    }
};

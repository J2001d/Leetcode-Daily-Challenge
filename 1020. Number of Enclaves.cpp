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
    
    int helper(vector<vector<int>> &a,int i,int j,int &cnt){
        if(i < 0 || j < 0 || i >= sz(a) || j >= sz(a[0])){
            return 0;
        }
        if(a[i][j] == 0){
            return 1;
        }
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        cnt++;
        a[i][j] = 0;
        int ans1 = helper(a,i+dx[0],j+dy[0],cnt);
        int ans2 = helper(a,i+dx[1],j+dy[1],cnt);
        int ans3 = helper(a,i+dx[2],j+dy[2],cnt);
        int ans4 = helper(a,i+dx[3],j+dy[3],cnt);
        
        return ans1 && ans2 && ans3 && ans4;
    }
    int numEnclaves(vector<vector<int>>& a) {
        int n = sz(a);
        int m = sz(a[0]);
        int ans = 0;
        rep(i,0,n){
            rep(j,0,m){
                if(a[i][j] == 1){
                    int cnt = 0;
                    if(helper(a,i,j,cnt)){
                        // watch(i);
                        // watch(j);
                        ans += cnt;
                    }
                }
            }
        }
        
        
        
        return ans;
        
    }
};

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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
            
        vector<int> ans(n,-1);
        
        
        // 0->red 1->blue  for a node -> {red,0}{blue,1} like that
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>()); 

        for(auto x:redEdges){
            adj[x[0]].pb({x[1],0}); // 0 means red edge
        }
        for(auto x:blueEdges){
            adj[x[0]].pb({x[1],1}); // 1 means blue edge
        }
        
        
        queue<vector<int>> q; // {node,prevColor,distance till here}
        
        q.push({0,-1,0});
        
        while(sz(q)){
                
            auto ele = q.front();q.pop();

            int node = ele[0];
            int color = ele[1];
            int dist = ele[2];
            
            if(ans[node] == -1){
                ans[node] = dist;
            }
            for(auto &nbr:adj[node]){
                if(nbr.s2 != color && nbr.f1 != -1){
                    q.push({nbr.f1,nbr.s2,dist+1}); 
                    
                    // making it visited
                    nbr.f1 = -1;
                }
            }
            
            
        }
        
        return ans;
    }
};

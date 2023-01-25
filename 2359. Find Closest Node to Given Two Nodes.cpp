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
class Solution {
public:
    void bfs(vector<vector<int>>&edges,int node,vector<int> &dist,int n){
        queue<int> q;
        vector<int> visited(n);
        q.push(node);
        visited[node] = 1;
        dist[node] = 0;
        while(!q.empty()){
            int qsize = q.size();
            rep(tp,0,qsize){
                int ele = q.front();
                q.pop();
                for(auto nbr:edges[ele]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        dist[nbr] = dist[ele]+1;
                        visited[nbr] = 1;
                    }
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& g, int node1, int node2) {
        int n = sz(g);
        vector<vector<int>> edges(n,vector<int>());
        
        rep(i,0,n){
            if(g[i] != -1)
                edges[i].pb(g[i]);
        }
    
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        
        bfs(edges,node1,dist1,n);
        bfs(edges,node2,dist2,n);
        
        // watch(dist1);
        // watch(dist2);
        
        vector<pair<int,int>> ans;
        rep(i,0,n){
            if(dist1[i] != -1 && dist2[i] != -1){
                ans.pb({max(dist1[i],dist2[i]),i});
            }
        }
        sort(all(ans));
        
        return sz(ans) == 0 ? -1 : ans[0].s2;
    }
};

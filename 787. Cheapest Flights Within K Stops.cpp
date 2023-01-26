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
// priority queue
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		// adj list

		unordered_map<int, vector<vector<int>>> adj;

		for (auto &x : flights) {
			adj[x[0]].pb({x[1], x[2]});
		}
		// minHeap
		pqg<vector<int>> pq; // cost , src, stopsTaken

		pq.push({0, src, 0});

		// To store ki is Node tak kitne stops lage
		vector<int> dist(n + 1, INT_MAX);

		while (!pq.empty()) {
			auto ele = pq.top(); pq.pop();
			// ele[0] is cost
			// ele[1] is currNode
			// ele[2] is stopsTaken
			int cost = ele[0];
			int currNode = ele[1];
			int stopsTaken = ele[2];

			if (currNode == dst) {
				return cost;
			}

			// agar currNode ke stops already calulated hai aur agar kam hai to hum kyu usko wapis traverse kre
			// sidha continue krr dete hai
			if (dist[currNode] < stopsTaken) {
				continue;
			}
			// dist[CurrNode] = StopsTaken
			dist[currNode] = stopsTaken;

			// Only K stops are allowed so if more than K than continue;
			if (stopsTaken > k) {
				continue;
			}

			// Now traversing over nbr

			for (auto nbr : adj[currNode]) {
				// nbr is a vector<int> with destination and cost
				pq.push({cost + nbr[1] , nbr[0] , stopsTaken + 1});
			}

		}





		return -1;
	}
};


// This approach is applicable when Cost is same if cost is diff the we have to use Dijkstra
// Simple BFS
// Find K levels from src
// wheneven you find dest calculate the cost

// In dijkstra we use pq(minHeap) so that we can have small weight is front whenever we visit a node and push that

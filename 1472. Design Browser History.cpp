class BrowserHistory {
public:
	stack<string> B;
	stack<string> F;

	BrowserHistory(string homepage) {
		B.push(homepage);
		F = stack<string>(); //resets stack
	}

	void visit(string url) {
		B.push(url);
		F = stack<string>();
	}

	string back(int steps) {
		while (steps > 0 && B.size() > 1) {
			F.push(B.top());
			B.pop();
			steps--;
		}
		return B.top();
	}

	string forward(int steps) {
		while (steps > 0 && F.size() > 0) {
			B.push(F.top());
			F.pop();
			steps--;
		}
		return B.top();
	}
};

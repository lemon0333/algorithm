#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int sol(int W, vector<int> wt, vector<int> valt, int N) {
	vector<vector<int>> con(N+1,vector<int> (W+1,0));
	for (int i = 0;i <= N ;i++) {
		for (int w = 0;w <= W ;w++) {
			if (i == 0 || w == 0)
				con[i][w] = 0;
			else if (wt[i - 1] <= w)
				con[i][w] = max(valt[i - 1] + con[i - 1][w - wt[i - 1]], con[i - 1][w]);
			else
				con[i][w] = con[i - 1][w];
		}
	}
	return con[N][W];
}

int main() {
	int W;
	int N;
	int K;
	cin >> N >> K;
	int V;
	vector<int> allweight;
	vector<int> allvalue;
	for (int i = 0;i < N;i++) {
		cin >> W >> V;
		allweight.push_back(W);
		allvalue.push_back(V);
	}
	cout << sol(K, allweight, allvalue, N);
}
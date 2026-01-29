#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n; int checkN = 0; int p0 = 0; int p1 = 0;
int result = 987654321;
int p[20]; int comp[20]; int visited[20];
vector<vector<int>> g(20);


void Init()
{
	fill(&comp[0], &comp[0] + 20, 0);
	fill(&visited[0], &visited[0] + 20, 0);
	checkN = 0; p0 = 0; p1 = 0;
}

void dfs(int index, int num)
{	
	visited[index] = 1;
	checkN++;		//방문했던 노드 수를 올려줌
	//cout << "index : " << index << "\n";
	if (num == 0) {
		p0 += p[index];		//인구수를 더해준다.
		//cout << "index : " << index << "   p0 :" << p0 << "\n";
	}
	else {
		p1 += p[index];
		//cout << "i : " << index << "   p1 :" << p1 << "\n";
	}

	for (int i : g[index]) {		//i -> index와 연결된 노드들을 순차적으로 나타냄
		if (comp[i] != num) continue;	//i노드가 같은 선거구가 아니면 continue
		if (visited[i]) continue;	//i노드가 이미 방문한 노드라면 continue

		//if (num == 0) {
		//	p0 += p[i];		//인구수를 더해준다.
		//	cout << "i : " << i << "   p0 :" << p0  <<"\n";
		//}
		//else{
		//	p1 += p[i];
		//	cout << "i : " << i << "   p1 :" << p1 << "\n";
		//}

		dfs(i, num);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {		//인구 수 입력
		int t; cin >> t;
		p[i] = t;
	}

	for (int i = 1; i <= n; i++) {				//gragh 제작
		int loop; cin >> loop;
		for (int j = 1; j <= loop; j++) {
			int t; cin >> t;
			g[t].push_back(i);
			g[i].push_back(t);
		}
	}

	//g[i]가 제대로 들어갔는지 확인 -> 오류 확인 j<loop였음.
	//for (int i = 1; i <= n; i++) {
	//	cout << i<<" in ";
	//	for (int j : g[i]) {
	//		cout << j << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 1; i < (1 << n) - 1; i++) {
		int count = 1; int index0 = 0, index1 = 0;
		Init();

		for (int j = 1; j < (1 << n); j = j*2) {
			if (i & j) {
				comp[count] = 1;
				index1 = count;			//count -> Node Numder
			}
			else {
				index0 = count;
			}
			count++;
		}

		//cout << "num = 0\n";
		dfs(index0, 0);
		//cout << "num = 1\n";
		dfs(index1, 1);

		if (n != checkN) continue;

		int subResult = abs(p0 - p1);


		//cout << "i : " << i << "    subResult : " << subResult << "\n";
		//cout << "p0 : " << p0 << "   p1 : " << p1 << "\n\n";

		result = min(subResult, result);
	}

	if (result != 987654321) {
		cout << result;
	}
	else cout << -1;
}
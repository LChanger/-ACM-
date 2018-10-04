#include<iostream>
#include<string>
#include<vector>
using namespace std;
int T;
int N, K, M;
int flag[15] = { 0 };
void  dfs(int k,vector<vector<int>> &chart);
int dfscount(vector<vector<int>> &chart);
int main(){
	int a, b;
	a = 7;
	b = a & 2;
	cout << b << endl;
	//cin >> T;
	//for (int m=0; m < T;++m){
	//	cin >> N >> M >> K;
	//	vector<vector<int>> chart(N, vector<int>(N));
	//	for (int i = 0; i<N; ++i){
	//		cout << endl;
	//		for (int j = 0; j<N; ++j){
	//			cout << chart[i][j]<<"  ";
	//		}
	//	}

	//	cout << endl;
	//	while (M > 0){
	//		cin >> a >> b;
	//		chart[a-1][b-1] = 1;
	//		--M;
	//	}
	//	vector<vector<int>> chart2(chart);
	//	for (int i = 0; i < N; ++i){
	//		for (int j = i+1; j < N; ++j){
	//			if (chart2[i][j] == 1){
	//				chart2[i][j] = 0;
	//			}
	//		}
	//	}
	//	cout << dfscount(chart) << endl;
	//}
	system("pause");
}
void dfs(int k,vector<vector<int>> &chart){
	flag[k] = 1;
	for (int j = 0; j < N; ++j){
		if (0==flag[j]&&1 == chart[k][j]){
			dfs(j,chart);
		}
	}
}
int dfscount(vector<vector<int>> &chart){
	int count = 0;
	for (int i = 0; i < N; ++i){
		if (flag[i] == 0){
			dfs(i,chart);
			++count;
		}
	}
	memset(flag, 0, 15 * sizeof(int));
	return count;
}
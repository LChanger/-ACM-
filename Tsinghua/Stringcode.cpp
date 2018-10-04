#include<iostream>
#include<string>
#include<vector>
using namespace std;
void  compress(string &str);
void dfs(int i, int j, vector<vector<char>> &a);
int result[100];
int m, n;
int direction[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
int main5(){
	cin >> m >> n;
	int count = 0;
	while (m != 0){
		vector<vector<char>> a(m, vector<char>(n));
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				cin>>a[i][j];
			}
		}
		//for (int i = 0; i < m; ++i){
		//	cout << endl;
		//	for (int j = 0; j < n; ++j){
		//		cout<<a[i][j]<<"     ";
		//	}
		//}
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (a[i][j] == '@'){ dfs(i, j, a); result[count]++; }
			}
		}
		//for (int i = 0; i < m; ++i){
		//	cout << endl;
		//	for (int j = 0; j < n; ++j){
		//		cout << a[i][j] << "     ";
		//	}
		//}
		count++;
		cin >> m >> n;
	}
	for (int i = 0; i < count; ++i){
		cout << result[i] << endl;
	}
	return 0;
}
void dfs(int i, int j, vector<vector<char>> &a){
	int fx, fy;
	for (int k = 0; k < 8; ++k){
		fx = i + direction[k][0];
		fy = j + direction[k][1];
		if (fx >= 0 && fx < m&&fy >= 0 && fy < n&&a[fx][fy] == '@'){
			a[fx][fy] = '*';
			dfs(fx, fy, a);
		}
	}
}
int main4(){
	string str;
	while (cin >> str){
		compress(str);
		cout << str << endl;
	}

	system("pause");
	return 0;
}
void compress(string &str){
	int count = 1;
	int i = 0;
	int pos = 0;
	while (i < str.length() - 1){
		if (str[i] == str[i + 1]){ ++count; ++i; }
		else if (count > 1) {
			str.erase(pos, count - 1);
			str.insert(pos, to_string(count));
			i = i - count + to_string(count).length() + 2;
			pos = pos + to_string(count).length() + 1;
			count = 1;
		}
		else { ++pos; ++i; }
	}
	if (count>1){
		str.erase(pos, count - 1);
		str.insert(pos, to_string(count));
	}	
}
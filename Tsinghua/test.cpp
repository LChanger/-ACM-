#include"iostream"
#include <string.h>
using namespace std;
bool judge(float *a, int index, float res, int n);
int main1(){
	int n;
	while (cin>>n){
		cout << "hello word " << endl;
		float *a = (float *)malloc(n*sizeof(float));
		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i){
			cout << a[i] << endl;
		}
		float res;
		cin >> res;
		if (judge(a, 0, res, n))cout << '1';
		else cout << '0';
	}
	
	return 0;
}
bool judge(float *a, int index, float res,int n){
	if (index == n - 1){ if (a[index] == res)return true; return false; }
	else if (judge(a, index + 1, res - a[index], n))return true;
	else if (judge(a, index + 1, a[index] - res, n))return true;
	else {
		float temp = a[index + 1];
		a[index + 1] = a[index] * a[index + 1];
		if (judge(a, index + 1, res, n))return true;
		a[index + 1] = temp;
		//cout << "nihao" << endl;
		a[index + 1] = a[index] / a[index + 1];
		if (judge(a, index + 1, res, n))return true;
		a[index + 1] = temp;
	}
	return false;
}

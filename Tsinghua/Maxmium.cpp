#include"iostream"
#include <string>
using namespace std;
int maxmium(int a[], int size);
int main2(){
	int n;
	while (cin >> n){
		int *p = (int*)malloc(n*sizeof(int));
		for (int i = 0; i < n; ++i){
			cin >> p[i];
		}
		cout<<maxmium(p,n)<<endl;
		free(p);
	}

	return 0;
}
int maxmium(int a[], int size){
	int i, j;
	i = 0;
	j = 0;
	int max = 0;
	int nowsum = 0;
	for (int k = 0;k < size; ++k){
		nowsum += a[k];
		if (nowsum>max){
			j = k;
			max = nowsum;
		}
		else if (nowsum < 0){
			nowsum = 0;
			i = k;
		}
	}
	return max;
}
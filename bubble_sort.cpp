#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int t=0;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i <n-j-1; i++) {
			if (arr[i] > arr[i + 1]) {
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] <<' ';
	}
	system("pause");
	return 0;
}
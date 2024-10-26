#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr){
	for (int i = 1; i < arr.size(); i++)
		for(int j = i; j > 0 && arr[j-1] < arr[j]; j--)
			swap(arr[j], arr[j-1]);	
}

int main(){
	vector<int> arr = {23, 1, 10, 5, 2};
	insertionSort(arr);
	for(auto& i: arr){
		cout << i << " ";
	}
}
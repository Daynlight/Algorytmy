#include "Algorytmy.h"

int main() {
	int arrIn[32] = {1, 2, 3, 4 ,1 ,2 ,2,5 ,6 ,7, 4, 4, 3, 4,4,3,3,4,2,5, 4,2,3,4,5,2,1,5,32,25,32,5};
	Array<int> arr;
	
	arr.arr.reserve(32);
	for (int& el : arrIn)
		arr.arr.emplace_back(el);

	for (int i = 0; i < 32; i++)
		printf("%d ", arr.arr[i]);
	
	printf("%d", arr.sumaBaseReq());


	return 0;
}
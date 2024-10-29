#include "Algorytmy.h"
#include <iostream>
#include <chrono>

int main() {
	int arrIn[5] = {1, 2, 3, 4, 5};
	
	Array arr;
	
	arr.arr.reserve(10);
	for (int& el : arrIn)
		arr.arr.emplace_back(el);

	printf("\n");
	std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();
	printf("Suma: %d", arr.sumaBaseReq());
	std::chrono::high_resolution_clock::time_point End = std::chrono::high_resolution_clock::now();
	printf("\n");

	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::duration(End - Start));
	std::cout << "Time: " << duration.count() << " ms\n";

	printf("\n");
	Start = std::chrono::high_resolution_clock::now();
	printf("Suma: %d", arr.sumaThreadReq());
	End = std::chrono::high_resolution_clock::now();
	printf("\n");

	duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::duration(End - Start));
	std::cout << "Time: " << duration.count() << " ms\n";


	return 0;
}
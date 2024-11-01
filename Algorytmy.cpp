#include "Algorytmy.h"

void Time(std::function<void()> fun) {
	std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();

	fun();

	std::chrono::high_resolution_clock::time_point End = std::chrono::high_resolution_clock::now();
	std::chrono::duration duration = std::chrono::duration(End - Start);

	std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(duration);
	std::chrono::milliseconds milisec = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
	std::chrono::nanoseconds nansec = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

	printf("Time: %Id s | %Id ms | %Id ns\n", sec.count(), milisec.count(), nansec.count());
}
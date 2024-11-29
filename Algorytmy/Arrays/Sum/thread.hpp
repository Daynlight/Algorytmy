#include "../Array.h"

template<typename T>
T Array<T>::threadSum(size_t thread_level) { return halfThreadSumReqFun(0, data_array.size() - 1, thread_level); }

template<typename T>
T Array<T>::halfThreadSumReqFun(const size_t x, const size_t y, size_t&thread_level) {
	if (y - x == 0) return data_array[x];
	else if (y - x == 1) return data_array[x] + data_array[y];
	else if (y - x < 0) return 0;

	T a = 0, b = 0;
	if (thread_level > 0) {
		thread_level--;
		std::future<T> eventA =
			std::async(std::launch::async, [this, &x, &y, &thread_level] { return halfThreadSumReqFun(x, (y - x) / 2 + x, thread_level); });

		b = halfThreadSumReqFun((y - x) / 2 + x + 1, y, thread_level);
		a = eventA.get();
	}
	else {
		a = halfThreadSumReqFun(x, (y - x) / 2 + x, thread_level);
		b = halfThreadSumReqFun((y - x) / 2 + x + 1, y, thread_level);
	}

	return a + b;
}
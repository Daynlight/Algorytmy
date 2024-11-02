int Time(std::function<void()> fun)
{
	std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();

	fun();

	std::chrono::high_resolution_clock::time_point End = std::chrono::high_resolution_clock::now();
	std::chrono::duration delta = std::chrono::duration(End - Start);

	std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(delta);
	std::chrono::milliseconds milisec = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
	std::chrono::nanoseconds nansec = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);

	printf("Time: %ld s | %ld ms | %ld ns\n", sec.count(), milisec.count(), nansec.count());

	return delta.count();
}

template <typename T>
T Random(T x, T y) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<T> dist(x, y);
	return dist(rng);
}
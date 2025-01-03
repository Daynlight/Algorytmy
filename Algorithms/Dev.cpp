#include "Dev.h"

void checkClock(){
	printf("\n****[Checking Clock Accuracy]****\n");
	printf("Clock test 100ms: ");
	printTime(Time(10, [] { std::this_thread::sleep_for(std::chrono::milliseconds(100)); }));
}

ProgressBar::ProgressBar(const size_t last, const size_t size)
	: last(last), size(size) {}

void ProgressBar::render(const size_t current) {
	const float percentage = static_cast<float>(current_step) / size;

	if (current > static_cast<float>(last / size) * current_step) {
		for (size_t i = 0; i < res.size(); i++)
			printf("\b");
		res.clear();

		res += "(";
		for (size_t i = 0; i < current_step; i++)
			res += "#";
		for (size_t i = 0; i < size - current_step; i++)
			res += " ";
		res += ")";
		res += std::to_string(static_cast<int>(percentage * 100));
		res += "%";
		printf("%s", res.c_str());

		current_step++;
	}
	if (current == last - 1) {
		for (size_t i = 0; i < res.size(); i++)
			printf("\b");
		res.clear();

		res += "(";
		for (size_t i = 0; i < size; i++)
			res += "#";
		res += ")";
		res += "100%\n";
		printf("%s", res.c_str());

		current_step++;
	};
}

const std::chrono::nanoseconds Time(const std::function<void()> function) {
	const std::chrono::high_resolution_clock::time_point Start = std::chrono::high_resolution_clock::now();

	function();

	const std::chrono::high_resolution_clock::time_point End = std::chrono::high_resolution_clock::now();
	const std::chrono::duration delta = std::chrono::duration(End - Start);

	return delta;
}

const std::chrono::nanoseconds Time(size_t n, const std::function<void()> function) {
	std::chrono::nanoseconds sum = std::chrono::nanoseconds(0);
	for(size_t i = 0; i < n; i++)
		sum += Time(function);
	return sum/n;
}

void printTime(const std::chrono::nanoseconds delta) {
	const std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(delta);
	const std::chrono::milliseconds miliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(delta);
	const std::chrono::nanoseconds nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(delta);

	printf("%lld s | %lld ms | %lld ns\n", seconds.count(), miliseconds.count(), nanoseconds.count());
}

int random(const int x, const int y) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(x, y);
	return dist(rng);
}


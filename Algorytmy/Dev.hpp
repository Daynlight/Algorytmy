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

PROGRESSBAR::PROGRESSBAR(int last, int size) {
	this->last = last;
	this->size = size;
	step = last / size;
}

void PROGRESSBAR::Render(int current) {
	percentage = static_cast<float>(current_step) / size;

	if (current == 0) {
		res += "(";
		for (int i = 0; i < size; i++)
			res += " ";
		res += ")";
		res += std::to_string(static_cast<int>(percentage * 100));
		res += "%";
		printf("%s", res.c_str());
		current_step++;
	}
	else if (current > step * current_step) {
		for (int i = 0; i < res.size(); i++)
			printf("\b");
		res.clear();
		res += "(";
		for (int i = 0; i < current_step; i++)
			res += "#";
		for (int i = 0; i < size - current_step; i++)
			res += " ";
		res += ")";
		res += std::to_string(static_cast<int>(percentage * 100));
		res += "%";
		printf("%s", res.c_str());
		current_step++;
	}
	if (current == last - 1) {
		for (int i = 0; i < res.size(); i++)
			printf("\b");
		res.clear();
		res += "(";
		for (int i = 0; i < size; i++)
			res += "#";
		for (int i = 0; i < size - current_step; i++)
			res += " ";
		res += ")";
		res += "100%\n";
		printf("%s", res.c_str());
		current_step++;
	};
}
#pragma once
#include <future>
#include <random>
#include <functional>
#include <chrono>

static bool FORCEPRINTARRAY = 0;
static int MAXARRAYPRINTSIZE = 1001;

const std::chrono::nanoseconds Time(const std::function<void()> function);
void printTime(const std::chrono::nanoseconds delta);
int random(const int x, const int y);

class ProgressBar {
public:
	ProgressBar(const size_t last = 100, const size_t size = 50);
	void render(const size_t current);
private:
	const size_t size = 50;
	const size_t last = 100;
	int current_step = 0;
	std::string res = "";
};
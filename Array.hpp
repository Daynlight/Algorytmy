template<typename T>
ARRAY<T>::ARRAY() {
}

template<typename T>
ARRAY<T>::ARRAY(std::initializer_list<T> inArr) {
	arr.reserve(inArr.size());
	for (const int el : inArr)
		arr.emplace_back(el);
}

template<typename T>
template<typename S>
S ARRAY<T>::sumaBaseReq() {
	return sumaBaseReqFun(0);
}

template<typename T>
template<typename S>
S ARRAY<T>::sumaBaseReqFun(int x) {
	if (x >= arr.size()) return 0;
	return arr[x] + sumaBaseReqFun(x + 1);
}

template<typename T>
size_t ARRAY<T>::size() {
	return arr.size();
}

template<typename T>
void ARRAY<T>::reserve(int n) {
	arr.reserve(n);
}

template<typename T>
void ARRAY<T>::emplace_back(int n) {
	arr.emplace_back(n);
}

template<typename T>
template<typename S>
S ARRAY<T>::sumaThreadReq() {
	return sumaThreadReqFun<S>(0, arr.size() - 1);
}

template<typename T>
template<typename S>
inline S ARRAY<T>::sumaLine() {
	S suma = 0;
	for (int i = 0; i < arr.size(); i++)
		suma += static_cast<S>(arr[i]);
	return suma;
}

template<typename T>
template<typename S>
S ARRAY<T>::sumaThreadReqFun(int x, int y) {
	if (y - x == 0) return arr[x];
	else if (y - x == 1) return arr[x] + arr[y];
	else if (y - x < 0) return 0;

	S a = 0, b = 0;
	if (ThreadsLevel < THREADSDEEPLEVEL) {

    THREAD<S> eventA = THREAD<S>([this,&x,&y] { return sumaThreadReqFun<S>(x, (y - x) / 2 + x); });

		ThreadsLevel++;
		b = sumaThreadReqFun<S>((y - x) / 2 + x + 1, y);
		a = eventA.get();
	}
	else {
		a = sumaThreadReqFun<S>(x, (y - x) / 2 + x);
		b = sumaThreadReqFun<S>((y - x) / 2 + x + 1, y);
	}

	return a + b;
}

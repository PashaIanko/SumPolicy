#pragma once
#include <string>

const double ACCURACY = 0.005;


template <typename T>
class SumTraits;//class declaration. КОгда хедер два раза прописываю, выскакивают ошибки


template<typename T>
class CmpPolicy {
public:
	static bool cmp(const T &a, const T &b) {
		return a == b;
	}
};

/*template <typename T>
class CmpPolicy {
public:
	static bool cmp(const T &a, const typename SumTraits<T>::SumT &b) {
		return true;
	}
};*/

template<>
class CmpPolicy<double> {
public:
	static bool cmp(const double a, const double b) {
		return abs(a - b) < ACCURACY;
	}
};

/*template <>
class CmpPolicy <std::string> {
	static bool cmp(const std::string &a, const std::string &b)
	{
		return strcmp()
	}
};*/


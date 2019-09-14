#pragma once
#include <string>
#include <array>
#include <vector>

template<typename T>
class CmpPolicy {
public:
	static const bool is_equal(const T &a, const T &b) {
		return a == b;
	}
};



template<>
class CmpPolicy<std::string> {
public:
	static const bool is_equal(const std::string &a, const std::string &b) {
		return !(a.compare(b));
	}
};


template<class T>
class CmpPolicy<std::vector<T>> {
public:
	static const bool is_equal(const std::vector<T> &a, const std::vector<T> &b) {
		if (a.size() == b.size()) {
			return a == b;
		}
		else
			return false;
	}
};

template<int N>
class CmpPolicy<char[N]> {
public:
	static const bool is_equal( char const (&a)[N], char const (&b)[N]) {
		return !strcmp(a, b);
	}
};



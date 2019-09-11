#pragma once

#include <string>

template <typename T>
class SumTraits {
public:
	typedef T SumT;
	static SumT zero() { return T{}; }
};

template <>
class SumTraits<char> {
public:
	typedef std::string SumT;
	static SumT  zero() { return ""; }
};

template <>
class SumTraits<std::string> {
public:
	typedef std::string SumT;
	static SumT  zero() { return ""; }
};

template <>
class SumTraits<unsigned char> {
public:
	typedef std::string SumT;
	static SumT  zero() { return ""; }
};


template<>
class SumTraits<short> {
public:
	typedef long SumT;
	static SumT zero() { return 0; }
};

template<>
class SumTraits<unsigned short> {
public:
	typedef unsigned long SumT;
	static SumT zero() { return 0; }
};

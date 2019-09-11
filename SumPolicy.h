#pragma once


class SumPolicy {
public:
	template <typename T1, typename T2>
	static void accumulate(T1 &total, const T2 &val) {
		total += val;
	}
};
#pragma once
/*SimplePolicy - in case if a numeric value is an argument, but not a container*/
template <typename T>
class SumTraits;

class SimplePolicy {
public:
	template <typename T,
			  typename Traits = SumTraits<T>>
		static T count_sum(const T &numeric_val) { return numeric_val; }
};
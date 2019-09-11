#pragma once
#include <type_traits>
#include <vector>
#include "SumTraits.h"
#include "CountContainers.h"
#include "SimplePolicy.h"


template<typename T,
         typename CountPolicy = CountContainers,
		 typename Traits = SumTraits<T>>

	inline typename Traits::SumT sum_all(const std::vector<T> &data) {
	return CountPolicy::count_sum(data);
}



template<typename T,
	     typename CountPolicy = typename std::enable_if<std::is_arithmetic<T>::value, SimplePolicy>::type,
		 typename Traits = SumTraits<T>>

	inline typename Traits::SumT sum_all(const T &data) {
	return CountPolicy::count_sum(data);
}


/*template<typename T,
		 typename Traits = SumTraits<T>>

inline typename Traits::SumT sum_all(const T &data) {
	typename Traits::SumT res = data;
	return res;
}*/
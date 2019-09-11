#pragma once
#include "SumPolicy.h"
#include <list>

template <typename T>
class SumTraits;


class CountContainers {
public:
	template <typename T,
			  typename Policy = SumPolicy,
			  typename Traits = SumTraits<typename T::value_type>>
	static typename SumTraits<typename T::value_type>::SumT count_sum(const T &data) {

		typename Traits::SumT  res = Traits::zero();		
		for (auto it: data) {
			Policy::accumulate(res, it);
		}
		return res;
	}

	template <typename T,
		typename Policy = SumPolicy,
		typename Traits = SumTraits<T>>
	static typename SumTraits<T>::SumT count_sum(const std::list<T> &data) {

		typename Traits::SumT  res = Traits::zero();
		auto it = data.cbegin();
		auto end = data.cend();

		while (it != end) {
			Policy::accumulate(res, *it);
			++it;
		}
		return res;
	}
};
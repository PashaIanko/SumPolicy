#pragma once
#pragma once
#include <vector>
#include "cmp_policy.h"


template <typename T>
class SumTraits;//class declaration. КОгда хедер два раза прописываю, выскакивают ошибки


template 
   <typename T,
	typename Traits = SumTraits<T>,
	typename Policy = CmpPolicy<T>>
	
inline bool test_func(const std::vector<T> &data, const typename SumTraits<T>::SumT &expect)
{

	typedef typename Traits::SumT SumT;

	SumT sum = sum_all(data);

	return Policy::cmp(sum, expect);
	
}


//full specialization of test_func
template <typename T,
		  typename = typename std::enable_if<std::is_arithmetic<T>::value>,
		  typename Policy = CmpPolicy<T>>
	const bool test_func(const std::vector<T> &data, const T &expect)
{
	typedef typename SumTraits<T>::SumT SumT;
	SumT sum = sum_all(data);
	return Policy::cmp(sum, expect);
}


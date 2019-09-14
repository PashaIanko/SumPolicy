#pragma once


#include <fstream>
#include <iostream>
#include <string>
#include "serialize.h"
#include "CmpPolicy.h"
#include <vector>

template<typename T>
class CmpPolicy;


template <typename T,
		  typename Policy = CmpPolicy<T>>
const bool test_func(const T const &data, const T const &expect)
{
	std::ofstream ofs("test.ser", std::ofstream::out | std::ofstream::binary);
	
	
	serialize(data, ofs);
	ofs.close();

	std::ifstream ifs("test.ser", std::ifstream::in | std::ofstream::binary);
	ifs >> std::noskipws;

	T deser_res;

	deserialize(deser_res, ifs);
	ifs.close();
	const bool res = Policy::is_equal(deser_res, expect);

	return res;
}

template<typename T,
		 typename Policy = CmpPolicy<std::vector<T>>>
	const bool test_func(const std::vector<T> &data, const std::vector<T> &expect)
{
	std::ofstream ofs("test.ser", std::ofstream::out | std::ofstream::binary);
	serialize(data, ofs);
	ofs.close();

	std::ifstream ifs("test.ser", std::ifstream::in | std::ofstream::binary);
	ifs >> std::noskipws;

	std::vector<T> deser_res;

	deserialize(deser_res, ifs);
	//ifs.close();
	const bool res = Policy::is_equal(deser_res, expect);

	return res;
}

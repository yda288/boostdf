// BoostDF.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/python/stl_iterator.hpp>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <boost/python/numpy.hpp>

namespace np = boost::python::numpy;
namespace python = boost::python;


typedef std::map<std::string, np::ndarray> NpArrMap;

std::string test_df(const boost::python::dict& py_dict) {
	boost::python::list keys = py_dict.keys();
	NpArrMap map_;
	
	for (int i = 0; i < len(keys); ++i) {
		std::string key = boost::python::extract<std::string>(keys[i]);
		boost::python::object valobj = boost::python::extract<python::object>(py_dict[key]);
		np::ndarray valarray = np::array(boost::python::extract<np::ndarray>(valobj.attr("values")));
		map_.insert(std::pair<std::string, np::ndarray>(key, valarray));
	}
	std::ostringstream s;
	for (auto elem : map_)
	{
		s << elem.first << " " << python::extract<char const *>(python::str(elem.second)) << std::endl;
	}

	return s.str();
	
}


BOOST_PYTHON_MODULE(BoostDF)
{
	
	Py_Initialize();
	np::initialize();
	python::def("test_df", &test_df);

}



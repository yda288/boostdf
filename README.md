# boostdf
Pandas DataFrame conversion to C++

Recently I needed to get a DataFrame into C++ for performance reasons. Naturally, you should prefer the idiomatic Pandas and Numpy vectorised approach wherever possible, however, if you really need to get your DataFrame into C++ this example demonstrates a very basic first attempt. Uses the DataFrame.to_dict() with boost::python::dict to represent the DataFrame as an STL (unordered?) map of string, numpy.ndarray.
Fetch the object and pick off the values attribute for each Series, accessing the underlying numpy array. 

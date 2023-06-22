# distutils: language = c++
# cython: language_level = 3
from libcpp.vector cimport vector
from libcpp.string cimport string

cdef extern from "../csrc/Test.h" namespace "testSpace":
    ctypedef float precision_t
    cdef cppclass Test:
        Test() except + 
        void fit(vector[vector[int]]&, vector[int]&, vector[precision_t]&) except +
        void print()
        string version()
        
cdef class CTest:
    cdef Test *thisptr
    def __cinit__(self):
        self.thisptr = new Test()
    def __dealloc__(self):
        del self.thisptr
    def fit(self, X, y, weights):
        self.thisptr.fit(X, y, weights)
        return self
    def print(self,):
        self.thisptr.print()
        return self
    def get_version(self):
        return self.thisptr.version()
    def __reduce__(self):
        return (CTest, ())
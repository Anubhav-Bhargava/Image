from libcpp.string cimport string

cdef extern from "ela_final.cpp":    
    string func (string filename)


def myfunc(filename):
  return func(filename)


 

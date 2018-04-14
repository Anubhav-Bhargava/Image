cdef extern from "ela_final.cpp":    
    void func (char* filename)


def myfunc(filename):
  func(filename)


 

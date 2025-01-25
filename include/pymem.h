#ifndef PYMEM_H
#define PYMEM_H

#include "pycore_runtume.h"
#include "object.h"
void* PyObject_Malloc(Py_ssize_t size ){
    return _PyObject.malloc(_PyObject.ctx,size);
}
static inline void*
_PyObject_MallocWithType(PyTypeObject* tp) {
    Py_ssize_t size = tp->tp_basicsize ;
    void* mem = PyObject_Malloc(size) ;
    return mem;
}
#endif

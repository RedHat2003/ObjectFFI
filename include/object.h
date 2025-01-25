#ifndef OBJECT_H 
#define OBJECT_H 
#include "core_object.h"


// Definition of PyTypeObject
typedef struct _typeobject {
    PyVarObject obv_base;
    const char* tp_name;
    Py_ssize_t tp_basicsize;
    Py_ssize_t tp_itemsize;
} PyTypeObject;

// Declaration of PyType_Type as an external variable
extern PyTypeObject PyType_Type;


#endif

#ifndef CORE_OBJECT
#define CORE_OBJECT
#include <sys/types.h>
#include <stdlib.h>

//Forward dec

typedef struct typeobject PyTypeObject;
typedef ssize_t Py_ssize_t ;
typedef struct _object {
    Py_ssize_t ob_refcnt ;
    PyTypeObject* ob_type ;
}PyObject;

typedef struct {
    PyObject ob_base ;
    Py_ssize_t size ;
}PyVarobject ;
//useful macros
#define PyVarobject_HEAD PyVarobject ob_base ;
#endif


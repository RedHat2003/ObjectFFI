//include/core_types.h
#ifndef CORE_TYPES_H 
#define  CORE_TYPES_H 
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>

typedef enum {
    MetaData = 1
}ExtensionType;

typedef struct Node {
    size_t struct_size; 
    ExtensionType type ; 
    struct Node* next ;
}ExtensionNode;

typedef ssize_t Py_ssize_t ; 

// Forward declaration of struct _typeobject 
typedef struct _typeobject PyTypeObject ; 

typedef struct _object {
    ExtensionNode* extension_start; 
    Py_ssize_t ob_refcnt ;
    PyTypeObject* ob_type ; 
}PyObject;

typedef struct {
    PyObject ob_base ; 
    Py_ssize_t ob_size ; 
}PyVarObject;

// Define useful Macros 
#define PyVarObject_HEAD PyVarObject ob_base ; 
#define PyObject_HEAD PyVarObject ob_base ; 
#endif

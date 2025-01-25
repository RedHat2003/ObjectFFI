#ifndef OBJECT
#define OBJECT
#include "core_objects.h"

typedef enum {
    Metadata = 1
}ExtensionType;

typedef struct  Node {
    ExtensionType type ;
    struct Node* next ;
}ExtensionNode;
typedef struct {
    Py_ssize_t ext_size ;
    ExtensionNode* extension_start ;
}Extension;

#define Extension_HEAD Extension ext_base ;

typedef struct typeobject {
    Extension_HEAD
    PyVarobject_HEAD
    Py_ssize_t tp_basicsize , tp_itemsizes;
    char* tp_name ;
}PyTypeObject ;

#endif


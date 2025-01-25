#include <stdlib.h>
#include <stdio.h>
#include "../include/pymem.h" 
// Declare PyType_Type (ensure this matches the definition in pytypes.c)
extern PyTypeObject PyType_Type;
#define PyObject_CAST(char) (PyObject*)(char)
PyObject* getObject (PyTypeObject* tp) {
    return PyObject_CAST(((char*)tp) + sizeof(Extension)) ;
}


int main(void){
    // Initialize the runtime state
    // Accessing PyType_Type
    printf("Type Name: %s\n", PyType_Type.tp_name);
    printf("Type Basic Size: %zu\n", PyType_Type.tp_basicsize);
    printf("Reference Count: %zd\n", PyType_Type.ob_base.ob_base.ob_refcnt);
    printf("Type Pointer Address: %p\n", (void*)PyType_Type.ob_base.ob_base.ob_type);

    // Verify self-referential pointer
    if (PyType_Type.ob_base.ob_base.ob_type == &PyType_Type) {
        printf("PyType_Type ob_type correctly points to itself.\n");
    } else {
        printf("PyType_Type ob_type does not point to itself. There is an issue.\n");
    }
    PyObject* TypeObject = getObject(&PyType_Type) ;
    printf ("The PyType_Type is PyObject with Type : %s !\n",TypeObject->ob_type->tp_name) ;

    // Demonstration of using the allocator
    void* ptr = _PyMem_Raw.malloc(_PyMem_Raw.ctx, PyType_Type.tp_basicsize);
    if (ptr == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Allocated %zu bytes at %p\n", PyType_Type.tp_basicsize, ptr);
    _PyMem_Raw.free(_PyMem_Raw.ctx,ptr);
    void* ptr2 = _PyObject_MallocWithType(&PyType_Type) ; 
    _PyObject.free(_PyObject.ctx,ptr2);
    return 0;
}

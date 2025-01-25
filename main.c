// main.c
#include "include/object.h"
#include <stdio.h>

int main(void) {
    // Set ob_type to point to PyType_Type after initialization to avoid circular dependency
    PyType_Type.obv_base.ob_base.ob_type = &PyType_Type;

    // Print the tp_name of PyType_Type
    printf("The type is: %s\n", PyType_Type.tp_name);
    return 0;
}


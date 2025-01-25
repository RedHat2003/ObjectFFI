// include/object.c
#include "object.h"

// Definition and Initialization of PyType_Type
PyTypeObject PyType_Type = {
    .obv_base = {
        .ob_base = {
            .extension_start = NULL,       // 1. extension_start
            .ob_refcnt = 1,                // 2. ob_refcnt
            .ob_type = NULL                // 3. ob_type (to be set later)
        },
        .ob_size = 0                        // ob_size
    },
    .tp_name = "type",                        // tp_name
    .tp_basicsize = 0,                        // tp_basicsize
    .tp_itemsize = 0,                         // tp_itemsize
                      // tp_repr
};

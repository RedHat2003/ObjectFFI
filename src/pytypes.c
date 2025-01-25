#include "../include/object.h"



PyTypeObject PyType_Type = {
    .ext_base = {
        .ext_size = 0,
        .extension_start = NULL,
    },
    .ob_base = {
        .ob_base = {
            .ob_refcnt = 1,
            .ob_type = &PyType_Type, // Self-referential
        },
        .size = sizeof(PyTypeObject),
    },
    .tp_name = "type",
    .tp_basicsize = sizeof(PyTypeObject),
    .tp_itemsizes = 0,
};

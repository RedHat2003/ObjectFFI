#ifndef PYRUNTIME_INIT_H
#define PYRUNTIME_INIT_H
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    void* ctx ;
    void* (*malloc)(void* ctx , size_t size) ;
    void (*free)(void* ctx , void* ptr);
}PyMemAllocatorEx;
extern void* _PyMem_RawMalloc(void* ctx, size_t size)
{
    if (size == 0)
        size = 1;
    return malloc(size);
}
void
_PyMem_RawFree(void *_unsed_ctx, void *ptr)
{
    free(ptr);
    printf("freed !\n");
}

typedef struct _pymem_allocators {
    struct {
        PyMemAllocatorEx raw;
        PyMemAllocatorEx obj;
    } standard;
} _pymem_allocators;

typedef struct pyruntimestate {
    _pymem_allocators allocators;
} _PyRuntimeState;

#define PYRAW_ALLOC {NULL, _PyMem_RawMalloc,_PyMem_RawFree}
# define PYOBJ_ALLOC PYRAW_ALLOC
#define _pymem_allocators_standard_INIT() \
    { \
        PYRAW_ALLOC, \
        PYOBJ_ALLOC, \
    }

// Macro to initialize pyruntimestate without parameters
#define _PyRuntimeState_INIT(runtime) \
    { \
        .allocators = { \
            .standard = _pymem_allocators_standard_INIT(), \
        }, \
    }

_PyRuntimeState _PyRuntime = _PyRuntimeState_INIT(runtime)  ;
// Macro to access the standard allocator
#define _PyMem_Raw (_PyRuntime.allocators.standard.raw)
#define _PyObject _PyMem_Raw
#endif


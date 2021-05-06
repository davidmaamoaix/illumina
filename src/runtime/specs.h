#ifndef ILLUMINA_SPECS_H
#define ILLUMINA_SPECS_H

#include <inttypes.h>

#ifdef VM_64_BIT_HEAP

#define HEAP_SIZE_T uint64_t
#define HEAP_OBJECT_COUNT_T uint32_t
#define OBJECT_SIZE_T uint32_t

#else

#define HEAP_SIZE_T uint32_t
#define HEAP_OBJECT_COUNT_T uint16_t
#define OBJECT_SIZE_T uint16_t

#endif // VM_64_BIT_HEAP

#define FILE_SIZE_T uint32_t
#define CONST_POOL_SIZE_T uint16_t

#endif //ILLUMINA_SPECS_H

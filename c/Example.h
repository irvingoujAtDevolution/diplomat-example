#ifndef Example_H
#define Example_H
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "diplomat_runtime.h"

#ifdef __cplusplus
namespace capi {
#endif

typedef struct Example Example;
#ifdef __cplusplus
} // namespace capi
#endif
#ifdef __cplusplus
namespace capi {
extern "C" {
#endif

Example* Example_new();

void Example_do_something(const Example* self, uint8_t* bytes_data, size_t bytes_len);
void Example_destroy(Example* self);

#ifdef __cplusplus
} // extern "C"
} // namespace capi
#endif
#endif

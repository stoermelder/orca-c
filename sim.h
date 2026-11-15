#pragma once
#include "base.h"
#include "vmio.h"

#ifdef __cplusplus
extern "C" {
#endif

// Host I/O for the '<' (CV in) and '>' (CV out) operators. orca-c never looks inside ctx.
typedef struct {
  void *ctx;
  Usz (*cv_in)(void *ctx, Usz port, Usz a, Usz b);
  void (*cv_out)(void *ctx, Usz port, Usz a, Usz b, Usz value);
} Orca_host;

// `host` may be NULL: '<' then reads 0 and '>' does nothing.
void orca_run(Glyph *restrict gbuffer, Mark *restrict mbuffer, Usz height,
              Usz width, Usz tick_number, Oevent_list *oevent_list,
              Usz random_seed, Orca_host const *host);

#ifdef __cplusplus
}
#endif

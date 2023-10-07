#ifndef TG_R_COMMON_H
#define TG_R_COMMON_H

#include "Rinternals.h"
#include "tg.h"

#ifdef __cplusplus
extern "C" {
#endif

void tg_c_release_geom(SEXP xptr);
SEXP tg_c_geometry_ptr(struct tg_geom* ptr);

#ifdef __cplusplus
}
#endif
#endif // TG_R_COMMON_H

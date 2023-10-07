#include "tg-common.h"

void tg_c_release_geom(SEXP external_ptr)
{
    struct tg_geom* geom = (struct tg_geom*) R_ExternalPtrAddr(external_ptr);
    if (geom != NULL) {
        tg_geom_free(geom);
    }
}

SEXP tg_c_geometry_ptr(struct tg_geom* ptr)
{
    SEXP external_ptr = R_MakeExternalPtr((void*)ptr, R_NilValue, R_NilValue);
    R_RegisterCFinalizerEx(external_ptr, tg_c_release_geom, TRUE);
    return external_ptr;
}

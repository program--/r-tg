#include "tg-common.h"

SEXP tg_c_type_str(SEXP geom)
{
    struct tg_geom* g = (struct tg_geom*) R_ExternalPtrAddr(geom);
    SEXP result = PROTECT(Rf_allocVector(STRSXP, 1));
    const char* str = tg_geom_type_string(tg_geom_typeof(g));
    SET_STRING_ELT(result, 0, Rf_mkChar(str));
    UNPROTECT(1);
    return result;
}

SEXP tg_c_wkt(SEXP geom)
{
    struct tg_geom* g = (struct tg_geom*) R_ExternalPtrAddr(geom);

    SEXP result = PROTECT(Rf_allocVector(STRSXP, 1));
    char wkt[BUFSIZ];
    tg_geom_wkt(g, wkt, sizeof(wkt));
    SET_STRING_ELT(result, 0, Rf_mkChar(wkt));
    UNPROTECT(1);
    return result;
}

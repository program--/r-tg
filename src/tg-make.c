#include "Rinternals.h"
#include "tg.h"
#define R_NO_REMAP
#include <R.h>
#include "tg-common.h"


SEXP tg_c_make_point(SEXP x, SEXP y)
{
    R_xlen_t size = Rf_xlength(x);
    double* px = REAL(x);
    double* py = REAL(y);

    SEXP result = PROTECT(Rf_allocVector(VECSXP, size));

    struct tg_geom* p;
    for (R_xlen_t i = 0; i < size; ++i) {
        if (ISNA(px[i]) && ISNA(py[i])) {
            p = tg_geom_new_point_empty();
        } else {
            struct tg_point point = {.x = px[i], .y = py[i]};
            p = tg_geom_new_point(point);
        }

        if (p == NULL) {
            Rf_error("[%d] %s", i + 1, "failed to allocate tg_point");
        }

        SET_VECTOR_ELT(result, i, tg_c_geometry_ptr(p));
    }

    UNPROTECT(1);
    return result;
}

SEXP tg_c_make_linestring(SEXP x, SEXP y, SEXP sizes)
{
    int* psizes = INTEGER(sizes);
    double* px = REAL(x);
    double* py = REAL(y);

    R_xlen_t nfeatures = Rf_xlength(sizes);
    SEXP result = PROTECT(Rf_allocVector(VECSXP, nfeatures));

    R_xlen_t idx = 0;
    int fsize;

    for (R_xlen_t i = 0; i < nfeatures; ++i) {
        fsize = psizes[i];
    
        struct tg_point pts[fsize];
        for (int j = 0; j < fsize; j++) {
            pts[j].x = px[idx];
            pts[j].y = py[idx];
            idx++;
        }
        
        struct tg_line* segments = tg_line_new(pts, fsize);
        struct tg_geom* ls = tg_geom_new_linestring(segments);
        tg_line_free(segments);

        SET_VECTOR_ELT(result, i, tg_c_geometry_ptr(ls));
    }

    UNPROTECT(1);
    return result;
}


SEXP tg_c_make_polygon(SEXP x, SEXP y, SEXP sizes){return R_NilValue;};

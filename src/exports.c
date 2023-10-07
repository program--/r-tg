#include <Rinternals.h>

SEXP tg_c_make_point(SEXP x, SEXP y);
SEXP tg_c_make_linestring(SEXP x, SEXP y, SEXP sizes);
SEXP tg_c_make_polygon(SEXP x, SEXP y, SEXP sizes);
SEXP tg_c_type_str(SEXP geom);
SEXP tg_c_wkt(SEXP geom);

static const R_CallMethodDef CallEntries[] = {
    {"tg_c_make_point", (DL_FUNC) &tg_c_make_point, 2},
    {"tg_c_make_linestring", (DL_FUNC) &tg_c_make_linestring, 3},
    {"tg_c_make_polygon", (DL_FUNC) &tg_c_make_polygon, 3},
    {"tg_c_type_str", (DL_FUNC) &tg_c_type_str, 1},
    {"tg_c_wkt", (DL_FUNC)&tg_c_wkt, 1},
    {NULL, NULL, 0}
};

void R_init_tg(DllInfo* dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

void R_unload_tg(DllInfo* dll) {}

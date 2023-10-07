tg_point <- function(x = c(NA_real_, NA_real_), dim = "XY") {
    ptr <- .Call(tg_c_make_point, x[1], x[2])
    class(ptr) <- c("tg_geom", "tg_point", class(ptr))
    ptr
}

tg_linestring <- function(x = matrix(numeric(0), 0, 2), dim = "XY") {
    ptr <- .Call(tg_c_make_linestring, x[, 1], x[, 2], as.integer(nrow(x)))
    class(ptr) <- c("tg_geom", "tg_linestring", class(ptr))
    ptr
}

tg_polygon <- function(x = list(), dim = "XY") {
    ptr <- NULL
    class(ptr) <- c("tg_geom", "tg_polygon", class(ptr))
    ptr
}

tg_multipoint <- function(x = matrix(numeric(0), 0, 2), dim = "XY") {
    ptr <- NULL
    class(ptr) <- c("tg_geom", "tg_multipoint", class(ptr))
    ptr
}

tg_multilinestring <- function(x = list(), dim = "XY") {
    ptr <- NULL
    class(ptr) <- c("tg_geom", "tg_multilinestring", class(ptr))
    ptr
}

tg_multipolygon <- function(x = list(), dim = "XY") {
    ptr <- NULL
    class(ptr) <- c("tg_geom", "tg_multipolygon", class(ptr))
    ptr
}

tg_geometrycollection <- function(x = list(), dims = "XY") {
    ptr <- NULL
    class(ptr) <- c("tg_geom", "tg_geometrycollection", class(ptr))
    ptr
}

#' @export
print.tg_geom <- function(x, ...) {
    s <- toupper(.Call(tg_c_wkt, x[[1]]))
    message(s)
}

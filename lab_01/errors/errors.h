#ifndef ERRORS_H
#define ERRORS_H

enum errors
{
    SUCCESS,
    EMPTY_FILE_NAME,
    OPEN_FILE_ERR,
    WRONG_FILE_ERR,
    WRONG_POINTS_PTR_ERR,
    WRONG_NPOINTS_ERR,
    POINTS_ALLOC_ERR,
    WRONG_EDGES_PTR_ERR,
    WRONG_NEDGES_ERR,
    WRONG_FILE_PTR_ERR,
    EDGES_ALLOC_ERR,
    FSAVE_NPOINTS_ERR,
    FILE_DESC_OBTAIN_ERR,
    FTRUNCATE_ERR,
    FSAVE_NEDGES_ERR,
    WRONG_POINT_INDEX_ERR,
    WRONG_EDGE_ERR,
    UNDEFINED_COMMAND
};

using err_t = enum errors;

void error_message(err_t error);

#endif // ERROR_H
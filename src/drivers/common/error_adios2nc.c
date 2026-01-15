/*
 *  Copyright (C) 2019, Northwestern University and Argonne National Laboratory
 *  See COPYRIGHT notice in top-level directory.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <common.h>
#include <errno.h>
#include <adios2_c.h>

/*----< ncmpii_error_adios2nc() ------------------------------------------------*/
/* translate posix io error codes to PnetCDF/netCDF error codes */
int ncmpii_error_adios2nc(int adios_err, char *err_msg)       /* extra error message */
{
    const char *errstr;

    /* check for specific error codes understood by PnetCDF */
    switch (adios_err){
        case adios2_error_none:
            return NC_NOERR;
        case adios2_error_invalid_argument:
            return NC_EINVAL;
        case adios2_error_system_error:
            return NC_EIO;
        case adios2_error_runtime_error:
        case adios2_error_exception:
        default:
            return NC_EADIOS;
    }

    /* other errors that currently have no corresponding PnetCDF error codes */
    if (err_msg == NULL) err_msg = "";

#ifdef PNETCDF_DEBUG
    /* report the world rank */
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("rank %d: IO error (code %d) : %s\n", rank, adios_err, err_msg);
#else
    printf("IO error (code %d) : %s\n", adios_err, err_msg);
#endif

    return NC_EFILE; /* other unknown file I/O error */
}


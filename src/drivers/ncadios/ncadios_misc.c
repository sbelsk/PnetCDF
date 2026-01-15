/*
 *  Copyright (C) 2019, Northwestern University and Argonne National Laboratory
 *  See COPYRIGHT notice in top-level directory.
 */

/*
 * This file implements helper functions used by the ADIOS driver.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include <mpi.h>
#include <pnc_debug.h>
#include <common.h>
#include <ncadios_driver.h>
#include <ncadios_internal.h>

nc_type ncadios_to_nc_type(adios2_type atype){
    switch (atype) {
        case adios2_type_uint8_t:
            return NC_BYTE;
        case adios2_type_int8_t:
            return NC_BYTE;
        case adios2_type_int16_t:
            return NC_SHORT;
        case adios2_type_uint16_t:
            return NC_USHORT;
        case adios2_type_int32_t:
            return NC_INT;
        case adios2_type_uint32_t:
            return NC_UINT;
        case adios2_type_int64_t:
            return NC_INT64;
        case adios2_type_uint64_t:
            return NC_UINT64;
        case adios2_type_float:
            return NC_FLOAT;
        case adios2_type_double:
            return NC_DOUBLE;
        case adios2_type_long_double:
            return NC_DOUBLE;
        case adios2_type_string:
            return NC_CHAR;
        case adios2_type_float_complex:
#ifdef PNETCDF_DEBUG
            printf("Warning: unsupported adios type: adios2_type_float_complex\n");
            fflush(stdout);
#endif
            return NC_BYTE;
        case adios2_type_double_complex:
#ifdef PNETCDF_DEBUG
            printf("Warning: unsupported adios type: adios2_type_double_complex\n");
            fflush(stdout);
#endif
            return NC_BYTE;
        case adios2_type_unknown:
#ifdef PNETCDF_DEBUG
            printf("Warning: unsupported adios type: adios2_type_unknown\n");
            fflush(stdout);
#endif
            return NC_BYTE;
    }

    return NC_NAT;
}

MPI_Datatype ncadios_to_mpi_type(adios2_type atype){
    switch (atype) {
        case adios2_type_uint8_t:
            return MPI_BYTE;
        case adios2_type_int8_t:
            return MPI_BYTE;
        case adios2_type_int16_t:
            return MPI_SHORT;
        case adios2_type_uint16_t:
            return MPI_UNSIGNED_SHORT;
        case adios2_type_int32_t:
            return MPI_INT;
        case adios2_type_uint32_t:
            return MPI_UNSIGNED;
        case adios2_type_int64_t:
            return MPI_LONG_LONG ;
        case adios2_type_uint64_t:
            return MPI_UNSIGNED_LONG_LONG ;
        case adios2_type_float:
            return MPI_FLOAT;
        case adios2_type_double:
            return MPI_DOUBLE;
        case adios2_type_long_double:
            return MPI_DOUBLE;
        case adios2_type_string:
            return MPI_CHAR;
        case adios2_type_float_complex:
#ifdef PNETCDF_DEBUG
            printf("Warning: unsupported adios type: adios2_type_float_complex\n");
            fflush(stdout);
#endif
            return NC_BYTE;
        case adios2_type_double_complex:
#ifdef PNETCDF_DEBUG
            printf("Warning: unsupported adios type: adios2_type_double_complex\n");
            fflush(stdout);
#endif
            return NC_BYTE;
        case adios2_type_unknown:
#ifdef PNETCDF_DEBUG
            printf("Warning: unsupported adios type: adios2_type_unknown\n");
            fflush(stdout);
#endif
            return NC_BYTE;
    }

    return NC_NAT;
}

MPI_Datatype ncadios_nc_to_mpi_type(nc_type atype){
    switch (atype) {
        case NC_BYTE:
            return MPI_BYTE;
        case NC_CHAR:
            return MPI_CHAR;
        case NC_SHORT:
            return MPI_SHORT;
        case NC_INT:
            return MPI_INT;
        case NC_FLOAT:
            return MPI_FLOAT;
        case NC_DOUBLE:
            return MPI_DOUBLE;
    }

    return NC_NAT;
}

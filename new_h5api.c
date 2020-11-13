/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * Purpose:	The new public API routines, dynamically registered by VOL
 *              connector.
 */

/* The header with the dynamic names for the new API routines */
#include "new_h5api.h"


/* Operation values for new "API" routines */
/* These are initialized in the VOL connector's 'init' callback at runtime.
 *      It's good practice to reset them back to -1 in the 'term' callback.
 */
static int H5VL_new_api_dataset_foo_op_g = -1;
static int H5VL_new_api_dataset_bar_op_g = -1;
static int H5VL_new_api_group_fiddle_op_g = -1;




/*-------------------------------------------------------------------------
 * Function:    H5Dfoo
 *
 * Purpose:     Performs the 'foo' operation on a dataset, using the
 *              dataset 'optional' VOL callback.
 *
 * Return:      Success:    0
 *              Failure:    -1
 *
 *-------------------------------------------------------------------------
 */
herr_t
H5Dfoo(hid_t dset_id, hid_t dxpl_id, void **req, int i, double d)
{
    /* Retrieve the operation value, if it hasn't already been retrieved */
    if(-1 == H5VL_new_api_dataset_foo_op_g)
        if(H5VLfind_opt_operation(H5VL_SUBCLS_DATASET, H5VL_PASSTHRU_EXT_DYN_FOO, &H5VL_new_api_dataset_foo_op_g) < 0)
            return(-1);

    /* Call the VOL dataset optional routine, requesting 'foo' occur */
    if(H5VLdataset_optional_op(dset_id, H5VL_new_api_dataset_foo_op_g, dxpl_id, req, i, d) < 0)
        return(-1);

    return 0;
} /* end H5Dfoo() */


/*-------------------------------------------------------------------------
 * Function:    H5Dbar
 *
 * Purpose:     Performs the 'bar' operation on a dataset, using the
 *              dataset 'optional' VOL callback.
 *
 * Return:      Success:    0
 *              Failure:    -1
 *
 *-------------------------------------------------------------------------
 */
herr_t
H5Dbar(hid_t dset_id, hid_t dxpl_id, void **req, double *dp, unsigned *up)
{
    /* Retrieve the operation value, if it hasn't already been retrieved */
    if(-1 == H5VL_new_api_dataset_bar_op_g)
        if(H5VLfind_opt_operation(H5VL_SUBCLS_DATASET, H5VL_PASSTHRU_EXT_DYN_BAR, &H5VL_new_api_dataset_bar_op_g) < 0)
            return(-1);

    /* Call the VOL dataset optional routine, requesting 'bar' occur */
    if(H5VLdataset_optional_op(dset_id, H5VL_new_api_dataset_bar_op_g, dxpl_id, req, dp, up) < 0)
        return(-1);

    return 0;
} /* end H5Dbar() */


/*-------------------------------------------------------------------------
 * Function:    H5Gfiddle
 *
 * Purpose:     Performs the 'fiddle' operation on a group, using the
 *              group 'optional' VOL callback.
 *
 * Return:      Success:    0
 *              Failure:    -1
 *
 *-------------------------------------------------------------------------
 */
herr_t
H5Gfiddle(hid_t dset_id, hid_t dxpl_id, void **req)
{
    /* Retrieve the operation value, if it hasn't already been retrieved */
    if(-1 == H5VL_new_api_group_fiddle_op_g)
        if(H5VLfind_opt_operation(H5VL_SUBCLS_GROUP, H5VL_PASSTHRU_EXT_DYN_FIDDLE, &H5VL_new_api_group_fiddle_op_g) < 0)
            return(-1);

    /* Call the VOL group optional routine, requesting 'fiddle' occur */
    if(H5VLgroup_optional_op(dset_id, H5VL_new_api_group_fiddle_op_g, dxpl_id, req) < 0)
        return(-1);

    return 0;
} /* end H5Gfiddle() */


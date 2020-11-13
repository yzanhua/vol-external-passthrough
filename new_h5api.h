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
 * Purpose:	The public header file for the pass-through VOL connector.
 */

#ifndef _new_h5api_H
#define _new_h5api_H

/* Include HDF5 header file */
#include "hdf5.h"

/* Names for dynamically registered operations */
#define H5VL_PASSTHRU_EXT_DYN_FOO        "org.example.ext_passthru.foo"
#define H5VL_PASSTHRU_EXT_DYN_BAR        "org.example.ext_passthru.bar"
#define H5VL_PASSTHRU_EXT_DYN_FIDDLE     "org.example.ext_passthru.fiddle"

#ifdef __cplusplus
extern "C" {
#endif

/* New "public" API routines */
herr_t H5Dfoo(hid_t dset_id, hid_t dxpl_id, void **req, int i, double d);
herr_t H5Dbar(hid_t dset_id, hid_t dxpl_id, void **req, double *dp, unsigned *up);
herr_t H5Gfiddle(hid_t group_id, hid_t dxpl_id, void **req);

#ifdef __cplusplus
}
#endif

#endif /* _new_h5api_H */


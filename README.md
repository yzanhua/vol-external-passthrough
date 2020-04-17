## HDF5 Dependency 	
It's tested with the latest version of the HDF5 dev branch (commit 66842e3347a52e18aea227ba893a4d48ee0b80e7), but you don't necessarily need that particular version.

**Note**: Make sure you have libhdf5 shared dynamic libraries in your hdf5/lib. For Linux, it's libhdf5.so, for OSX, it's libhdf5.dylib.

### Generate HDF5 shared library
If you don't have the shared dynamic libraries, you'll need to reinstall HDF5.

- Get the latest version of the develop branch;
- In the repo directory, run ./autogen.sh
- In your build directory, run configure and make sure you **DO NOT ** have option "--disable-shared", for example: 
 	>
	env CC=mpicc ../hdf5_dev/configure --enable-build-mode=debug --enable-internal-debug=all --enable-parallel
- make; make install	 

##Change following paths in Makefile:

- **HDF5_DIR**: path to your hdf5 install/build location, such as hdf5_build/hdf5/
- **SRC_DIR**: path to this VOL connector source code directory.


## Build the pass-through VOL library and run the demo
Type *make* in the source dir and you'll see **libh5passthrough_vol.so**, which is the pass -hrough VOL connector library. 

To run the demo, set following environment variables first:
>
	export HDF5_PLUGIN_PATH=PATH_TO_YOUR_pass_through_vol
	export HDF5_VOL_CONNECTOR="pass_through_ext under_vol=0;under_info={};"
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:PATH_TO_YOUR_hdf5_build/hdf5/lib:$HDF5_PLUGIN_PATH

You can run hdf5/bin/h5ls sample.h5, and it should show many lines of debugging info like:
>
	------- PASS THROUGH VOL INIT
	------- PASS THROUGH VOL INFO String To Info
	------- PASS THROUGH VOL INFO Copy

By default, the debugging mode is enabled to ensure the VOL connector is working. To disable it, simply remove the $(DEBUG) option from the CC line, and rerun make.


HDF5_DIR=${HOME}/HDF5/1.13.2
VOL_DIR=${HOME}/PassthruVol/vol-external-passthrough

all:
	mpicc -I${HDF5_DIR}/include -L${HDF5_DIR}/lib -lhdf5 -lhdf5_hl test.cpp -o test
run:
	LD_LIBRARY_PATH=${VOL_DIR}:${HDF5_DIR}/lib:${LD_LIBRARY_PATH} \
	HDF5_PLUGIN_PATH=${VOL_DIR} \
	HDF5_VOL_CONNECTOR="pass_through_ext under_vol=0;under_info={};" \
	./test

clean:
	rm -rf test *.h5 core.*

CC=mpicc
#Your HDF5 install path
HDF5_DIR=/Users/koziol/HDF5/github/hdfgroup/async/build_parallel_debug/hdf5/
MPI_DIR=/usr/local

INCLUDES=-I$(MPI_DIR)/include -I$(HDF5_DIR)/include
LIBS=-L$(HDF5_DIR)/lib -L$(MPI_DIR)/lib -lhdf5 -lz
DEBUG=-DENABLE_EXT_PASSTHRU_LOGGING

CFLAGS=$(INCLUDES) $(LIBS)

TARGET=libh5passthrough_vol.so

all: makeso

makeso:
	$(CC) -shared $(CFLAGS)  $(DEBUG) -o $(TARGET) -fPIC H5VLpassthru_ext.c

clean:
	rm -f $(TARGET)

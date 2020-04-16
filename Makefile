CC=mpicc
#Your HDF5 install path
HDF5_DIR=/Users/tonglin/nersc_dev_sync/hdf5_build/hdf5
MPI_DIR=/usr/local

INCLUDES=-I$(MPI_DIR)/include -I$(HDF5_DIR)/include
LIBS=-L$(HDF5_DIR)/lib -L$(MPI_DIR)/lib -lhdf5 -lz
DEBUG=-DENABLE_PASSTHRU_LOGGING

CFLAGS=$(INCLUDES) $(LIBS)

TARGET=libh5passthrough_vol.so

all: makeso

makeso:
	$(CC) -shared $(CFLAGS)  $(DEBUG) -o $(TARGET) -fPIC H5VLpassthru_ext.c

clean:
	rm -f $(TARGET)

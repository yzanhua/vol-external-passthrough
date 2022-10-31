# HDF5 Passthru VOL Test
This test folder contains a [test.cpp](./test.cpp) that
1. creates an HDF5 file
1. creates a dataset
1. write some data to the dataset
1. close everything.

A [makefile](./makefile) is also provided to compile and run the program using Passthru VOL.

Note: need parallel HDF5 and mpicc compiler to run this test program.

```shell
% # modify the environment variable in make file

% make  # compile the test program

% make run  # run the program using mpi 1 process
```

## Expected Output
This test program should run without problems (i.e. no error).

## Observed Output
1. Using the original/un-modifiled [Passthru-VOL](https://github.com/hpc-io/vol-external-passthrough), there's no error. (develop branch is used)
1. Using the [modified Passthru-VOL](https://github.com/yzanhua/vol-external-passthrough), 
a segmentation fault occurred. (devlop branch is used)

#!/usr/bin/env python3

import hpcMpi
import sys
import time as t
import numpy

from mpi4py import MPI


if __name__ == '__main__':

    comm = MPI.COMM_WORLD
    worldRank = comm.Get_rank()
    worldSize = comm.Get_size()

    # parse command line arguments
    step = 1e-3
    if len(sys.argv) == 2:
        step = float(sys.argv[1])

   #  t0 = t.time()

    # compute


    node_data = worldRank
    node_result = numpy.empty(1, 'f')# 'i' pour entier "f" pour float
    node_result[0] = hpcMpi.compute(hpcMpi.fPi, worldRank/worldSize, (worldRank+1)/worldSize, step)    
    all_results = numpy.empty(1, 'f')
    comm.Reduce(node_result, all_results, op=MPI.SUM)
    
    #result = 0
    #value = hpcMpi.compute(hpcMpi.fPi, worldRank/worldSize, (worldRank+1)/worldSize, step)    
    #value = hpcMpi.compute(hpcMpi.fPi, 0,1, step)    

 #   comm.Reduce(value, result, op=MPI.SUM)

    if worldRank == 0:    # master node
        print(all_results)
        #print(value)
        #print(result)
    
   #  time = t1 - t0
   #  print(step, "1", value, time)       



#   value0 = hpcMpi.compute(hpcMpi.fPi, 0, (worldRank+1)/worldSize, step)    

   #  for i in range(1, worldSize):
     #       msg = comm.recv(source=i)
      #      print(i, "sent:", msg)

     #   t1 = MPI.Wtime()
      #  print('walltime: {0:.6f} s'.format(t1-t0))

   #  t1 = t.time()

 #   else:    # other nodes

  # value = hpcMpi.compute(hpcMpi.fPi, worldRank/worldSize, (worldRank+1)/worldSize, step)    
   # comm.send(value, dest=0)

    # output result
   

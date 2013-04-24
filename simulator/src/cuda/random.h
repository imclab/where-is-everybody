#ifndef CUDA_RANDOM_H
#define CUDA_RANDOM_H

#pragma once


///////////////////////////////////////////////////////////////////////////////
// CUDA and CURAND includes.
///////////////////////////////////////////////////////////////////////////////
#include <cuda.h>
#include <curand.h>


///////////////////////////////////////////////////////////////////////////////
// System includes.
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <string>
#include <sstream>
#include <stdexcept>


///////////////////////////////////////////////////////////////////////////////
// Local includes.
///////////////////////////////////////////////////////////////////////////////
#include "cuda/device.h"


///////////////////////////////////////////////////////////////////////////////
// Class definition.
///////////////////////////////////////////////////////////////////////////////
namespace CUDA {
  class Random
  {
  public:
    Random(CUDA::Device& pDevice, unsigned long pSeed, unsigned int pSampleCount, curandRngType pRngMethod);
    Random(CUDA::Device& pDevice, unsigned long pSeed, unsigned int pSampleCount);
    ~Random();
    void generate();
    void copyToHost(float* buffer);

    void assertResult(curandStatus_t result, const std::string& msg);


  private:
    CUDA::Device&     device;
    long              seed;
    unsigned long     sampleCount;
    float*            samples;
    curandRngType     rngMethod;
    curandGenerator_t generator;

    void Init();
  };
}
#endif

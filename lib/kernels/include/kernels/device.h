#ifndef _FLEXFLOW_DEVICE_H_
#define _FLEXFLOW_DEVICE_H_

#if defined(FF_USE_CUDA) || defined(FF_USE_HIP_CUDA)
#include <cuda_runtime.h>
#include <cudnn.h>
#include <cublas_v2.h>
#elif defined(FF_USE_HIP_ROCM)
#include <hip/hip_runtime.h>
#include <miopen/miopen.h>
#include <hipblas.h>
#else
#error "Unknown device"
#endif

#if defined(FF_USE_CUDA)
#include <cuda_fp16.h>
#elif defined(FF_USE_HIP_CUDA)
#include <cuda_fp16.h>
#elif defined(FF_USE_HIP_ROCM)
#include <hip/hip_fp16.h>
#endif

#include <iostream>
#include <cassert>

namespace FlexFlow {

#if defined(FF_USE_CUDA) || defined(FF_USE_HIP_CUDA)
typedef cudaStream_t ffStream_t;
cudaError_t get_legion_stream(cudaStream_t *stream);
typedef cudnnTensorDescriptor_t ffTensorDescriptor_t;
typedef cudnnActivationDescriptor_t ffActivationDescriptor_t;
typedef cudnnPoolingDescriptor_t ffPoolingDescriptor_t;
typedef cudnnBatchNormMode_t ffBatchNormMode_t;
typedef cudnnFilterDescriptor_t ffFilterDescriptor_t;
typedef cudnnConvolutionDescriptor_t ffConvolutionDescriptor_t;
typedef cudnnConvolutionFwdAlgo_t ffConvolutionFwdAlgo_t;
typedef cudnnConvolutionBwdFilterAlgo_t ffConvolutionBwdFilterAlgo_t;
typedef cudnnConvolutionBwdDataAlgo_t ffConvolutionBwdDataAlgo_t;
typedef cudnnDropoutDescriptor_t ffDropoutDescriptor_t;
typedef cudnnOpTensorDescriptor_t ffOpTensorDescriptor_t;
typedef cudnnReduceTensorDescriptor_t ffReduceTensorDescriptor_t;
typedef cudnnAttnDescriptor_t ffAttnDescriptor_t;
typedef cudnnSeqDataDescriptor_t ffSeqDataDescriptor_t;
typedef cudnnHandle_t ffHandle_t;
typedef cudaEvent_t ffEvent_t;
typedef cublasHandle_t ffblasHandle_t;
typedef cudnnStatus_t ffStatus_t;
typedef cudaDataType_t ffDataType_t ;
typedef cudnnDataType_t ffCudnnDataType_t;
#elif defined(FF_USE_HIP_ROCM)
typedef hipStream_t ffStream_t;
hipError_t get_legion_stream(hipStream_t *stream);
typedef miopenTensorDescriptor_t ffTensorDescriptor_t;
typedef miopenActivationDescriptor_t ffActivationDescriptor_t;
typedef miopenPoolingDescriptor_t ffPoolingDescriptor_t;
typedef miopenBatchNormMode_t ffBatchNormMode_t;
typedef miopenFilterDescriptor_t ffFilterDescriptor_t;
typedef miopenConvolutionDescriptor_t ffConvolutionDescriptor_t;
typedef miopenConvolutionFwdAlgo_t ffConvolutionFwdAlgo_t;
typedef miopenConvolutionBwdFilterAlgo_t ffConvolutionBwdFilterAlgo_t;
typedef miopenConvolutionBwdDataAlgo_t ffConvolutionBwdDataAlgo_t;
typedef miopenDropoutDescriptor_t ffDropoutDescriptor_t;
typedef miopenOpTensorDescriptor_t ffOpTensorDescriptor_t;
typedef miopenReduceTensorDescriptor_t ffReduceTensorDescriptor_t;
typedef miopenAttnDescriptor_t ffAttnDescriptor_t;
typedef miopenSeqDataDescriptor_t ffSeqDataDescriptor_t;
typedef miopenHandle_t ffHandle_t;
typedef hipEvent_t ffEvent_t;
typedef hipblasHandle_t ffblasHandle_t;
typedef miopenStatus_t ffStatus_t;
typedef hipblasDataType_t ffDataType_t ;
typedef miopenDataType_t ffCudnnDataType_t;
#else
#error "Unknown device"
#endif

#define FatalError(s)                                                          \
  do {                                                                         \
    std::stringstream _where, _message;                                        \
    _where << __FILE__ << ':' << __LINE__;                                     \
    _message << std::string(s) + "\n" << __FILE__ << ':' << __LINE__;          \
    std::cerr << _message.str() << "\nAborting...\n";                          \
    assert(false);                                                             \
    exit(1);                                                                   \
  } while (0)

#define checkCUDA(status)                                                      \
  do {                                                                         \
    std::stringstream _error;                                                  \
    if (status != 0) {                                                         \
      _error << "Cuda failure: " << status;                                    \
      FatalError(_error.str());                                                \
    }                                                                          \
  } while (0)

}

#endif 

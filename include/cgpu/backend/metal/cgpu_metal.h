#pragma once
#include "cgpu/api.h"

#ifdef __cplusplus
extern "C" {
#endif

RUNTIME_API const CGpuProcTable* CGPU_MetalProcTable();
RUNTIME_API const CGpuSurfacesProcTable* CGPU_MetalSurfacesProcTable();

// Instance APIs
RUNTIME_API CGpuInstanceId cgpu_create_instance_metal(CGpuInstanceDescriptor const* descriptor);
RUNTIME_API void cgpu_query_instance_features_metal(CGpuInstanceId instance, struct CGpuInstanceFeatures* features);
RUNTIME_API void cgpu_free_instance_metal(CGpuInstanceId instance);

// Adapter APIs
RUNTIME_API void cgpu_enum_adapters_metal(CGpuInstanceId instance, CGpuAdapterId* const adapters, uint32_t* adapters_num);
RUNTIME_API void cgpu_query_adapter_detail_metal(const CGpuAdapterId adapter, struct CGpuAdapterDetail* detail);
RUNTIME_API uint32_t cgpu_query_queue_count_metal(const CGpuAdapterId adapter, const ECGpuQueueType type);

#ifdef __cplusplus
}
#endif
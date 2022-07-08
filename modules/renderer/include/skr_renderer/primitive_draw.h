#pragma once
#if !defined(__meta__)
    #include "SkrRenderer/skr_renderer.configure.h"
#endif
#include "cgpu/api.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct skr_vertex_buffer_view_t {
    CGPUBufferId buffer;
    // in bytes
    uint32_t offset = 0;
    // in bytes
    uint32_t size = 0;
    // in bytes
    uint32_t stride = 0;
} skr_vertex_buffer_view_t;

typedef struct skr_index_buffer_view_t {
    CGPUBufferId buffer;
    // in bytes
    uint32_t offset = 0;
    // in bytes
    uint32_t stride = 0;
} skr_index_buffer_view_t;

typedef struct skr_primitive_draw_t {
    CGPURenderPipelineId pipeline;
    const uint8_t* push_const;
    const skr_vertex_buffer_view_t* vertex_buffers;
    uint32_t vertex_buffer_count;
    skr_index_buffer_view_t index_buffer;
} skr_primitive_draw_t;

typedef struct skr_primitive_draw_list_view_t {
    skr_primitive_draw_t* drawcalls;
    uint32_t count;
} skr_primitive_draw_list_view_t;

#ifdef __cplusplus
}
#endif
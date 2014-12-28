#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include <xgl.h>

#include "gtest/gtest.h"
#include "gtest-1.7.0/include/gtest/gtest.h"
#include "xgltestbinding.h"

#define ASSERT_XGL_SUCCESS(err) ASSERT_EQ(XGL_SUCCESS, err) << xgl_result_string(err)

static inline const char *xgl_result_string(XGL_RESULT err)
{
    switch (err) {
#define STR(r) case r: return #r
    STR(XGL_SUCCESS);
    STR(XGL_UNSUPPORTED);
    STR(XGL_NOT_READY);
    STR(XGL_TIMEOUT);
    STR(XGL_EVENT_SET);
    STR(XGL_EVENT_RESET);
    STR(XGL_ERROR_UNKNOWN);
    STR(XGL_ERROR_UNAVAILABLE);
    STR(XGL_ERROR_INITIALIZATION_FAILED);
    STR(XGL_ERROR_OUT_OF_MEMORY);
    STR(XGL_ERROR_OUT_OF_GPU_MEMORY);
    STR(XGL_ERROR_DEVICE_ALREADY_CREATED);
    STR(XGL_ERROR_DEVICE_LOST);
    STR(XGL_ERROR_INVALID_POINTER);
    STR(XGL_ERROR_INVALID_VALUE);
    STR(XGL_ERROR_INVALID_HANDLE);
    STR(XGL_ERROR_INVALID_ORDINAL);
    STR(XGL_ERROR_INVALID_MEMORY_SIZE);
    STR(XGL_ERROR_INVALID_EXTENSION);
    STR(XGL_ERROR_INVALID_FLAGS);
    STR(XGL_ERROR_INVALID_ALIGNMENT);
    STR(XGL_ERROR_INVALID_FORMAT);
    STR(XGL_ERROR_INVALID_IMAGE);
    STR(XGL_ERROR_INVALID_DESCRIPTOR_SET_DATA);
    STR(XGL_ERROR_INVALID_QUEUE_TYPE);
    STR(XGL_ERROR_INVALID_OBJECT_TYPE);
    STR(XGL_ERROR_UNSUPPORTED_SHADER_IL_VERSION);
    STR(XGL_ERROR_BAD_SHADER_CODE);
    STR(XGL_ERROR_BAD_PIPELINE_DATA);
    STR(XGL_ERROR_TOO_MANY_MEMORY_REFERENCES);
    STR(XGL_ERROR_NOT_MAPPABLE);
    STR(XGL_ERROR_MEMORY_MAP_FAILED);
    STR(XGL_ERROR_MEMORY_UNMAP_FAILED);
    STR(XGL_ERROR_INCOMPATIBLE_DEVICE);
    STR(XGL_ERROR_INCOMPATIBLE_DRIVER);
    STR(XGL_ERROR_INCOMPLETE_COMMAND_BUFFER);
    STR(XGL_ERROR_BUILDING_COMMAND_BUFFER);
    STR(XGL_ERROR_MEMORY_NOT_BOUND);
    STR(XGL_ERROR_INCOMPATIBLE_QUEUE);
    STR(XGL_ERROR_NOT_SHAREABLE);
#undef STR
    default: return "UNKNOWN_RESULT";
    }
}

static inline void test_error_callback(const char *expr, const char *file,
                                       unsigned int line, const char *function)
{
    ADD_FAILURE_AT(file, line) << "Assertion: `" << expr << "'";
}

#endif // TEST_COMMON_H

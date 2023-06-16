#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

/*
 * Primitive types
 */

/* Unsigned types */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/* Signed types */
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

/* Floating point types */
typedef float f32;
typedef double f64;

/*
 * Math types
 */

/* Vector types */
typedef f32 vec2[2];
typedef f32 vec3[3];
typedef f32 vec4[4];

/* Matrix types */
typedef vec2 mat2[2];
typedef vec3 mat3[3];
typedef vec4 mat4[4];

#endif // TYPES_H

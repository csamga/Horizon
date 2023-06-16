#ifndef VEC3_H
#define VEC3_H

#include "types.h"

void vec3_zero(vec3 v);
void vec3_one(vec3 v);
void vec3_copy(vec3 v, vec3 out);

void vec3_addv(vec3 u, vec3 v, vec3 out);
void vec3_subv(vec3 u, vec3 v, vec3 out);
void vec3_mulv(vec3 u, vec3 v, vec3 out);
void vec3_divv(vec3 u, vec3 v, vec3 out);

void vec3_adds(vec3 v, f32 s, vec3 out);
void vec3_subs(vec3 v, f32 s, vec3 out);
void vec3_scale(vec3 v, f32 s, vec3 out);
void vec3_divs(vec3 v, f32 s, vec3 out);

void vec3_negate(vec3 v);
void vec3_negate_to(vec3 v, vec3 out);

f32 vec3_dot(vec3 u, vec3 v);
f32 vec3_norm(vec3 v);
f32 vec3_inv_norm(vec3 v);

void vec3_normalize(vec3 v);
void vec3_normalize_to(vec3 v, vec3 out);

void vec3_cross(vec3 u, vec3 v, vec3 out);

void vec3_print(const char *id, vec3 v);

#endif // VEC3_H

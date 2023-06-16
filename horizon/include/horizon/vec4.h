#ifndef VEC4_H
#define VEC4_H

#include "types.h"

void vec4_zero(vec4 v);
void vec4_one(vec4 v);
void vec4_copy(vec4 v, vec4 out);

void vec4_addv(vec4 u, vec4 v, vec4 out);
void vec4_subv(vec4 u, vec4 v, vec4 out);
void vec4_mulv(vec4 u, vec4 v, vec4 out);
void vec4_divv(vec4 u, vec4 v, vec4 out);

void vec4_adds(vec4 v, f32 s, vec4 out);
void vec4_subs(vec4 v, f32 s, vec4 out);
void vec4_scale(vec4 v, f32 s, vec4 out);
void vec4_divs(vec4 v, f32 s, vec4 out);

void vec4_negate(vec4 v);
void vec4_negate_to(vec4 v, vec4 out);

f32 vec4_dot(vec4 u, vec4 v);
f32 vec4_norm(vec4 v);
f32 vec4_inv_norm(vec4 v);
void vec4_normalize(vec4 v);
void vec4_normalize_to(vec4 v, vec4 out);

void vec4_cross(vec4 u, vec4 v, vec4 out);

void vec4_print(const char *id, vec4 v);

#endif // VEC4_H

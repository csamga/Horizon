#ifndef VEC2_H
#define VEC2_H

#include "types.h"

void vec2_copy(vec2 v, vec2 out);

void vec2_zero(vec2 v);
void vec2_one(vec2 v);

void vec2_addv(vec2 u, vec2 v, vec2 out);
void vec2_adds(vec2 v, f32 s, vec2 out);

void vec2_subv(vec2 u, vec2 v, vec2 out);
void vec2_subs(vec2 v, f32 s, vec2 out);

void vec2_mulv(vec2 u, vec2 v, vec2 out);
void vec2_scale(vec2 v, f32 s, vec2 out);

void vec2_divv(vec2 u, vec2 v, vec2 out);
void vec2_divs(vec2 v, f32 s, vec2 out);

f32 vec2_norm(vec2 v);
f32 vec2_dot(vec2 u, vec2 v);

// void vec2_cross(vec2 u, vec2 v, vec2 out);
void vec2_normalize(vec2 v);

void vec2_negate(vec2 v, vec2 out);

void vec2_print(const char *name, vec2 v);

#endif // VEC2_H

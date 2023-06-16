#include "pch.h"
#include "horizon/vec2.h"
#include "horizon/vec3.h"
#include "horizon/utils.h"

void vec2_zero(vec2 v)
{
	v[0] = v[1] = 0.0f;
}
void vec2_one(vec2 v)
{
	v[0] = v[1] = 1.0f;
}
void vec2_copy(vec2 v, vec2 out)
{
	out[0] = v[0];
	out[1] = v[1];
}

void vec2_addv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] + v[0];
	out[1] = u[1] + v[1];
}
void vec2_subv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] - v[0];
	out[1] = u[1] - v[1];
}
void vec2_mulv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] * v[0];
	out[1] = u[1] * v[1];
}
void vec2_divv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] / v[0];
	out[1] = u[1] / v[1];
}

void vec2_adds(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] + s;
	out[1] = v[1] + s;
}
void vec2_subs(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] - s;
	out[1] = v[1] - s;
}
void vec2_scale(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] * s;
	out[1] = v[1] * s;
}
void vec2_divs(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] / s;
	out[1] = v[1] / s;
}

void vec2_negate(vec2 v)
{
	v[0] = -v[0];
	v[1] = -v[1];
}
void vec2_negate_to(vec2 v, vec2 out)
{
	out[0] = -v[0];
	out[1] = -v[1];
}

f32 vec2_dot(vec2 u, vec2 v)
{
	return (u[0] * v[0]) + (u[1] * v[1]);
}
f32 vec2_norm(vec2 v)
{
	return sqrtf(vec2_dot(v, v));
}
f32 vec3_inv_norm(vec2 v)
{
	f32 dot = vec2_dot(v, v);

	if (0.0f == dot)
		return 0.0f;

	return fast_inv_sqrt(dot);
}
void vec2_normalize(vec2 v)
{
	f32 inv_norm = vec2_inv_norm(v);

	if (0.0f == inv_norm) {
		vec2_zero(v);
		return;
	}

	vec2_muls(v, inv_norm, v);
}
void vec2_normalize_to(vec2 v, vec2 out)
{
	f32 inv_norm = vec2_inv_norm(v);

	if (0.0f == inv_norm) {
		vec2_zero(out);
		return;
	}

	vec2_muls(v, inv_norm, out);
}

void vec2_cross(vec2 u, vec2 v, vec3 out)
{
	out[0] = 0.0f;
	out[1] = 0.0f;
	out[2] = (u[0] * v[1]) - (u[1] * v[0]);
}

void vec2_print(const char *id, vec2 v)
{
	printf("%s = (%.3f, %.3f)\n", id, v[0], v[1]);
}

#include "pch.h"
#include "horizon/vec3.h"
#include "horizon/utils.h"

void vec3_zero(vec3 v)
{
	v[0] = v[1] = v[2] = 0.0f;
}
void vec3_one(vec3 v)
{
	v[0] = v[1] = v[2] = 1.0f;
}
void vec3_copy(vec3 v, vec3 out)
{
	out[0] = v[0];
	out[1] = v[1];
	out[2] = v[2];
}

void vec3_addv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] + v[0];
	out[1] = u[1] + v[1];
	out[2] = u[2] + v[2];
}
void vec3_subv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] - v[0];
	out[1] = u[1] - v[1];
	out[2] = u[2] - v[2];
}
void vec3_mulv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] * v[0];
	out[1] = u[1] * v[1];
	out[2] = u[2] * v[2];
}
void vec3_divv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] / v[0];
	out[1] = u[1] / v[1];
	out[2] = u[2] / v[2];
}

void vec3_adds(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] + s;
	out[1] = v[1] + s;
	out[2] = v[2] + s;
}
void vec3_subs(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] - s;
	out[1] = v[1] - s;
	out[2] = v[2] - s;
}
void vec3_scale(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] * s;
	out[1] = v[1] * s;
	out[2] = v[2] * s;
}
void vec3_divs(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] / s;
	out[1] = v[1] / s;
	out[2] = v[2] / s;
}

void vec3_negate(vec3 v)
{
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}
void vec3_negate_to(vec3 v, vec3 out)
{
	out[0] = -v[0];
	out[1] = -v[1];
	out[2] = -v[2];
}

f32 vec3_dot(vec3 u, vec3 v)
{
	return (u[0] * v[0]) + (u[1] * v[1]) + (u[2] * v[2]);
}
f32 vec3_norm(vec3 v)
{
	return sqrtf(vec3_dot(v, v));
}
f32 vec3_inv_norm(vec3 v)
{
	f32 dot = vec3_dot(v, v);

	if (0.0f == dot)
		return 0.0f;

	return fast_inv_sqrt(dot);
}
void vec3_normalize(vec3 v)
{
	f32 inv_norm = vec3_inv_norm(v);

	if (0.0f == inv_norm) {
		vec3_zero(v);
		return;
	}

	vec3_muls(v, inv_norm, v);
}
void vec3_normalize_to(vec3 v, vec3 out)
{
	f32 inv_norm = vec3_inv_norm(v);

	if (0.0f == inv_norm) {
		vec3_zero(out);
		return;
	}

	vec3_muls(v, inv_norm, out);
}

void vec3_cross(vec3 u, vec3 v, vec3 out)
{
	out[0] = (u[1] * v[2]) - (u[2] * v[1]);
	out[1] = (u[2] * v[0]) - (u[0] * v[2]);
	out[2] = (u[0] * v[1]) - (u[1] * v[0]);
}

void vec3_print(const char *id, vec3 v)
{
	printf("%s = (%.3f, %.3f, %.3f)\n", id, v[0], v[1], v[2]);
}

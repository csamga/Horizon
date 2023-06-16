#include "pch.h"
#include "horizon/vec3.h"

void vec3_copy(vec3 v, vec3 out)
{
	out[0] = v[0];
	out[1] = v[1];
	out[2] = v[2];
}

void vec3_zero(vec3 v)
{
	v[0] = v[1] = v[2] = 0.0f;
}

void vec3_one(vec3 v)
{
	v[0] = v[1] = v[2] = 1.0f;
}

void vec3_addv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] + v[0];
	out[1] = u[1] + v[1];
	out[2] = u[2] + v[2];
}

void vec3_adds(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] + s;
	out[1] = v[1] + s;
	out[2] = v[2] + s;
}

void vec3_subv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] - v[0];
	out[1] = u[1] - v[1];
	out[2] = u[2] - v[2];
}

void vec3_subs(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] - s;
	out[1] = v[1] - s;
	out[2] = v[2] - s;
}

void vec3_mulv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] * v[0];
	out[1] = u[1] * v[1];
	out[2] = u[2] * v[2];
}

void vec3_scale(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] * s;
	out[1] = v[1] * s;
	out[2] = v[2] * s;
}

void vec3_divv(vec3 u, vec3 v, vec3 out)
{
	out[0] = u[0] / v[0];
	out[1] = u[1] / v[1];
	out[2] = u[2] / v[2];
}

void vec3_divs(vec3 v, f32 s, vec3 out)
{
	out[0] = v[0] / s;
	out[1] = v[1] / s;
	out[2] = v[2] / s;
}

f32 vec3_dot(vec3 u, vec3 v)
{
	return (u[0] * v[0]) + (u[1] * v[1]) + (u[2] * v[2]);
}

f32 vec3_norm(vec3 v)
{
	return sqrtf(vec3_dot(v, v));
}

void vec3_cross(vec3 u, vec3 v, vec3 out)
{
	vec3 cross;

	cross[0] = (u[1] * v[2]) - (u[2] * v[1]);
	cross[1] = (u[2] * v[0]) - (u[0] * v[2]);
	cross[2] = (u[0] * v[1]) - (u[1] * v[0]);

	vec3_copy(cross, out);
}

void vec3_normalize(vec3 v)
{
	f32 norm = vec3_norm(v);

	if (norm == 0.0f) {
		vec3_zero(v);
		return;
	}

	vec3_divs(v, norm, v);
}

void vec3_negate(vec3 v, vec3 out)
{
	out[0] = -v[0];
	out[1] = -v[1];
	out[2] = -v[2];
}

void vec3_print(const char *name, vec3 v)
{
	printf("%s = (%.3f, %.3f, %.3f)\n", name, v[0], v[1], v[2]);
}

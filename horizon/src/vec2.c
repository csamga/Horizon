#include "pch.h"
#include "horizon/vec2.h"

void vec2_copy(vec2 v, vec2 out)
{
	out[0] = v[0];
	out[1] = v[1];
}

void vec2_zero(vec2 v)
{
	v[0] = v[1] = 0.0f;
}

void vec2_one(vec2 v)
{
	v[0] = v[1] = 1.0f;
}

void vec2_addv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] + v[0];
	out[1] = u[1] + v[1];
}

void vec2_adds(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] + s;
	out[1] = v[1] + s;
}

void vec2_subv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] - v[0];
	out[1] = u[1] - v[1];
}

void vec2_subs(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] - s;
	out[1] = v[1] - s;
}

void vec2_mulv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] * v[0];
	out[1] = u[1] * v[1];
}

void vec2_scale(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] * s;
	out[1] = v[1] * s;
}

void vec2_divv(vec2 u, vec2 v, vec2 out)
{
	out[0] = u[0] / v[0];
	out[1] = u[1] / v[1];
}

void vec2_divs(vec2 v, f32 s, vec2 out)
{
	out[0] = v[0] / s;
	out[1] = v[1] / s;
}

f32 vec2_dot(vec2 u, vec2 v)
{
	return (u[0] * v[0]) + (u[1] * v[1]);
}

f32 vec2_norm(vec2 v)
{
	return sqrtf(vec2_dot(v, v));
}

// void vec2_cross(vec2 u, vec2 v, vec2 out)
// {
// 	vec2 cross;

// 	cross[0] = (u[1] * v[2]) - (u[2] * v[1]);
// 	cross[1] = (u[2] * v[0]) - (u[0] * v[2]);
// 	cross[2] = (u[0] * v[1]) - (u[1] * v[0]);

// 	vec2_copy(cross, out);
// }

void vec2_normalize(vec2 v)
{
	f32 norm = vec2_norm(v);

	if (norm == 0.0f) {
		vec2_zero(v);
		return;
	}

	vec2_divs(v, norm, v);
}

void vec2_negate(vec2 v, vec2 out)
{
	out[0] = -v[0];
	out[1] = -v[1];
}

void vec2_print(const char *name, vec2 v)
{
	printf("%s = (%.3f, %.3f)\n", name, v[0], v[1]);
}

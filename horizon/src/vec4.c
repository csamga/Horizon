#include "pch.h"
#include "horizon/vec4.h"

void vec4_copy(vec4 v, vec4 out)
{
	out[0] = v[0];
	out[1] = v[1];
	out[2] = v[2];
	out[3] = v[3];
}

void vec4_zero(vec4 v)
{
	v[0] = v[1] = v[2] = v[3] = 0.0f;
}

void vec4_one(vec4 v)
{
	v[0] = v[1] = v[2] = v[3] = 1.0f;
}

void vec4_addv(vec4 u, vec4 v, vec4 out)
{
	out[0] = u[0] + v[0];
	out[1] = u[1] + v[1];
	out[2] = u[2] + v[2];
	out[3] = u[3] + v[3];
}

void vec4_adds(vec4 v, f32 s, vec4 out)
{
	out[0] = v[0] + s;
	out[1] = v[1] + s;
	out[2] = v[2] + s;
	out[3] = v[3] + s;
}

void vec4_subv(vec4 u, vec4 v, vec4 out)
{
	out[0] = u[0] - v[0];
	out[1] = u[1] - v[1];
	out[2] = u[2] - v[2];
	out[3] = u[3] - v[3];
}

void vec4_subs(vec4 v, f32 s, vec4 out)
{
	out[0] = v[0] - s;
	out[1] = v[1] - s;
	out[2] = v[2] - s;
	out[3] = v[3] - s;
}

void vec4_mulv(vec4 u, vec4 v, vec4 out)
{
	out[0] = u[0] * v[0];
	out[1] = u[1] * v[1];
	out[2] = u[2] * v[2];
	out[3] = u[3] * v[3];
}

void vec4_scale(vec4 v, f32 s, vec4 out)
{
	out[0] = v[0] * s;
	out[1] = v[1] * s;
	out[2] = v[2] * s;
	out[3] = v[3] * s;
}

void vec4_divv(vec4 u, vec4 v, vec4 out)
{
	out[0] = u[0] / v[0];
	out[1] = u[1] / v[1];
	out[2] = u[2] / v[2];
	out[3] = u[3] / v[3];
}

void vec4_divs(vec4 v, f32 s, vec4 out)
{
	out[0] = v[0] / s;
	out[1] = v[1] / s;
	out[2] = v[2] / s;
	out[3] = v[3] / s;
}

f32 vec4_dot(vec4 u, vec4 v)
{
	return (u[0] * v[0]) + (u[1] * v[1]) + (u[2] * v[2]) + (u[3] * v[3]);
}

f32 vec4_norm(vec4 v)
{
	return sqrtf(vec4_dot(v, v));
}

void vec4_cross(vec4 u, vec4 v, vec4 out)
{
	vec4 cross;

	cross[0] = (u[2] * v[3]) - (u[3] - v[2]);
	cross[1] = (u[3] * v[0]) - (u[0] - v[3]);
	cross[2] = (u[0] * v[1]) - (u[1] - v[0]);
	cross[3] = (u[1] * v[2]) - (u[2] - v[1]);

	vec4_copy(cross, out);
}

void vec4_normalize(vec4 v)
{
	f32 norm = vec4_norm(v);

	if (0.0f == norm) {
		vec4_zero(v);
		return;
	}

	vec4_divs(v, norm, v);
}

void vec4_negate(vec4 v, vec4 out)
{
	out[0] = -v[0];
	out[1] = -v[1];
	out[2] = -v[2];
	out[3] = -v[3];
}

void vec4_print(const char *name, vec4 v)
{
	printf("%s = (%.3f, %.3f, %.3f, %.3f)\n", name, v[0], v[2], v[2], v[3]);
}

#include "pch.h"
#include "horizon/utils.h"

#define PI 3.14159265358979323846

f32 deg_to_rad(f32 angle)
{
	return angle * PI / 180.0f;
}

f32 rad_to_deg(f32 angle)
{
	return angle * 180.0f / PI;
}

f32 fast_inv_sqrt(f32 s)
{
	i32 i;
	f32 s2, y;
	const f32 three_halfs = 1.5f;

	s2 = s * 0.5f;
	y = s;
	i = *(i32 *)&y; // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1); // what the fuck?
	y = *(f32 *)&i;
	y = y * (three_halfs - (s2 * y * y)); // 1st iteration
	y = y * (three_halfs - (s2 * y * y)); // 2nd iteration, this can be removed

	return y;
}

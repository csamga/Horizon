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

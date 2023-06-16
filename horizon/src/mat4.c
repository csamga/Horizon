#include "pch.h"
#include "horizon/mat4.h"
#include "horizon/vec3.h"
#include "horizon/utils.h"

// clang-format off
#define MAT4_ZERO {{0.0f, 0.0f, 0.0f, 0.0f},\
                   {0.0f, 0.0f, 0.0f, 0.0f},\
                   {0.0f, 0.0f, 0.0f, 0.0f},\
                   {0.0f, 0.0f, 0.0f, 0.0f}}

#define MAT4_IDENTITY {{1.0f, 0.0f, 0.0f, 0.0f},\
                       {0.0f, 1.0f, 0.0f, 0.0f},\
                       {0.0f, 0.0f, 1.0f, 0.0f},\
                       {0.0f, 0.0f, 0.0f, 1.0f}}
// clang-format on

void mat4_copy(mat4 m, mat4 out)
{
	// clang-format off
    out[0][0] = m[0][0]; out[1][0] = m[1][0];
    out[0][1] = m[0][1]; out[1][1] = m[1][1];
    out[0][2] = m[0][2]; out[1][2] = m[1][2];
    out[0][3] = m[0][3]; out[1][3] = m[1][3];

    out[2][0] = m[2][0]; out[3][0] = m[3][0];
    out[2][1] = m[2][1]; out[3][1] = m[3][1];
    out[2][2] = m[2][2]; out[3][2] = m[3][2];
    out[2][3] = m[2][3]; out[3][3] = m[3][3];
	// clang-format on
}

void mat4_zero(mat4 m)
{
	mat4_copy((mat4)MAT4_ZERO, m);
}

void mat4_zero_array(mat4 *matrices[], i32 length)
{
	for (i32 i = 0; i < length; ++i)
		mat4_zero(*matrices[i]);
}

void mat4_identity(mat4 m)
{
	mat4_copy((mat4)MAT4_IDENTITY, m);
}

void mat4_identity_array(mat4 *matrices[], i32 length)
{
	for (i32 i = 0; i < length; ++i)
		mat4_identity(*matrices[i]);
}

void mat4_mul(mat4 a, mat4 b, mat4 out)
{
	f32 a00 = a[0][0], a01 = a[0][1], a02 = a[0][2], a03 = a[0][3];
	f32 a10 = a[1][0], a11 = a[1][1], a12 = a[1][2], a13 = a[1][3];
	f32 a20 = a[2][0], a21 = a[2][1], a22 = a[2][2], a23 = a[2][3];
	f32 a30 = a[3][0], a31 = a[3][1], a32 = a[3][2], a33 = a[3][3];

	f32 b00 = b[0][0], b01 = b[0][1], b02 = b[0][2], b03 = b[0][3];
	f32 b10 = b[1][0], b11 = b[1][1], b12 = b[1][2], b13 = b[1][3];
	f32 b20 = b[2][0], b21 = b[2][1], b22 = b[2][2], b23 = b[2][3];
	f32 b30 = b[3][0], b31 = b[3][1], b32 = b[3][2], b33 = b[3][3];

	out[0][0] = (a00 * b00) + (a10 * b01) + (a20 * b02) + (a30 * b03);
	out[0][1] = (a01 * b00) + (a11 * b01) + (a21 * b02) + (a31 * b03);
	out[0][2] = (a02 * b00) + (a12 * b01) + (a22 * b02) + (a32 * b03);
	out[0][3] = (a03 * b00) + (a13 * b01) + (a23 * b02) + (a33 * b03);

	out[1][0] = (a00 * b10) + (a10 * b11) + (a20 * b12) + (a30 * b13);
	out[1][1] = (a01 * b10) + (a11 * b11) + (a21 * b12) + (a31 * b13);
	out[1][2] = (a02 * b10) + (a12 * b11) + (a22 * b12) + (a32 * b13);
	out[1][3] = (a03 * b10) + (a13 * b11) + (a23 * b12) + (a33 * b13);

	out[2][0] = (a00 * b20) + (a10 * b21) + (a20 * b22) + (a30 * b23);
	out[2][1] = (a01 * b20) + (a11 * b21) + (a21 * b22) + (a31 * b23);
	out[2][2] = (a02 * b20) + (a12 * b21) + (a22 * b22) + (a32 * b23);
	out[2][3] = (a03 * b20) + (a13 * b21) + (a23 * b22) + (a33 * b23);

	out[3][0] = (a00 * b30) + (a10 * b31) + (a20 * b32) + (a30 * b33);
	out[3][1] = (a01 * b30) + (a11 * b31) + (a21 * b32) + (a31 * b33);
	out[3][2] = (a02 * b30) + (a12 * b31) + (a22 * b32) + (a32 * b33);
	out[3][3] = (a03 * b30) + (a13 * b31) + (a23 * b32) + (a33 * b33);
}

void mat4_mul_array(mat4 *matrices[], i32 len, mat4 out)
{
	mat4_mul(*matrices[0], *matrices[1], out);

	for (i32 i = 2; i < len; ++i)
		mat4_mul(out, *matrices[i], out);
}

void mat4_translation(vec3 v, mat4 out)
{
	mat4_identity(out);
	vec3_copy(v, out[3]);
}

void mat4_rotation_x(f32 x_angle_rad, mat4 out)
{
	f32 cos = cosf(x_angle_rad);
	f32 sin = sinf(x_angle_rad);

	mat4_identity(out);

	out[1][1] = cos;
	out[1][2] = sin;
	out[2][1] = -sin;
	out[2][2] = cos;
}

void mat4_rotation_y(f32 y_angle_rad, mat4 out)
{
	f32 cos = cosf(y_angle_rad);
	f32 sin = sinf(y_angle_rad);

	mat4_identity(out);

	out[0][0] = cos;
	out[0][2] = sin;
	out[2][0] = -sin;
	out[2][2] = cos;
}

void mat4_rotation_z(f32 z_angle_rad, mat4 out)
{
	f32 cos = cosf(z_angle_rad);
	f32 sin = sinf(z_angle_rad);

	mat4_identity(out);

	out[0][0] = cos;
	out[0][1] = sin;
	out[1][0] = -sin;
	out[1][1] = cos;
}

// FIXME: array parameter for mul_array is nonsense
void mat4_rotation(vec3 xyz_angles_rad, mat4 out)
{
	mat4 rotation_z;
	mat4 rotation_y;
	mat4 rotation_x;

	mat4_rotation_z(xyz_angles_rad[2], rotation_z);
	mat4_rotation_y(xyz_angles_rad[1], rotation_y);
	mat4_rotation_x(xyz_angles_rad[0], rotation_x);

	mat4_mul_array((mat4 *[]){&rotation_z, &rotation_y, &rotation_x}, 3, out);
}

void mat4_scaling(vec3 v, mat4 out)
{
	mat4_identity(out);

	out[0][0] = v[0];
	out[1][1] = v[1];
	out[2][2] = v[2];
}

void mat4_view(vec3 position, vec3 forward, vec3 up, mat4 out)
{
	vec3 negative_pos;
	vec3_negate(position, negative_pos);

	mat4 translation;
	mat4_translation(negative_pos, translation);

	vec3 n;
	vec3_copy(forward, n);

	vec3 u;
	vec3_cross(up, n, u);
	vec3_normalize(u);

	vec3 v;
	vec3_cross(n, u, v);

	mat4 rotation;
	mat4_identity(rotation);

	rotation[0][0] = u[0];
	rotation[1][0] = u[1];
	rotation[2][0] = u[2];

	rotation[0][1] = v[0];
	rotation[1][1] = v[1];
	rotation[2][1] = v[2];

	rotation[0][2] = n[0];
	rotation[1][2] = n[1];
	rotation[2][2] = n[2];

	mat4_mul(rotation, translation, out);
}

void mat4_projection(
	f32 fov_deg, f32 aspect_ratio, f32 z_near, f32 z_far, mat4 out)
{
	f32 fov_rad = deg_to_rad(fov_deg);
	f32 d = 1.0f / tanf(fov_rad / 2.0f);

	f32 z_range = z_far - z_near;
	f32 a = (-z_far - z_near) / z_range;
	f32 b = 2.0f * z_far * z_near / z_range;

	mat4_zero(out);

	out[0][0] = d / aspect_ratio;
	out[1][1] = d;
	out[2][2] = a;
	out[2][3] = 1.0f;
	out[3][2] = b;
}

void mat4_print(mat4 m)
{
	for (i32 j = 0; j < 4; ++j) {
		printf("|");

		for (i32 i = 0; i < 4; ++i)
			printf("%1.1f  ", m[i][j]);

		printf("\b\b|\n");
	}
}

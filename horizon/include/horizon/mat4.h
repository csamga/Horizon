#ifndef MATRIX_H
#define MATRIX_H

#include "types.h"

/*
 * Matrix in column-major representation: m[col][row]
 *
 * | m[0][0] m[1][0] m[2][0] m[3][0] |
 * | m[0][1] m[1][1] m[2][1] m[3][1] |
 * | m[0][2] m[1][2] m[2][2] m[3][2] |
 * | m[0][3] m[1][3] m[2][3] m[3][3] |
 */

/*
 * Matrix in row-major representation: m[row][col]
 *
 * | m[0][0] m[0][1] m[0][2] m[0][3] |
 * | m[1][0] m[1][1] m[1][2] m[1][3] |
 * | m[2][0] m[2][1] m[2][2] m[2][3] |
 * | m[3][0] m[3][1] m[3][2] m[3][3] |
 */

/*
 * Here we use a column-major matrix representation
 * to facilitate the creation of translation matrices.
 * In This way one can simply copy the translation vector
 * in the last column of the matrix instead of copying each
 * vector component in separate rows.
 */

void mat4_copy(mat4 m, mat4 out);

void mat4_zero(mat4 m);
void mat4_zero_array(mat4 *matrices[], i32 length);

void mat4_identity(mat4 m);
void mat4_identity_array(mat4 *matrices[], i32 length);

void mat4_mul(mat4 a, mat4 b, mat4 out);
void mat4_mul_array(mat4 *matrices[], i32 len, mat4 out);

void mat4_translation(vec3 v, mat4 out);

void mat4_rotation_x(f32 x_angle_rad, mat4 out);
void mat4_rotation_y(f32 y_angle_rad, mat4 out);
void mat4_rotation_z(f32 z_angle_rad, mat4 out);
void mat4_rotation(vec3 xyz_angles_rad, mat4 out);

void mat4_scaling(vec3 v, mat4 out);

void mat4_view(vec3 position, vec3 forward, vec3 up, mat4 out);

void mat4_projection(
	f32 fov_deg, f32 aspect_ratio, f32 z_near, f32 z_far, mat4 out);

void mat4_print(mat4 m);

#endif // MATRIX_H

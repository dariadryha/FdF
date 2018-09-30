#include "../fdf.h"

t_vectr matrix_subtraction(t_vectr v1, t_vectr v2)
{
	t_vectr result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	result.w = 1;
	return(result);
}

t_vectr	normilize_vector(t_vectr v)
{
	float length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return(v);
}

t_vectr cross(t_vectr v1, t_vectr v2)
{
	t_vectr result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return(result);
}

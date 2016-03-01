#include "RTv1.h"

void	ft_cone_angle(double c_angle, t_cone *cone)
{
	if (fmod(c_angle, 90) == 0)
		c_angle = c_angle - 0.01;
	cone->angle = c_angle;
	cone->k =  tan(c_angle * M_PI / (double)180);
}

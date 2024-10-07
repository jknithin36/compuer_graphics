#include "Sphere.h"
#include "../Imageio/Imageio.h"
#include <math.h>

Intersect_Cond Sphere::intersection_check(const M3DVector3f start, const M3DVector3f dir, float & distance, M3DVector3f intersection_p)
{
M3DVector3f ray_to_center;
m3dSubtractVectors3(ray_to_center,_pos,start);
float ray_center_length = m3dDotProduct(ray_to_center, ray_to_center);

float closest_point = m3dDotProduct( ray_to_center, dir);
if (closest_point < 0)
{
return _k_miss;
}

float halfCord2 = (_rad * _rad) - (ray_center_length - (closest_point * closest_point));  
if(halfCord2 < 0)
{
return _k_miss;
}

Intersect_Cond type;
M3DVector3f tmp;
m3dSubtractVectors3(tmp,start,_pos);
float length = m3dDotProduct(tmp,tmp);
if (length < _rad2)
{
type = _k_inside;
distance = closest_point + sqrt(halfCord2);
}else
{
type = _k_hit;
distance = closest_point - sqrt(halfCord2);
}

M3DVector3f tmp_v;
m3dCopyVector3(tmp_v, dir);
m3dScaleVector3(tmp_v,distance);
m3dAddVectors3(intersection_p,start,tmp_v);

return type;
}

void Sphere::shade(M3DVector3f view,M3DVector3f intersect_p,const Light & sp_light, M3DVector3f am_light, M3DVector3f color, bool shadow)
{
M3DVector3f light_spot, light_illumination;
M3DVector3f l;
M3DVector3f m;
M3DVector3f n;
sp_light.get_light(light_spot, light_illumination);
m3dSubtractVectors3(l, intersect_p, _pos);
m3dNormalizeVector(l);
m3dSubtractVectors3(m, light_spot, intersect_p);
m3dNormalizeVector(m);
float scatter = m3dDotProduct(m, l);
m3dCopyVector3(n, l);
m3dScaleVector3(n, 2 * scatter);
m3dSubtractVectors3(n, m, n);
float spec = m3dDotProduct(n, view);
for (int i = 0; i < 3; i++)
{
color[i] = _ka * _color[i] * am_light[i];

if (scatter > 0)
{
color[i] += _kd * _color[i] * light_illumination[i] * scatter;
}
if (spec > 0)
{
color[i] += _ks * light_illumination[i] * pow(spec, 100);
}
}

}
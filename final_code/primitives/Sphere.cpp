// #include "Sphere.h"
// #include "../Imageio/Imageio.h"
// #include <math.h>

// Intersect_Cond Sphere::intersection_check(const M3DVector3f start, const M3DVector3f dir, float & distance, M3DVector3f intersection_p)
// {
// M3DVector3f ray_to_center;
// m3dSubtractVectors3(ray_to_center,_pos,start);
// float ray_center_length = m3dDotProduct(ray_to_center, ray_to_center);

// float closest_point = m3dDotProduct( ray_to_center, dir);
// if (closest_point < 0)
// {
// return _k_miss;
// }

// float halfCord2 = (_rad * _rad) - (ray_center_length - (closest_point * closest_point));  
// if(halfCord2 < 0)
// {
// return _k_miss;
// }

// Intersect_Cond type;
// M3DVector3f tmp;
// m3dSubtractVectors3(tmp,start,_pos);
// float length = m3dDotProduct(tmp,tmp);
// if (length < _rad2)
// {
// type = _k_inside;
// distance = closest_point + sqrt(halfCord2);
// }else
// {
// type = _k_hit;
// distance = closest_point - sqrt(halfCord2);
// }

// M3DVector3f tmp_v;
// m3dCopyVector3(tmp_v, dir);
// m3dScaleVector3(tmp_v,distance);
// m3dAddVectors3(intersection_p,start,tmp_v);

// return type;
// }

// void Sphere::shade(M3DVector3f view,M3DVector3f intersect_p,const Light & sp_light, M3DVector3f am_light, M3DVector3f color, bool shadow)
// {
// M3DVector3f light_spot, light_illumination;
// M3DVector3f l;
// M3DVector3f m;
// M3DVector3f n;
// sp_light.get_light(light_spot, light_illumination);
// m3dSubtractVectors3(l, intersect_p, _pos);
// m3dNormalizeVector(l);
// m3dSubtractVectors3(m, light_spot, intersect_p);
// m3dNormalizeVector(m);
// float scatter = m3dDotProduct(m, l);
// m3dCopyVector3(n, l);
// m3dScaleVector3(n, 2 * scatter);
// m3dSubtractVectors3(n, m, n);
// float spec = m3dDotProduct(n, view);
// for (int i = 0; i < 3; i++)
// {
// color[i] = _ka * _color[i] * am_light[i];

// if (scatter > 0)
// {
// color[i] += _kd * _color[i] * light_illumination[i] * scatter;
// }
// if (spec > 0)
// {
// color[i] += _ks * light_illumination[i] * pow(spec, 100);
// }
// }

// }

#include "Sphere.h"
#include "../Imageio/Imageio.h"
#include <cmath> // Use <cmath> instead of <math.h> for C++

Intersect_Cond Sphere::intersection_check(const M3DVector3f start, const M3DVector3f dir, float &distance, M3DVector3f intersection_p) {
    M3DVector3f ray_to_center;
    m3dSubtractVectors3(ray_to_center, _pos, start);
    
    // Calculate the squared length from the ray start to the sphere center
    float ray_center_length_squared = m3dDotProduct(ray_to_center, ray_to_center);

    // Calculate the closest point on the ray to the center of the sphere
    float closest_point = m3dDotProduct(ray_to_center, dir);
    if (closest_point < 0) {
        return _k_miss; // The ray misses the sphere
    }

    // Calculate half the chord squared
    float halfChordSquared = (_rad * _rad) - (ray_center_length_squared - (closest_point * closest_point));
    if (halfChordSquared < 0) {
        return _k_miss; // The ray misses the sphere
    }

    // Determine intersection type and calculate distance to the intersection point
    Intersect_Cond type;
    M3DVector3f tmp;
    m3dSubtractVectors3(tmp, start, _pos);
    float length_squared = m3dDotProduct(tmp, tmp);
    
    if (length_squared < _rad2) {
        type = _k_inside;
        distance = closest_point + sqrt(halfChordSquared);
    } else {
        type = _k_hit;
        distance = closest_point - sqrt(halfChordSquared);
    }

    // Calculate the intersection point
    M3DVector3f tmp_v;
    m3dCopyVector3(tmp_v, dir);
    m3dScaleVector3(tmp_v, distance);
    m3dAddVectors3(intersection_p, start, tmp_v);

    return type; // Return the intersection condition
}

void Sphere::shade(M3DVector3f view, M3DVector3f intersect_p, const Light &sp_light, M3DVector3f am_light, M3DVector3f color, bool shadow) {
    M3DVector3f light_spot, light_illumination;
    sp_light.get_light(light_spot, light_illumination);
    
    // Calculate the vector from the sphere center to the intersection point
    M3DVector3f l;
    m3dSubtractVectors3(l, intersect_p, _pos);
    m3dNormalizeVector(l);
    
    // Calculate the vector from the intersection point to the light source
    M3DVector3f m;
    m3dSubtractVectors3(m, light_spot, intersect_p);
    m3dNormalizeVector(m);

    // Calculate the diffuse component
    float scatter = m3dDotProduct(m, l);
    
    // Calculate reflection vector for specular component
    M3DVector3f n;
    m3dCopyVector3(n, l);
    m3dScaleVector3(n, 2 * scatter);
    m3dSubtractVectors3(n, m, n);
    
    // Calculate the specular component
    float spec = m3dDotProduct(n, view);
    
    // Calculate the final color based on ambient, diffuse, and specular contributions
    for (int i = 0; i < 3; i++) {
        color[i] = _ka * _color[i] * am_light[i]; // Ambient component

        if (scatter > 0) {
            color[i] += _kd * _color[i] * light_illumination[i] * scatter; // Diffuse component
        }
        if (spec > 0) {
            color[i] += _ks * light_illumination[i] * pow(spec, 100); // Specular component
        }
    }
}

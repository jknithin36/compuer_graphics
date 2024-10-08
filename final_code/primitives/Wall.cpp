// #include "Wall.h"
// #include <math.h>
// #include "../Imageio/Imageio.h"

// Intersect_Cond Wall::intersection_check(const M3DVector3f start, const M3DVector3f dir, float &distance, M3DVector3f intersection_p)
// {
// 	if (_tr1.intersection_check(start,dir,distance,intersection_p) == _k_hit)
// 	{
// 		return _k_hit;
// 	}else
// 	{
// 		return _tr2.intersection_check(start,dir,distance,intersection_p);
// 	}
// }


// void	Wall::shade(M3DVector3f view, M3DVector3f intersect_p,const Light & sp_light, M3DVector3f am_light, M3DVector3f color,bool shadow)
// {
// 	for (int i = 0; i < 3; i++)
// 	{
// 		color[i] = _color[i];
// 	}
// }


// void	Wall::get_reflect_direct(const M3DVector3f direct0,const M3DVector3f intersect_p, M3DVector3f reflect_direct)
// {
	
// }


// void Wall::load_texture(std::string file_name)
// {
	
// }

// void Wall::texture_color(M3DVector3f pos, M3DVector3f color)
// {
// }

// void	Wall::get_texel(float x, float y, M3DVector3f color)
// {
// 	return;
// }

#include "Wall.h"
#include <cmath> // Use <cmath> instead of <math.h> for C++
#include "../Imageio/Imageio.h"

// Check if the ray intersects with either triangle of the wall
Intersect_Cond Wall::intersection_check(const M3DVector3f start, const M3DVector3f dir, float &distance, M3DVector3f intersection_p) {
    // Check intersection with the first triangle
    if (_tr1.intersection_check(start, dir, distance, intersection_p) == _k_hit) {
        return _k_hit; // Hit if the first triangle is intersected
    } else {
        // Check intersection with the second triangle
        return _tr2.intersection_check(start, dir, distance, intersection_p);
    }
}

// Shade the wall with its base color (currently no shading calculations)
void Wall::shade(M3DVector3f view, M3DVector3f intersect_p, const Light &sp_light, M3DVector3f am_light, M3DVector3f color, bool shadow) {
    for (int i = 0; i < 3; i++) {
        color[i] = _color[i]; // Set color based on the wall's color
    }
}

// Placeholder for calculating reflected direction (not implemented)
void Wall::get_reflect_direct(const M3DVector3f direct0, const M3DVector3f intersect_p, M3DVector3f reflect_direct) {
    // Functionality not implemented yet
}

// Load a texture from a file (not implemented)
void Wall::load_texture(std::string file_name) {
    // Functionality not implemented yet
}

// Get the color from the texture at a specific position (not implemented)
void Wall::texture_color(M3DVector3f pos, M3DVector3f color) {
    // Functionality not implemented yet
}

// Get the texel color at the given texture coordinates (not implemented)
void Wall::get_texel(float x, float y, M3DVector3f color) {
    // Functionality not implemented yet
    return;
}

#pragma once
#include "Sprite3D.h"

class Sphere : public Sprite3D
{
public:
	Sphere(Shaders* shader, Camera* camera, Texture* texture);
	Sphere(Shaders* shader, Camera* camera, Vector4 color);
	~Sphere();
};
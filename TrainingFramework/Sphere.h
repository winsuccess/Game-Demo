#pragma once
#include "Sprite3D.h"

class Sphere : public Sprite3D
{
public:
	Sphere(Models* model, Shaders* shader, Camera* camera, Texture* texture);
	Sphere(Models* model, Shaders* shader, Camera* camera, Vector4 color);
	~Sphere();
};
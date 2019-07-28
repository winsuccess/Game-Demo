#pragma once
#include "Sprite3D.h"

class Sphere : public Sprite3D
{
public:
	Sphere();
	Sphere(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, std::unique_ptr<Texture> texture);
	Sphere(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera,Vector4 color);
	~Sphere();
};
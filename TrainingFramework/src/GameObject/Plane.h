#pragma once
#include "Sprite3D.h"
class Plane : public Sprite3D
{
public:
	Plane();
	Plane(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, std::unique_ptr<Texture> texture);
	Plane(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, Vector4 color);
	~Plane();
};

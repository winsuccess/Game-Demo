#pragma once
#include "Sprite3D.h"
class Cube : public Sprite3D
{
public:
	Cube();
	Cube(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, std::unique_ptr<Texture> texture);
	Cube(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, Vector4 color);
	~Cube();
};


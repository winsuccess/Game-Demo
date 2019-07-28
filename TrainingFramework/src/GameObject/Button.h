#pragma once
#include "Sprite2D.h"

class Button : public Sprite2D
{
public:
	Button();
	Button (std::unique_ptr<Shaders> shader, std::unique_ptr<Texture> texture);
	Button(std::unique_ptr<Shaders> shader, Vector4 color);
	~Button();
};
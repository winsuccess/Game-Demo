#pragma once
#include "Sprite2D.h"

class Button : public Sprite2D
{
public:
	Button(Shaders* shader, Texture* texture);
	Button(Shaders* shader, Vector4 color);
	~Button();
};
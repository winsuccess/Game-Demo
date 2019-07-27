#pragma once
#include "baseobject.h"

class Sprite2D : public BaseObject
{
private:
	std::string		m_Text;
	Vector2			m_Vec2DPos;
	GLint			m_iHeight;
	GLint			m_iWidth;

	void			CaculateWorldMatrix();

public:
	Sprite2D(Models* model, Shaders* shader, Texture * texture);
	Sprite2D(Models* model, Shaders* shader, Vector4 color);
	~Sprite2D();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	void		SetText(std::string text);
	std::string	GetText();

	void		Set2DPosition(GLfloat x, GLfloat y);
	void		Set2DPosition(Vector2 pos);

	Vector2		Get2DPosition();
	void		SetSize(GLint width, GLint height);

};


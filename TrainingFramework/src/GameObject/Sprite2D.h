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
	Sprite2D();
	Sprite2D(std::unique_ptr<Models> model, std::unique_ptr<Shaders> shader, std::unique_ptr<Texture> texture);
	Sprite2D(std::unique_ptr<Models> model, std::unique_ptr<Shaders> shader, Vector4 color);
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


#pragma once
#include "baseobject.h"


class Sprite3D : public BaseObject
{
private:
	void			CaculateWorldMatrix();

public:
	Sprite3D();
	Sprite3D(Models* model, Shaders* shader, Camera* camera, Texture * texture);
	Sprite3D(Models* model, Shaders* shader, Camera* camera, Vector4 color);
	~Sprite3D();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;


	void			Set3DPosition(Vector3 pos);
	Vector3			Get3DPosition();
	void			Set3DScale(Vector3 sca);
	Vector3			Get3DScale();
	void			Set3DRotation(Vector3 ros);
	Vector3			Get3DRotation();

};


#pragma once
#include "utilities.h" 


class Shaders;
class Models;
class Texture;
class Camera;
class BaseObject
{

private:
	GLint			m_Id;
	std::string		m_Name;

protected:
	Vector3			m_Vec3Position;
	Vector3			m_Vec3Scale;
	Vector3			m_Vec3Rotation;
	Vector4			m_Color;

	Matrix			m_WorldMat;

	Models			*m_pModel;
	Shaders			*m_pShader;
	Camera			*m_pCamera;
	Texture			*m_pTexture;
public:
	BaseObject() {
		m_Id = 0;
		m_Name = "name";

		m_Vec3Position = Vector3(0, 0, 0);
		m_Vec3Scale = Vector3(1, 1, 1);
		m_Vec3Rotation = Vector3(0, 0, 0);
		m_Color = Vector4(0.5, 0.5, 0.5, 1.0);

		m_pModel = nullptr;
		m_pShader = nullptr;
		m_pCamera = nullptr;
		m_pTexture = nullptr;
	}
	virtual ~BaseObject() {}

	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update(GLfloat deltaTime) = 0;

	// get - set
	void			SetObjectID(GLuint id) { m_Id = id; }
	GLint			GetObjectID(GLuint id) { return	m_Id; }

	void			SetName(std::string name) { m_Name = name; }
	std::string		GetName() { return	m_Name; }


	void			SetColor(Vector4 color) { m_Color = color; }

	void			SetCamera(Camera *cam) { m_pCamera = cam; }

	void			SetModels(Models* mod) { m_pModel = mod; }

	void			SetShaders(Shaders* sha) { m_pShader = sha; }

	void			SetTexture(Texture* tex) { m_pTexture = tex; }

};


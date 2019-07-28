#pragma once
#include "utilities.h" 
#include <memory>
#include "Shaders.h"
#include "Models.h"
#include "Camera.h"
#include "Texture.h"

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
	
	std::unique_ptr<Models> m_pModel{ new Models() };
	std::unique_ptr<Shaders> m_pShader{ new Shaders() };
	std::shared_ptr<Camera> m_pCamera{ new Camera() };
	std::unique_ptr<Texture> m_pTexture{ new Texture() };

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

	void			SetCamera(std::unique_ptr<Camera> cam) { m_pCamera = std::move(cam); }

	void			SetModels(std::unique_ptr<Models> mod) { m_pModel = std::move(mod); }

	void			SetShaders(std::unique_ptr<Shaders> sha) { m_pShader = std::move(sha); }

	void			SetTexture(std::unique_ptr<Texture> tex) { m_pTexture = std::move(tex); }

};


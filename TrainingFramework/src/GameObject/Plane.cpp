#include "Plane.h"
#include "Camera.h"
#include "Shaders.h"
#include "Models.h"
#include "Texture.h"

Plane::Plane()
{

}

Plane::Plane(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, std::unique_ptr<Texture> texture) : Sprite3D()
{
	std::unique_ptr<Models> model(new Models());
	model->Init("..\\Data\\Model\\Plane.nfg", NFG);
	m_pModel = std::move(model);
	m_pShader = std::move(shader);
	m_pCamera = camera;
	m_pTexture = std::move(texture);
}

Plane::Plane(std::unique_ptr<Shaders> shader, std::shared_ptr<Camera> camera, Vector4 color) : Sprite3D()
{
	std::unique_ptr<Models> model(new Models());
	model->Init("..\\Data\\Model\\Cube.nfg", NFG);
	m_pModel = std::move(model);
	m_pShader = std::move(shader);
	m_pCamera = camera;
	m_pTexture = nullptr;
	m_Color = color;
}

Plane::~Plane()
{

}
#include "Sphere.h"
#include "Camera.h"
#include "Shaders.h"
#include "Models.h"
#include "Texture.h"

Sphere::Sphere( Shaders* shader, Camera* camera, Texture* texture) : Sprite3D()
{
	Models* model = new Models();
	model->Init("..\\Data\\Model\\Bila.nfg", NFG);
	m_pModel = model;
	m_pShader = shader;
	m_pCamera = camera;
	m_pTexture = texture;
}

Sphere::Sphere(Shaders* shader, Camera* camera, Vector4 color) : Sprite3D()
{
	Models* model = new Models();
	model->Init("..\\Data\\Model\\Bila.nfg", NFG);
	m_pModel = model;
	m_pShader = shader;
	m_pCamera = camera;
	m_pTexture = nullptr;
	m_Color = color;
}

Sphere::~Sphere()
{

}
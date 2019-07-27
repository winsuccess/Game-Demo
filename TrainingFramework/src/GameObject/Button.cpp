#include "Button.h"
#include "Shaders.h"
#include "Models.h"
#include "Camera.h"
#include "Texture.h"

Button::Button(Shaders* shader, Texture* texture)
{
	Models* model = new Models();
	model->Init("..\\Data\\Model\\rectangle.nfg", NFG);
	m_pModel = model;
	m_pShader = shader;
	m_pCamera = nullptr;
	m_pTexture = texture;

	m_Vec3Position = Vector3(0, 0, 0);
}

Button::Button(Shaders* shader, Vector4 color)
{
	Models* model = new Models();
	model->Init("..\\Data\\Model\\rectangle.nfg", NFG);
	m_pModel = model;
	m_pShader = shader;
	m_pCamera = nullptr;
	m_pTexture = nullptr;
	m_Color = color;

	m_Vec3Position = Vector3(0, 0, 0);
}

Button::~Button()
{

 }
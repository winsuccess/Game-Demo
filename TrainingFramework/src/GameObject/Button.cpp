#include "Button.h"
#include "Shaders.h"
#include "Models.h"
#include "Camera.h"
#include "Texture.h"

Button::Button()
{

}

Button::Button(std::unique_ptr<Shaders> shader, std::unique_ptr<Texture> texture)
{
	std::unique_ptr<Models> model(new Models());
	model->Init("..\\Data\\Model\\Rectangle.nfg", NFG);
	m_pModel = std::move(model);
	m_pShader = std::move(shader);
	m_pTexture = std::move(texture);
	m_pCamera = nullptr;

	m_Vec3Position = Vector3(0, 0, 0);
}

Button::Button(std::unique_ptr<Shaders> shader, Vector4 color)
{
	std::unique_ptr<Models> model(new Models());
	model->Init("..\\Data\\Model\\Rectangle.nfg", NFG);
	m_pModel = std::move(model);
	m_pShader = std::move(shader);
	m_pCamera = nullptr;
	m_pTexture = nullptr;
	m_Color = color;

	m_Vec3Position = Vector3(0, 0, 0);
}

Button::~Button()
{

 }

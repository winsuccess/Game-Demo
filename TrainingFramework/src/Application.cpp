#include "Application.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
extern GLint screenWidth;
extern GLint screenHeight;

Application::Application(void)
{
}


Application::~Application(void)
{
}


void Application::Init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	std::unique_ptr<Shaders> m_Shaders (new Shaders());
	std::unique_ptr<Texture> m_texture(new Texture());;
	std::unique_ptr<Models> m_model (new Models());;
	std::shared_ptr<Camera> m_Camera(new Camera());;

	//Start Button
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\sgbutton.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Button = std::unique_ptr<Button>(new Button(std::move(m_Shaders),std::move(m_texture)));
	m_Button->Set2DPosition(320, 50);
	m_Button->SetSize(400, 100);
	m_Button->Init();


	//camera
	Vector3 CameraPos(10, 40, 40);
	Vector3 TargetPos(0, 0, 0);
	float fFovY = 0.7f;
	m_Camera->Init(CameraPos, TargetPos, fFovY, (GLfloat)screenWidth / screenHeight, 1.0f, 5000.0f, 1.0f);


	//plan
	m_model.reset(new Models());
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_model->Init("..\\Data\\Model\\Plan.nfg", NFG);
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\Dirt.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Plan = std::unique_ptr<Sprite3D>(new Sprite3D(std::move(m_model), std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Plan->Set3DScale(Vector3(20, 20, 20));
	m_Plan->Init();


	//box
	m_model.reset(new Models());
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_model->Init("..\\Data\\Model\\box.nfg", NFG);
	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\ColorShader.fs");
	m_Sprite3D = std::unique_ptr<Sprite3D>(new Sprite3D(std::move(m_model), std::move(m_Shaders), m_Camera, Vector4(0.0, 0.0, 1.0, 0.5)));
	m_Sprite3D->Set3DScale(Vector3(1, 1, 1));
	m_Sprite3D->Init();


	//sphere
	m_model.reset(new Models());
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\Rock.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Sphere = std::unique_ptr<Sphere>(new Sphere(std::move(m_Shaders), m_Camera, std::move(m_texture)) );
	m_Sphere->Init();
	m_Sphere->Set3DScale(Vector3(0.1, 0.1, 0.1));

}

void Application::Update(GLfloat deltaTime)
{
	//update
	m_Button->Update(deltaTime);
	m_Plan->Update(deltaTime);
	m_Sprite3D->Update(deltaTime);
	m_Sphere->Update(deltaTime);
}

void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw
	
	//3D
	m_Plan->Draw();
	m_Sprite3D->Draw();
	m_Sphere->Draw();
	
	//2D
	m_Button->Draw();
}

void Application::HandleKeyEvent(unsigned char key, bool bIsPresseded)
{

}

void Application::HandleTouchEvent(GLint x, GLint y, bool bIsPresseded)
{
}

void Application::Exit()
{
	exit(0);
}

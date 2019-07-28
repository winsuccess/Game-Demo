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

	std::unique_ptr<Shaders> m_Shaders(new Shaders());
	std::unique_ptr<Texture> m_texture(new Texture());;
	std::unique_ptr<Models> m_model(new Models());;
	std::shared_ptr<Camera> m_Camera(new Camera());;

	//Start Button
	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\sgbutton.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Button = std::unique_ptr<Button>(new Button(std::move(m_Shaders), std::move(m_texture)));
	m_Button->Set2DPosition(320, 50);
	m_Button->SetSize(400, 100);
	m_Button->Init();


	//camera
	Vector3 CameraPos(10, 40, 40);
	Vector3 TargetPos(0, 0, 0);
	float fFovY = 0.7f;
	m_Camera->Init(CameraPos, TargetPos, fFovY, (GLfloat)screenWidth / screenHeight, 1.0f, 5000.0f, 1.0f);


	//plane
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\ColorShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\space.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Plane = std::unique_ptr<Plane>(new Plane(std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Plane->Set3DScale(Vector3(15, 15, 15));
	m_Plane->Init();


	//Cube
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\rmarble.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Cube = std::unique_ptr<Cube>(new Cube(std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Cube->Set3DScale(Vector3(3, 3, 3));
	m_Cube->Init();
	m_Cube->Set3DPosition(Vector3(1, 10, 1));


	//sphere1
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\mercury.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Sphere1 = std::unique_ptr<Sphere>(new Sphere(std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Sphere1->Init();
	m_Sphere1->Set3DScale(Vector3(0.03, 0.03, 0.03));
	m_Sphere1->Set3DPosition(Vector3(-20, -10, 0));

	//sphere2
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\venus.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Sphere2 = std::unique_ptr<Sphere>(new Sphere(std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Sphere2->Init();
	m_Sphere2->Set3DScale(Vector3(0.07, 0.07, 0.07));
	m_Sphere2->Set3DPosition(Vector3(-10, -10, -0));

	//sphere3
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\mars.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Sphere3 = std::unique_ptr<Sphere>(new Sphere(std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Sphere3->Init();
	m_Sphere3->Set3DScale(Vector3(0.05, 0.05, 0.05));
	m_Sphere3->Set3DPosition(Vector3(0, -10, 0));

	//sphere4
	m_Shaders.reset(new Shaders());
	m_texture.reset(new Texture());

	m_Shaders->Init("..\\Data\\Shaders\\TextureShader.vs", "..\\Data\\Shaders\\TextureShader.fs");
	m_texture->Init("..\\Data\\Textures\\neptune.tga", GL_CLAMP_TO_EDGE, GL_LINEAR_MIPMAP_LINEAR);
	m_Sphere4 = std::unique_ptr<Sphere>(new Sphere(std::move(m_Shaders), m_Camera, std::move(m_texture)));
	m_Sphere4->Init();
	m_Sphere4->Set3DScale(Vector3(0.09, 0.09, 0.09));
	m_Sphere4->Set3DPosition(Vector3(10, -10, 0));

}

void Application::Update(GLfloat deltaTime)
{
	//update
	m_Button->Update(deltaTime);
	m_Plane->Update(deltaTime);
	m_Cube->Update(deltaTime);
	m_Sphere1->Update(deltaTime);
	m_Sphere2->Update(deltaTime);
	m_Sphere3->Update(deltaTime);
	m_Sphere4->Update(deltaTime);
}

void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw

	//3D
	m_Plane->Draw();
	m_Cube->Draw();
	m_Sphere1->Draw();
	m_Sphere2->Draw();
	m_Sphere3->Draw();
	m_Sphere4->Draw();

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

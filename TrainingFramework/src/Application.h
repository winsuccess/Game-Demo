#pragma once
#include "Singleton.h"
#include "GameConfig.h"

#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Sphere.h"

class Application : public CSingleton<Application>
{
public:
	Application(void);
	~Application(void);
	void		Init();
	void		Update( GLfloat deltaTime);
	void		Render();
	void		HandleKeyEvent(unsigned char key, bool bIsPresseded);
	void		HandleTouchEvent(GLint x, GLint y, bool bIsPresseded);
	void		Exit();

private:
	
	Sprite2D *	m_Sprite2D;
	Sprite3D *	m_Plan;
	Sprite3D *	m_Sprite3D1;
	Sprite3D *	m_Sprite3D;
	

};


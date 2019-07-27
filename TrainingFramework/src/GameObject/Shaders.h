#pragma once
#include "utilities.h"

class Shaders 
{
private:
	GLuint		m_iShaderID;
	char		fileVS[260];
	char		fileFS[260];
	GLuint		vertexShader;
	GLuint		fragmentShader;
public:
	Shaders();
	~Shaders();

	GLuint		program;
	GLint		iTextureLoc[5];

	GLint		Init(char * fileVertexShader, char * fileFragmentShader);
	void		EnableTest(GLuint);
	void		EnableAlpha();

	void		SetShaderID(GLuint);
	GLuint		GetShaderID();
	GLuint		GetAttribLocation(char *str);
	GLuint		GetUniformLocation(char *str);
};
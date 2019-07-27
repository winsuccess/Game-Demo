#pragma once
#include "Vertex.h"

class Models
{
private:
	GLuint		m_iModelID;
	GLuint		m_iNumIndices;
	GLuint		m_iVboID; 
	GLuint		m_iIboID;
	void		Filter(unsigned char * pBuffer, GLint range);
public:
	int			Init(const char *szFileName, GLuint type);
	int			Init(GLuint type);
	GLuint		GetVertexObject();
	GLuint		GetIndiceObject();
	GLuint		GetNumIndiceObject();
	void		SetModelId(GLuint);
	GLuint		GetModelId();
};
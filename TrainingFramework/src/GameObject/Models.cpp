#include "Models.h"
#include "utilities.h" 


void Models::Filter(unsigned char * pBuffer, GLint range)
{
	unsigned char * pTemp =new unsigned char[range*range];
	GLfloat fAvg,fNum;
	GLint ii,jj;
	for(GLint i=0;i<range;i++)
	{
		for(GLint j=0;j<range;j++)
		{
			fAvg=0.0;
			fNum=0.0;
			for( ii=i-1;ii<=i+1;ii++)
			{
				for( jj=j-1;jj<=j+1;jj++)
				{
					if((ii<0)||(ii>=range)||(jj<0)||(jj>range)) continue;
					fNum+=1.0;
					fAvg+= pBuffer[ii*range+jj];
				}
			}
			pTemp[i*range+j]=( unsigned char)(fAvg/fNum);
		}
	}
	memcpy(pBuffer,pTemp,range*range);
	delete []pTemp;
}

int Models::Init(const char *szFileName, GLuint type)
{

	FILE *f = fopen(szFileName, "rb" );
	if (f == NULL)
	{
		LOGE("ERROR %s \n",szFileName);
		return 0;
	}
	LOGI("Load Models:%s\t\t",szFileName);

	GLuint iNumVertex=0;
	Vertex *verticesData;
	GLuint *Indices;
	if(type == NFG)
	{
		GLuint line=0, iTemp=0;
		float x=0;
		char *strtemp=new char[255];
		char temp;

		FSCANF(f,"%s",strtemp);
		FSCANF(f,"%d",&iNumVertex);
		//LOGI("  Verte: %d ",iNumVertex);

		verticesData=new Vertex[iNumVertex];
		for(GLuint i=0;i<iNumVertex;i++)
		{
			FSCANF(f,"%d",&line);
			//read position
			fread(strtemp,7,1,f);FSCANF(f,"%f",&x); (verticesData[i]).position.x=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).position.y=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).position.z=x;
			//read normal
			fread(strtemp,9,1,f);FSCANF(f,"%f",&x);(verticesData[i]).normal.x=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).normal.y=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).normal.z=x;
			//read binorm
			fread(strtemp,11,1,f);FSCANF(f,"%f",&x);(verticesData[i]).bitangent.x=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).bitangent.y=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).bitangent.z=x;
			//read tgt
			fread(strtemp,8,1,f);FSCANF(f,"%f",&x);(verticesData[i]).tangent.x=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).tangent.y=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).tangent.z=x;
			//read uv
			fread(strtemp,7,1,f);FSCANF(f,"%f",&x);(verticesData[i]).uv.x=x;
			FSCANF(f,"%c",&temp);FSCANF(f,"%f",&x);(verticesData[i]).uv.y=x;
			fread(strtemp,2,1,f);
		}

		fread(strtemp,11,1,f);
		FSCANF(f,"%d",&m_iNumIndices);
		//LOGI("Indices: %d\t",m_iNumIndices);
		Indices= new GLuint[m_iNumIndices];
		for(GLuint i=0;i<m_iNumIndices/3;i++)
		{
			FSCANF(f,"%d",&line);
			FSCANF(f,"%c",&temp);FSCANF(f,"%d",&iTemp); (Indices[3*i+0])=iTemp;
			FSCANF(f,"%c",&temp);FSCANF(f,"%d",&iTemp); (Indices[3*i+1])=iTemp;
			FSCANF(f,"%c",&temp);FSCANF(f,"%d",&iTemp); (Indices[3*i+2])=iTemp; 
			FSCANF(f,"%c",&temp);
		}
		delete [] strtemp;
	}
	
	//buffer object
	glGenBuffers(1, &m_iVboID);
	glBindBuffer(GL_ARRAY_BUFFER, m_iVboID);
	glBufferData(GL_ARRAY_BUFFER, iNumVertex* sizeof(Vertex), verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//if(m_iIboID == 0)
	{
		glGenBuffers(1, &m_iIboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iIboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_iNumIndices *sizeof(GLuint), Indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	fclose( f );
	delete [] verticesData;
	delete [] Indices;
	LOGI("Done.\n");
	return 0;
}

int Models::Init(GLuint type)
{
	GLuint iNumVertex=0;
	Vertex *verticesData;
	GLuint *Indices;
	if(type == GAME_3D_SPRITE)
	{
		//gen model
		iNumVertex		= 8;
		verticesData	= new Vertex[iNumVertex];
		int ii			= 0;
		float ratio		= 1;
		float r			= 1;
		float angle		= 0;
		float height	= -1.0;
		//A
		verticesData[ii].position.x	= 1;
		verticesData[ii].position.y	= 1;
		verticesData[ii].position.z	= 1;
		verticesData[ii].uv.x		= 0.0;
		verticesData[ii].uv.y		= 0.0;
		ii++;
		//B
		verticesData[ii].position.x	= -1;
		verticesData[ii].position.y	= 1;
		verticesData[ii].position.z	= 1;
		verticesData[ii].uv.x		= 0.0;
		verticesData[ii].uv.y		= 0.0;
		ii++;
		//C
		verticesData[ii].position.x	= -1;
		verticesData[ii].position.y	= 1;
		verticesData[ii].position.z	= -1;
		verticesData[ii].uv.x		= 0.0;
		verticesData[ii].uv.y		= 0.0;
		ii++;
		//D
		verticesData[ii].position.x	= 1;
		verticesData[ii].position.y	= 1;
		verticesData[ii].position.z	= -1;
		verticesData[ii].uv.x		= 0.0;
		verticesData[ii].uv.y		= 0.0;
		ii++;

		//A
		verticesData[ii].position.x = 1;
		verticesData[ii].position.y = -1;
		verticesData[ii].position.z = 1;
		verticesData[ii].uv.x = 0.0;
		verticesData[ii].uv.y = 0.0;
		ii++;
		//B
		verticesData[ii].position.x = -1;
		verticesData[ii].position.y = -1;
		verticesData[ii].position.z = 1;
		verticesData[ii].uv.x = 0.0;
		verticesData[ii].uv.y = 0.0;
		ii++;
		//C
		verticesData[ii].position.x = -1;
		verticesData[ii].position.y = -1;
		verticesData[ii].position.z = -1;
		verticesData[ii].uv.x = 0.0;
		verticesData[ii].uv.y = 0.0;
		ii++;
		//D
		verticesData[ii].position.x = 1;
		verticesData[ii].position.y = -1;
		verticesData[ii].position.z = -1;
		verticesData[ii].uv.x = 0.0;
		verticesData[ii].uv.y = 0.0;
		ii++;

		ii		= 0;
		m_iNumIndices = 36;
		Indices	= new GLuint[m_iNumIndices];
		for (GLuint i = 0; i < m_iNumIndices; i++)
		{
			Indices [i] =0;
		}
		Indices [ii] = 0; ii++;
		Indices [ii] = 1; ii++;
		Indices [ii] = 5; ii++;

		Indices [ii] = 0; ii++;
		Indices [ii] = 1; ii++;
		Indices [ii] = 2; ii++;

		Indices [ii] = 0; ii++;
		Indices [ii] = 5; ii++;
		Indices [ii] = 4; ii++;

		Indices [ii] = 0; ii++;
		Indices [ii] = 2; ii++;
		Indices [ii] = 3; ii++;

		Indices [ii] = 0; ii++;
		Indices [ii] = 3; ii++;
		Indices [ii] = 7; ii++;

		Indices [ii] = 0; ii++;
		Indices [ii] = 7; ii++;
		Indices [ii] = 4; ii++;

		Indices [ii] = 6; ii++;
		Indices [ii] = 5; ii++;
		Indices [ii] = 1; ii++;

		Indices [ii] = 6; ii++;
		Indices [ii] = 7; ii++;
		Indices [ii] = 3; ii++;

		Indices [ii] = 6; ii++;
		Indices [ii] = 5; ii++;
		Indices [ii] = 4; ii++;

		Indices [ii] = 6; ii++;
		Indices [ii] = 1; ii++;
		Indices [ii] = 2; ii++;

		Indices [ii] = 6; ii++;
		Indices [ii] = 3; ii++;
		Indices [ii] = 2; ii++;

		Indices [ii] = 6; ii++;
		Indices [ii] = 4; ii++;
		Indices [ii] = 7; ii++;
	}

	if(type == GAME_2D_SPRITE)
	{
		iNumVertex		= 4;
		verticesData	= new Vertex[iNumVertex];

		int ii			= 0;
		verticesData[ii].position	= Vector3(0.0, 0.0, 0.0);
		verticesData[ii].uv			= Vector2(0.0, 1.0);
		ii++;

		verticesData[ii].position	= Vector3(0.0, 1.0, 0.0);
		verticesData[ii].uv			= Vector2(0.0, 0.0);
		ii++;

		verticesData[ii].position	= Vector3(1.0, 1.0, 0.0);
		verticesData[ii].uv			= Vector2(1.0, 0.0);
		ii++;

		verticesData[ii].position	= Vector3(1.0, 0.0, 0.0);
		verticesData[ii].uv			= Vector2(1.0, 1.0);

		
		
		m_iNumIndices = 6;
		Indices	= new GLuint[m_iNumIndices];
		ii				= 0;
		Indices [ii] = 0; ii++;
		Indices [ii] = 1; ii++;
		Indices [ii] = 2; ii++;

		Indices [ii] = 0; ii++;
		Indices [ii] = 2; ii++;
		Indices [ii] = 3; ii++;
	}
	

	//buffer object
	glGenBuffers(1, &m_iVboID);
	glBindBuffer(GL_ARRAY_BUFFER, m_iVboID);
	glBufferData(GL_ARRAY_BUFFER, iNumVertex* sizeof(Vertex), verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//if(m_iIboID == 0)
	{
		glGenBuffers(1, &m_iIboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iIboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_iNumIndices *sizeof(GLuint), Indices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	delete [] verticesData;
	delete [] Indices;
	LOGI("Done.\n");
	return 0;
}

GLuint Models::GetVertexObject(){return m_iVboID;}
GLuint Models::GetIndiceObject(){return m_iIboID;}
GLuint Models::GetNumIndiceObject(){return m_iNumIndices;}
void Models::SetModelId(GLuint id){m_iModelID=id;}
GLuint Models::GetModelId(){return m_iModelID;}
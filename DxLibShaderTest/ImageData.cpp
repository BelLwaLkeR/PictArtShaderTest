#include "ImageData.h"
#include <Light.h>

ImageData::ImageData(	const std::string& imagePath,
						const std::string& shaderPath,
						const std::string& bumpMapPath,
						std::weak_ptr<Light> pLight,
						int posX,
						int posY){
	setup(imagePath, shaderPath, bumpMapPath, pLight, posX, posY, 64, 64);
}

ImageData::~ImageData(){
}

void ImageData::draw(){
	int tmpScreen = MakeScreen(m_sizeX, m_sizeY);
	SetDrawScreen(tmpScreen);
	ClearDrawScreen();
//	DrawGraph(m_posX - m_sizeX/2, m_posY - m_sizeY/2,m_ImageHandle, FALSE);
	DrawGraph(0, 0, m_ImageHandle, FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
	setShader();
	SetUseTextureToShader(0, m_ImageHandle);
	SetUseTextureToShader(1, m_BumpMapHandle);
	SetUseTextureToShader(2, m_ReflectionMapHandle);


	std::array<float, 3> relativeLightPosition	= getRelativeLightPosition();
	std::array<float, 3> ambientLightColor		= { 0.3f, 0.3f, 0.3f };
	std::array<float, 3> LightColor				= { 1.f, 1.f, 1.f };


	SetPSConstSF(0, m_sizeX);
	SetPSConstSF(1, m_sizeY);
	SetPSConstSFArray(2, &ambientLightColor[0]		, 3);
	SetPSConstSFArray(5, &LightColor[0]				, 3);
	SetPSConstSFArray(8, &relativeLightPosition[0]	, 3);
	SetPSConstSF(11, 5.f);

//	printfDx("\t\t\t\t\t%f, %f, %f\n", m_pLight.lock()->getPosition().x, m_pLight.lock()->getPosition().y, m_pLight.lock()->getPosition().z);

	DrawPolygon2DToShader(&m_Vertex[0], 2);
//	deleteShader();
}

std::array<float, 3> ImageData::getRelativeLightPosition()
{
	return {
		m_pLight.lock()->getPositionArray()[0] - (m_posX + m_sizeX/2),
		m_pLight.lock()->getPositionArray()[1] - (m_posY + m_sizeY/2),
		m_pLight.lock()->getPositionArray()[2] - 0
	};
}

void ImageData::setup(	const std::string& imagePath,
						const std::string& shaderPath,
						const std::string& bumpMapPath,
						std::weak_ptr<Light> pLight,
						int posX, int posY, int sizeX, int sizeY){
	m_ImageHandle			= LoadGraph(imagePath.c_str());
	m_ShaderHandle			= LoadPixelShader(shaderPath.c_str());
	m_BumpMapHandle			= LoadGraph(bumpMapPath.c_str());
	m_ReflectionMapHandle	= LoadGraph("./testReflectionImage.png");
	m_pLight				= pLight;
	m_posX					= posX;
	m_posY					= posY;
	m_sizeX					= sizeX;
	m_sizeY					= sizeY;
	setupVertex();
}

void ImageData::setupVertex(){
	for (int i = 0; i < 6; ++i) {
		m_Vertex[i].pos	= VGet((i%2)*m_sizeX+m_posX, (((i + 1) / 3) % 2)*m_sizeY+m_posY, 0);
		m_Vertex[i].rhw	= 1.f;
		m_Vertex[i].dif	= GetColorU8(255, 255,255,255);
		m_Vertex[i].spc	= GetColorU8(0, 0, 0, 0);
		m_Vertex[i].u	= (float)(i%2);
		m_Vertex[i].su	= (float)(i%2);
		m_Vertex[i].v	= (float)(((i+1)/3)%2);
		m_Vertex[i].sv	= (float)(((i+1)/3)%2);
	}
}

void ImageData::setShader(){
	SetUsePixelShader(m_ShaderHandle);
}

void ImageData::deleteShader(){
	DeleteShader(m_ShaderHandle);
}

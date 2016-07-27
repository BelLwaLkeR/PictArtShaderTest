#pragma once
#include <string>
#include <array>
#include <memory>
#include <DxLib.h>

class Light;

class ImageData
{
public:
	ImageData(const std::string& imagePath, const std::string& shaderPath, const std::string& bumpMapPath, std::weak_ptr<Light> pLight, int posX, int posY);
	~ImageData();
	void draw();

	std::array<float, 3> getRelativeLightPosition();

private:
	int m_posX;
	int m_posY;
	int m_sizeX;
	int m_sizeY;

	int m_ImageHandle;
	int m_ShaderHandle;
	int m_BumpMapHandle;
	int m_ReflectionMapHandle;

	std::array<VERTEX2DSHADER, 6>	m_Vertex;
	std::weak_ptr<Light>			m_pLight;

	void setup(const std::string& imagePath, const std::string& shaderPath, const std::string& bumpMapPath, std::weak_ptr<Light> pLight, int posX, int posY, int sizeX, int sizeY);
	void setupVertex();
	void setShader();
	void deleteShader();
};





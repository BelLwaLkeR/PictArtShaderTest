#include <DxLib.h>
#include <ImageData.h>
#include <Light.h>
#include <cmath>
#include <memory>

void dispRelativeLightPosition(std::weak_ptr<ImageData> image1, std::weak_ptr<ImageData> image2) {
	using namespace std;
	float length1 = sqrt(
		pow(image1.lock()->getRelativeLightPosition()[0], 2) +
		pow(image1.lock()->getRelativeLightPosition()[1], 2) +
		pow(image1.lock()->getRelativeLightPosition()[2], 2)
		);

	float  length2 = sqrt(
		pow(image2.lock()->getRelativeLightPosition()[0], 2) +
		pow(image2.lock()->getRelativeLightPosition()[1], 2) +
		pow(image2.lock()->getRelativeLightPosition()[2], 2)
		);
	printfDx("\t\t\t\t\t1[X:%04.2f, Y:%04.2f, Z:%04.2f, L:%04.2f],\t2[X:%04.2f, Y:%04.2f, Z:%04.2f, L:%04.2f]\n",
		image1.lock()->getRelativeLightPosition()[0],
		image1.lock()->getRelativeLightPosition()[1],
		image1.lock()->getRelativeLightPosition()[2],
		length1,
		image2.lock()->getRelativeLightPosition()[0],
		image2.lock()->getRelativeLightPosition()[1],
		image2.lock()->getRelativeLightPosition()[2],
		length2
		);

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	SetGraphMode(1280, 720, 32);
//	SetGraphMode(168, 106, 32);
	SetUseDirect3DVersion(DX_DIRECT3D_9);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	std::shared_ptr<Light> light = std::make_shared<Light>(50, 50, 20, 1);
	std::shared_ptr<ImageData> image1 = std::make_shared<ImageData>("./testImage.png", "./testLighting.pso", "./testNormalMap.png", light, 20, 20);
	std::shared_ptr<ImageData> image2 = std::make_shared<ImageData>("./testImage.png", "./testLighting.pso", "./testNormalMap.png", light, 84, 20);

	bool isGameEnd = false;
	while (!ProcessMessage() || isGameEnd) {
		ClearDrawScreen();
		DrawBox(0, 0, 1280, 720, GetColor(32, 64, 32), TRUE);

		light->update();
		image1->draw();
		image2->draw();
		light->draw();
		dispRelativeLightPosition(image1, image2);
		ScreenFlip();
	}
	DxLib_End();
}




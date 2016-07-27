#pragma once
#include <DxLib.h>
#include <array>

class Light{

public:
	Light(float posX, float posY, float posZ, float moveSpeed);
	~Light();
	void update();
	void draw();

	const FLOAT3& getPosition() const;
	const FLOAT4& getColor() const;

	const std::array<float, 3> getPositionArray() const;
	const std::array<float, 4> getColorArray() const;

private:
	FLOAT3	m_Position;
	FLOAT3	m_DefaultPosition;
	FLOAT4	m_Color;
	float	m_MoveSpeed;

	void moveX(float velocity);
	void moveY(float velocity);
	void moveZ(float velocity);
	void resetPosition();
};








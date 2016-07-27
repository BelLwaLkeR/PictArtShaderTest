#include "Light.h"
#include <DxLib.h>

Light::Light(float posX, float posY, float posZ, float moveSpeed) :
	m_Position({ posX, posY, posZ }),
	m_DefaultPosition({ posX, posY, posZ }),
	m_MoveSpeed(moveSpeed){


}

Light::~Light(){
}

void Light::update(){
	if (CheckHitKey(KEY_INPUT_LEFT)		)	{ moveX(-m_MoveSpeed);	}
	if (CheckHitKey(KEY_INPUT_RIGHT)	)	{ moveX( m_MoveSpeed);	}
	if (CheckHitKey(KEY_INPUT_UP)		)	{ moveY(-m_MoveSpeed);	}
	if (CheckHitKey(KEY_INPUT_DOWN)		)	{ moveY( m_MoveSpeed);	}
	if (CheckHitKey(KEY_INPUT_PGUP)		)	{ moveZ(-m_MoveSpeed);	}
	if (CheckHitKey(KEY_INPUT_PGDN)		)	{ moveZ( m_MoveSpeed);	}
	if (CheckHitKey(KEY_INPUT_R)		)	{ resetPosition();		}
}

void Light::draw(){
	DrawBox(m_Position.x-2, m_Position.y-2, m_Position.x+2, m_Position.y+2, GetColor(255,255,255), TRUE);

}

const FLOAT3& Light::getPosition() const{
	return m_Position;
}

const FLOAT4& Light::getColor() const{
	return m_Color;
}

const std::array<float, 3> Light::getPositionArray() const{
	return std::array<float, 3>{ m_Position.x, m_Position.y, m_Position.z };
}

const std::array<float, 4> Light::getColorArray() const{
	return std::array<float, 4>{ m_Color.x, m_Color.y, m_Color.z, m_Color.w };
}

void Light::moveX(float velocity){
	m_Position.x += velocity;
}

void Light::moveY(float velocity){
	m_Position.y += velocity;
}

void Light::moveZ(float velocity){
	m_Position.z += velocity;
}

void Light::resetPosition(){
	m_Position = m_DefaultPosition;
}

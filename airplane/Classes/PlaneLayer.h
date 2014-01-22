#pragma once
#include "cocos2d.h"

using namespace cocos2d;

const int AIRPLANE = 100;

class PlaneLayer:public Layer
{
public:
	PlaneLayer();
	~PlaneLayer();
	virtual bool init();
	static PlaneLayer* create();
	static PlaneLayer* sharedPlane;
};
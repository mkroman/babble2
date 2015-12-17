#pragma once
#include <SDL/SDL.h>

class EventHandler
{
public:
	EventHandler() {}
	virtual ~EventHandler() {}

	virtual void onInputFocus();
	virtual void onInputBlur();
	virtual void onKeyPress(SDLKey symbols, SDLMod modifiers, uint16_t unicode);
	virtual void onKeyRelease(SDLKey symbols, SDLMod modifiers, uint16_t unicode);
	virtual void onMouseFocus();
	virtual void onMouseBlur();
	virtual void onMouseMove(int x, int y, int rx, int ry, bool left, bool right, bool middle);
	virtual void onLeftButtonPress(int x, int y);
	virtual void onLeftButtonRelease(int x, int y);
	virtual void onRightButtonPress(int x, int y);
	virtual void onRightButtonRelease(int x, int y);
	virtual void onMiddleButtonPress(int x, int y);
	virtual void onMiddleButtonRelease(int x, int y);
	virtual void onMinimize();
	virtual void onRestore();
	virtual void onResize(int width, int height);
	virtual void onExpose();
	virtual void onExit();
	virtual void onUserEvent(uint8_t type, int code, void* data, void* extra);
};

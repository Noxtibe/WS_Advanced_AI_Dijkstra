#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Field.h"
#include <vector>

struct SDLNode
{
	SDL_FRect rect;
	const Nodes* node;
};

class SDLField
{
public :

	SDLField(Field* field);
	~SDLField();

	bool IsRunning() const;

	void Update();
	void Reset();

private :

	void ClearData();

	void HandleInput(const SDL_Event& event);
	void RenderNodes();

private :

	Field* _field = nullptr;

	//int _fieldRows;
	//int _fieldColumns;

	std::vector<SDLNode*> _nodes;

	// SDL
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

	static constexpr const char* WINDOW_NAME = "Visualization A Star";
	static constexpr int WINDOW_WIDTH = 1920;
	static constexpr int WINDOW_HEIGHT = 1080;
	static constexpr float NODE_PADDING = 3.0f;

	bool _isRunning = true;

	// Delta Time
	int lastTime = 0;
	static constexpr float STEP_DELAY = 0.025f; // Step time1
	float timeUntilStep = STEP_DELAY;

};


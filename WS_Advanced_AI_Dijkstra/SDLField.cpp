#include "SDLField.h"
#include <string>

using namespace std;

SDLField::SDLField(Field* field) : _field(field)
{
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_window, -1, 0);

	if (_window == nullptr || _renderer == nullptr)
	{
		throw string("Unable to Initialize SDL");
	}

	Reset();
}

SDLField::~SDLField()
{
	ClearData();
}

bool SDLField::IsRunning() const
{
	return _isRunning;
}

void SDLField::Update()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	HandleInput(event);

	// Delta
	int thisTime = SDL_GetTicks();
	float dt = ((float)thisTime - lastTime) / 1000.0f;
	lastTime = thisTime;

	timeUntilStep -= dt;

	if (timeUntilStep < 0.0f)
	{
		timeUntilStep = STEP_DELAY;
		_field->Step();
	}

	// Render
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	RenderNodes();
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(_renderer);
}

void SDLField::Reset()
{
	ClearData();
	const FieldType& nodeField = _field->GetField();

	const float totalPaddingWidth = _field->GetColumns() * NODE_PADDING + NODE_PADDING;
	const float totalPaddingHeight = _field->GetRows() * NODE_PADDING + NODE_PADDING;

	const float fieldWidth = WINDOW_WIDTH - totalPaddingWidth;
	const float fieldHeight = WINDOW_HEIGHT - totalPaddingHeight;

	float currentX = NODE_PADDING;
	float currentY = NODE_PADDING;

	const float nodeWidth = fieldWidth / (float)_field->GetColumns();
	const float nodeHeight = fieldHeight / (float)_field->GetRows();

	for (int i = 0; i < nodeField.size(); i++)
	{
		const vector<Nodes*>& row = nodeField.at(i);

		for (const Nodes* node : row)
		{
			_nodes.push_back(new SDLNode{ {currentX, currentY, nodeWidth, nodeHeight}, node });
			currentX += nodeWidth + NODE_PADDING;
		}
		currentY += nodeHeight + NODE_PADDING;
		currentX = NODE_PADDING;
	}
}

void SDLField::ClearData()
{
	for (SDLNode* node : _nodes)
	{
		delete node;
	}
	_nodes.clear();
}

void SDLField::HandleInput(const SDL_Event& event)
{
	switch(event.type)
	{
		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				_isRunning = false;
			}
			break;
		}

		case SDL_QUIT:
		{
			_isRunning = false;
			break;
		}

		default:
		{
			break;
		}
	}
}

void SDLField::RenderNodes()
{
	const vector<Nodes*>& openNodes = _field->GetOpenSet();
	const vector<Nodes*>& closedNodes = _field->GetClosedSet();
	const vector<Nodes*>& pathNodes = _field->GetShortestPathNodes();

	for (const SDLNode* node : _nodes)
	{
		if (node->node->isStart())
		{
			SDL_SetRenderDrawColor(_renderer, 45, 185, 115, 255);
		}
		else if (node->node->isTarget())
		{
			SDL_SetRenderDrawColor(_renderer, 50, 105, 185, 255);
		}
		else if (node->node->isObstacle())
		{
			SDL_SetRenderDrawColor(_renderer, 175, 15, 60, 255);
		}
		else if (count(pathNodes.cbegin(), pathNodes.cend(), node->node))
		{
			SDL_SetRenderDrawColor(_renderer, 15, 220, 45, 255);
		}
		else if (count(openNodes.cbegin(), openNodes.cend(), node->node))
		{
			SDL_SetRenderDrawColor(_renderer, 175, 180, 10, 255);
		}
		else if (count(closedNodes.cbegin(), closedNodes.cend(), node->node))
		{
			SDL_SetRenderDrawColor(_renderer, 110, 110, 102, 255);
		}
		else // Unexplored field
		{
			SDL_SetRenderDrawColor(_renderer, 240, 240, 220, 255);
		}
		SDL_RenderFillRectF(_renderer, &node->rect);
	}
}

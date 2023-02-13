#include <SFML/Graphics.hpp>
#include "settings.h"
#include "roadobj.h"
#include "player.h"

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setFramerateLimit(60);
	window.setPosition(Vector2i{(1440 - (int)WINDOW_WIDTH) / 2, 0});
	RoadObj grass1, grass2;
	roadObjInit(grass1, Vector2f{0.f,0.f}, "grass.jpg", 0.f);
	roadObjInit(grass2, Vector2f{ 0.f, -WINDOW_HEIGHT }, "grass.jpg", 0.f);
	Player player;
	playerInit(player);

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		roadObjUpdate(grass1);
		roadObjUpdate(grass2);
		
		window.clear();
		roadObjDraw(window, grass1);
		roadObjDraw(window, grass2);
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "ball.h"
#include "bat.h"
#include "textobj.h"
#include "brick.h"
#include "brickfield.h"
#include "functions.h"

using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE, 
		Style::Titlebar | Style::Close
	);
	window.setFramerateLimit(60);

	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	TextObj scoreText;
	textInit(scoreText, ball.score);
	BrickField field;
	brickFieldInit(field);
	

	while (window.isOpen())
	{
		//1 обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//обновление игровых объектов (функции update)
		ballUpdate(ball);
		batUpdate(bat);
		textUpdate(scoreText, ball.score);
		brickFieldUpdate(field);

		//проверка столкновений
		ballCollideWithBat(ball, bat);
		ballCollidedWithBricks(ball,field);

		//отрисовка объектов и обновление окна
		window.clear();
		brickFieldDraw(window, field);
		ballDraw(window, ball);
		batDraw(window, bat);
		textDraw(window, scoreText);
		window.display();
	}

	return 0;
}
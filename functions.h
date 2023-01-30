#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "ball.h"
#include "brickfield.h"

bool pointInRect(sf::RectangleShape rect, sf::Vector2f point) {
	return	rect.getPosition().x <= point.x &&
		point.x <= rect.getPosition().x + rect.getSize().x &&
		rect.getPosition().y <= point.y &&
		point.y <= rect.getPosition().y + rect.getSize().y;
}
int getBrickScore(const Brick& brick) {
	int score = 0;
	if (brick.color == sf::Color::Yellow)		score = 1;
	if (brick.color == sf::Color::Green)		score = 3;
	if (brick.color == sf::Color{ 255,165,0 })	score = 5;
	if (brick.color == sf::Color::Red)			score = 7;
	return score;
}
void ballCollidedWithBricks(Ball& ball, BrickField& brickfield) {
	sf::Vector2f midLeft{ 
		ball.shape.getPosition().x, 
		ball.shape.getPosition().y + BALL_RADIUS 
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,  
		ball.shape.getPosition().y 
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,  
		ball.shape.getPosition().y + 2 * BALL_RADIUS 
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS 
	};
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//� ������ ����� �������
			if (pointInRect(brickfield.arr[i][j].shape, midTop) && 
				brickfield.arr[i][j].color != sf::Color::Black) {
				ball.score += getBrickScore(brickfield.arr[i][j]);
				//������ �����, ������ � ���� ����
				brickfield.arr[i][j].color = sf::Color::Black;
				brickfield.arr[i][j].shape.setFillColor(sf::Color::Black);
				//��� ������� �����������
				ball.speedY = -ball.speedY;
				//�������� ����
				break;
			}
			//� ������ ����� �������
			else if (pointInRect(brickfield.arr[i][j].shape, midLeft) &&
				brickfield.arr[i][j].color != sf::Color::Black) {
				ball.score += getBrickScore(brickfield.arr[i][j]);
				//������ �����
				brickfield.arr[i][j].color = sf::Color::Black;
				brickfield.arr[i][j].shape.setFillColor(sf::Color::Black);
				//��� ������� �����������
				ball.speedX = -ball.speedX;
				//�������� ����
				break;
			}
			//� �����
			else if (pointInRect(brickfield.arr[i][j].shape, midRight) &&
				brickfield.arr[i][j].color != sf::Color::Black) {
				ball.score += getBrickScore(brickfield.arr[i][j]);
				//������ �����
				brickfield.arr[i][j].color = sf::Color::Black;
				brickfield.arr[i][j].shape.setFillColor(sf::Color::Black);
				//��� ������� �����������
				ball.speedX = -ball.speedX;
				//�������� ����
				break;
			}
			//� �������
			else if (pointInRect(brickfield.arr[i][j].shape, midBottom) &&
				brickfield.arr[i][j].color != sf::Color::Black) {
				ball.score += getBrickScore(brickfield.arr[i][j]);
				//������ �����
				brickfield.arr[i][j].color = sf::Color::Black;
				brickfield.arr[i][j].shape.setFillColor(sf::Color::Black);
				//��� ������� �����������
				ball.speedY = -ball.speedY;
				//�������� ����
				break;
			}
		}
	}
	
}

void ballCollideWithBat(Ball& ball, const Bat& bat) {
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	if (pointInRect(bat.shape, midBottom))
		ball.speedY = -ball.speedY;
}
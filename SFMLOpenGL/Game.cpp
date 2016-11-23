#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawPoints();
	drawLines();
	drawLineStrip();
	drawLineLoop();
	drawTriangles();
	drawTriagnleStrip();
	drawTriangleFan();
	drawQuads();
	drawQuadStrip();
	drawPolygon();
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::drawTriangles()
{
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.0, 0.4, -5.0);
		glVertex3f(-0.4, -0.4, -5.0);
		glVertex3f(0.4, -0.4, -5.0);
	}
	glEnd();
}

void Game::drawPoints()
{
	glPointSize(20);
	glBegin(GL_POINTS);
	{
		glVertex3f(0.6, 0.6, -5.0);
		glVertex3f(0.6, 1.0, -5.0);
	}
	glEnd();
}

void Game::drawLines()
{
	glBegin(GL_LINES);
	{
		glVertex3f(0.4, 0.4, -5.0);
		glVertex3f(0.4, -0.2, -5.0);
	}
	glEnd();
}

void Game::drawLineStrip()
{
	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(1.0, 1.0, -5.0);
		glVertex3f(2.0, 2.0, -5.0);
		glVertex3f(1.0, 2.0, -5.0);
		glVertex3f(2.0, 1.0, -5.0);
	}
	glEnd();
}

void Game::drawLineLoop()
{
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(-1.0, -2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(-2.0, -1.0, -5.0);
	}
	glEnd();
}

void Game::drawTriagnleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertex3f(1.0, -1.0, -5.0);
		glVertex3f(0.5, -0.5, -5.0);
		glVertex3f(1.0, -0.5, -5.0);
		glVertex3f(0.5, -1.0, -5.0);
		glVertex3f(0.6, -0.6, -5.0);
	}
	glEnd();
}

void Game::drawTriangleFan()
{
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(-1.0, 1.0, -5.0);
		glVertex3f(-0.5, 0.5, -5.0);
		glVertex3f(-1.0, 0.5, -5.0);
		glVertex3f(-0.5, 1.0, -5.0);
		glVertex3f(-0.6, 0.6, -5.0);
	}
	glEnd();
}

void Game::drawQuads()
{
	glBegin(GL_QUADS);
	{
		glVertex3f(-2.0, 2.0, -5.0);
		glVertex3f(-1.6, 1.6, -5.0);
		glVertex3f(-2.0, 1.6, -5.0);
		glVertex3f(-1.6, 2.0, -5.0);
		glVertex3f(-1.4, 1.4, -5.0);
		glVertex3f(-1.0, 1.0, -5.0);
		glVertex3f(-1.4, 1.0, -5.0);
		glVertex3f(-1.0, 1.4, -5.0);
	}
	glEnd();
}

void Game::drawQuadStrip()
{
	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(-2.0, 0.0, -5.0);
		glVertex3f(-2.0, 0.4, -5.0);
		glVertex3f(-1.5, 0.4, -5.0);
		glVertex3f(-2.4, 0.6, -5.0);
		glVertex3f(-1.2, 0.0, -5.0);
		glVertex3f(-1.2, 0.6, -5.0);
	}
	glEnd();
}

void Game::drawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(0.3, 2.0, -5.0);
		glVertex3f(1.0, 1.6, -5.0);
		glVertex3f(0.0, 1.8, -5.0);
		glVertex3f(1.0, 2.0, -5.0);
	}
	glEnd();
}
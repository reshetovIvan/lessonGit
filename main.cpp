#include <SFML/Graphics.hpp>
#include "Button.cpp"
#include <iostream>
#include "cstring"
using namespace std;
using namespace sf;

enum NumColor {
	BLACK=0,
	WHITE=255,
	GREEN
};

int main()
{	
	
	RenderWindow window(VideoMode(800, 600), "SFML Works!");
	Button button1(Color::Yellow, 20, 20, 200, 100, "but1");
	Button button2(Color::Red, 20, 140, 200, 100, "but2");
	window.clear(Color(250, 220, 100, 0));
	button1.draw(window);
	button2.draw(window);
	int a = 0;
	auto s = to_string(a);
	Text text;
	Font font;
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setString(s);
	text.setFillColor(Color::Black);
	text.setCharacterSize(20);
	text.setPosition(400, 400);

	while (window.isOpen())
	{		
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)
				window.close();
			if (event.key.code == Keyboard::Escape)
				window.close();
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (event.mouseButton.x >= 20 && event.mouseButton.x <= 220 && event.mouseButton.y >= 140 && event.mouseButton.y <= 240)
				{
					button2.visible(false);
					a++;
					s = to_string(a);
					text.setString(s);
				}

			}
				
				

		}
		window.clear(Color(250, 220, 100, 0));
		button1.draw(window);
		button2.draw(window);
		window.draw(text);
		window.display();
	}

	
}
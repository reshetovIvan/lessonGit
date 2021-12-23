#pragma once
class Button
{
	Text text;
	Font font;
	RectangleShape rectangle;
	Color color;

public:
	Button(Color color, int PositionX, int PositionY, int Width, int Hight, std::string str)
	{	
		this->color = color;
		RectangleShape rectangle2(Vector2f(Width, Hight));
		rectangle2.setFillColor(color);
		rectangle2.setPosition(PositionX, PositionY);
		this->rectangle = rectangle2;
		Text text;
		font.loadFromFile("arial.ttf");
		text.setFont(font);
		text.setString(str);
		text.setFillColor(Color::Black);
		text.setCharacterSize(20);
		text.setPosition(PositionX+10, PositionY + (Hight / 2) - 10);
		this->text = text;
		//createText(PositionX, PositionY, Hight, str);
	}
	void draw(RenderWindow &window)
	{
		window.draw(rectangle);
		window.draw(text);

	}
	void visible(bool flag)
	{
		if (flag){
			rectangle.setFillColor(color);			
		}
		else
		{
			rectangle.setFillColor(Color::Transparent);
		}
		
	}
//private:
//	void createText(int PositionX, int PositionY, int Hight, String str)
//	{
//		Text text;
//		font.loadFromFile("arial.ttf");
//		text.setFont(font);
//		text.setString(str);
//		text.setFillColor(Color::Black);
//		text.setCharacterSize(20);
//		text.setPosition(PositionX, PositionY+Hight/2);
//		this->text = text;
//	}
};


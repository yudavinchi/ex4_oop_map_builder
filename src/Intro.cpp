#include "Intro.h"

Intro::Intro()
	 :Window(MAX_WIDTH, MAX_HEIGHT, "Initializer")
{
	m_font.loadFromFile("arial.ttf");

	m_location_width_input   = sf::Vector2f(20, 20);
	m_location_height_input  = sf::Vector2f(250, 20);
	m_location_send_button   = sf::Vector2f(160, 100);
}

sf::Vector2i Intro::run()
{
	sf::RenderWindow intro_window(sf::VideoMode(this->get_width(), this->get_height()), this->get_name());

	std::string height, width;

	sf::Vector2i location_of_mouse;

	IntroButton send_button(m_location_send_button, 40, 120);
	send_button.set_text("SEND" , m_font);

	sf::Color white_color = sf::Color::White;		    // white
	sf::Color gray_color = sf::Color({160, 160, 160});  // Gray

	auto height_string = init_text(height, m_location_height_input);
	auto width_string  = init_text(width, m_location_width_input);

	auto height_box = init_input_box(SIZE, m_location_height_input);
	auto width_box  = init_input_box(SIZE, m_location_width_input);
	

	//main window
	while (intro_window.isOpen())
	{
		//clears
		intro_window.clear(); 

		//draws
		send_button.Draw(intro_window);
		intro_window.draw(height_box);
		intro_window.draw(width_box);
		intro_window.draw(height_string);
		intro_window.draw(width_string);

		//displays
		intro_window.display();

		//to handle events
		sf::Event event;

		location_of_mouse = sf::Mouse::getPosition(intro_window);

		// if the mouse above the rectangle it will change color, using "? :" method
		/*
		(height_box.getGlobalBounds().contains(location_of_mouse.x, location_of_mouse.y))
			? height_box.setFillColor(white_color) : height_box.setFillColor(gray_color);
		(width_box.getGlobalBounds().contains(location_of_mouse.x, location_of_mouse.y))
			? width_box.setFillColor(white_color) : width_box.setFillColor(gray_color);
		*/

		while (intro_window.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::Closed):
				intro_window.close();
				break;

			case(sf::Event::MouseButtonPressed):
				if (height_box.getGlobalBounds().contains(location_of_mouse.x, location_of_mouse.y))
				{
					height_box.setFillColor(white_color);

					if(width_box.getFillColor() == white_color)
						width_box.setFillColor(gray_color);
				}

				if(width_box.getGlobalBounds().contains(location_of_mouse.x, location_of_mouse.y))
				{
					width_box.setFillColor(white_color);

					if (height_box.getFillColor() == white_color)
						height_box.setFillColor(gray_color);
				}

				if (send_button.contain_click_button(location_of_mouse))
				{
					intro_window.close();
				}

				break;

			case(sf::Event::TextEntered):
				// write down numbers 
				if (event.text.unicode > 47 && event.text.unicode < 58)
				{
					if (height_box.getFillColor() == white_color)
					{
						std::cout << "ASCII character typed: " << (event.text.unicode) << std::endl;

						if (height.size() < MAX_LENGTH)
							height += (char)(event.text.unicode);

						height_string.setString(height);

						std::cout << height << std::endl;
					}

					if (width_box.getFillColor() == white_color)
					{
						std::cout << "ASCII character typed: " << (event.text.unicode) << std::endl;
						if (width.size() < MAX_LENGTH)
							width += (char)(event.text.unicode);

						width_string.setString(width);

						std::cout << width << std::endl;
					}
				}
				// erase = 8 in ASCII 
				else if (event.text.unicode == 8)
				{
					if (height_box.getFillColor() == white_color)
					{
						std::cout << "ASCII character typed: " << (event.text.unicode) << std::endl;

						if (height.size() > 0)
							height.pop_back();

						height_string.setString(height);

						std::cout << height << std::endl;
					}

					if (width_box.getFillColor() == white_color)
					{
						std::cout << "ASCII character typed: " << (event.text.unicode) << std::endl;

						if (width.size() > 0)
							width.pop_back();

						width_string.setString(width);

						std::cout << width << std::endl;
					}
				}
				break;
			}				
		}
	}

	sf::Vector2i values;

	values.x = convert_into_int(width);
	values.y = convert_into_int(height);

	return values;
}


sf::Text Intro::init_text(std::string &string, sf::Vector2f &location) const
{
	auto text = sf::Text(string, m_font);
	text.setCharacterSize(40);
	text.setPosition(location);
	text.setColor(sf::Color::Green);

	return text;
}

sf::RectangleShape Intro::init_input_box(sf::Vector2f size, sf::Vector2f &location) const
{
	sf::Color gray_color = sf::Color({ 160, 160, 160 }); // Gray

	auto box = sf::RectangleShape(size);
	box.setPosition(location);
	box.setFillColor(gray_color);

	return box;
}

int Intro::convert_into_int(std::string &string) const
{
	int num = 0;

	for (int i = 0; i < string.length(); i++)
	{
		num *= 10;
		num += string[i] - '0';
	}
	return num;
}


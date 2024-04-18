#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <Ship.hpp>

namespace pa {
	class Game {
	private:
		int m_width;
		int m_height;
		std::string m_capture;
		pa::Circle* m_c;
		int m_n;
		sf::RenderWindow m_window;
		sf::Texture m_TextureBackground;
		sf::Sprite m_SpriteBackground;

		Ship m_Ship;

	public:
		Game(int width, int height, const std::string& capture) {
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		bool Setup(int n) {
			m_n = n;
			//�������� ����
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);
			m_window.setTitle(m_capture);
			//��������
			if (!m_TextureBackground.loadFromFile("assets\\Background.jpeg")) {
				std::cout << "Error while loading background.jpeg";
				return false;
			}
			m_SpriteBackground.setTexture(m_TextureBackground);
			//�������� ������� ������
			if (!m_Ship.Setup(100, 100)) {
				return false;
			}
			m_c = new pa::Circle[m_n];
			srand(time(0));
			for (int i = 0; i < m_n; i++) {
				int r = rand() % 200 + 1;
				int x = rand() % (1100 - 2*r) + r;
				int y = rand() % (1000 - 2*r) + r;
				int dx = (rand() % 200);
				int dy = (rand() % 200);
				m_c[i].Setup(x, y, r, dx, dy);
			}
		}

		void TouchBorder(Circle& obj) 
		{
			float x = obj.X();
			float y = obj.Y();
			float dx1 = obj.dx();
			float dy1 = obj.dy();
			float r = obj.R();

			if (x + r >= m_width || x - r <= 0) {
				obj.dx(obj.dx());
			}
			if (y + r >= m_height || y - r <= 0) {
				obj.dy(obj.dy());
			}
		}


		void Life()
		{
			sf::Clock clock;
			while (m_window.isOpen())
			{
				//�������
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) {
						m_window.close();
					}
				}
				//��������� ����������
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					m_Ship.SetVelocity(0.001);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					m_Ship.SetVelocity(-0.001);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					m_Ship.Rotate(-0.1);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					m_Ship.Rotate(0.1);
				}

				//std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // ��������
				//������
				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();
				//����������� ������
				for (int i = 0; i < m_n; i++) {
					m_c[i].Move(dt);
				}
				for (int i = 0; i < m_n; i++) {
					TouchBorder(m_c[i]);
				}
				//����������� �������
				m_Ship.Move();
				//�����������
				m_window.clear();
				m_window.draw(m_SpriteBackground);
				m_window.draw(m_Ship.Get());
				for (int i = 0; i < m_n; i++) {
					m_window.draw(m_c[i].Get());
				}
				m_window.display();
			}
		}

		~Game()
		{
			delete[] m_c;
		}
	};
}
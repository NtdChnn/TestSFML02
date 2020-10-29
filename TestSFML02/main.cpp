#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "Animation.h"
using namespace sf;
using namespace std;
int main()
{
	//�Դ˹�ҵ�ҧ ��˹������пѧ��ѹ�˹�ҵ�ҧ
	RenderWindow window(VideoMode(1024, 512), "SFML Tutorial", Style::Close /*| Style::Titlebar*/ | Style::Resize);

	 //���ҧ�ٻ������������˹���Ҵ�����
	RectangleShape player(Vector2f(117.0f, 108.0f));
	//player.setFillColor(Color::Magenta);

	//��˹��ش��觡�ҧ�ͧ����Ф� ���� setposition ��١���˹�
	//player.setOrigin(Vector2f(200.0f, 25.0f));

	//��˹��ش�á�ͧ����Ф�
	player.setPosition(Vector2f(100.0f, 230.0f));

	//texture�ͧplayer 
	Texture playerTexture ; //��С�ȵ����texture
	playerTexture.loadFromFile("player01Run.png"); //��Ŵtexture�ҡ���
	player.setTexture(&playerTexture); //�Ըչ����texture�׹����

	//Animation
	Animation animation(&playerTexture, Vector2u(8, 1), 0.05f);
	
	float deltaTime = 0.0f;
	Clock clock;

/*	//textureẺ����ҹ
	Vector2u textureSize =  playerTexture.getSize();
	textureSize.x /= 4;
	textureSize.y /= 4;
	player.setTextureRect(IntRect(textureSize.x*0,textureSize.y*2,textureSize.x,textureSize.y)); */

	//�Ҵplayer�͡��


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		//Animation
		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);
		
		//������˹�ҵ�ҧ��ѧ�ҡ���player��Ѻ����
		window.clear();
		window.draw(player);
		window.display();

		Event evnt; //��С�ȵ���ê�Դ event
		while (window.pollEvent(evnt)) //move window around (?)
		{
			switch (evnt.type)
			{
			case Event::Closed: //close window
				window.close();
				break;
			/*case Event::Resized: //resize
				//�ʴ��Ť��������Ф������ҧ�ͧ����ѧ�ҡ�١ resize
				printf("New window height: %i New window width: %i \n", evnt.size.height, evnt.size.width);
				break;*/
			/*case Event::TextEntered: //�Ѻtext��ҹkeyboard
				if (evnt.text.unicode < 128) //������繵���ѡ�÷����ҵ�ͧ����������
				{
					printf("%c", evnt.text.unicode);
				}*/
			}


			//�Ѻinput�ҡ�������
		/*	if (Keyboard::isKeyPressed(Keyboard::Key::W))
			{
				player.move(0.0f, -1.0f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::A))
			{
				player.move(-1.0f, 0.0f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::S))
			{
				player.move(0.0f, 1.0f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::D))
			{
				player.move(1.0f, 0.0f);
			} */

			//�Ѻinput�ҡ�����
			/*if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousePos = Mouse::getPosition(window); //�Ѻ���˹觢ͧ�����
				player.setPosition((float)mousePos.x, ((float)mousePos.y)); //setpositionplayer == positionmouse
			}*/
		}
	}
	return 0;
}
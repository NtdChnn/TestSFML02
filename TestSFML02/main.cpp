#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "Animation.h"
using namespace sf;
using namespace std;
int main()
{
	//เปิดหน้าต่าง กำหนดไซส์และฟังก์ชันในหน้าต่าง
	RenderWindow window(VideoMode(1024, 512), "SFML Tutorial", Style::Close /*| Style::Titlebar*/ | Style::Resize);

	 //สร้างรูปสี่เหลี่ยมกำหนดขนาดและสี
	RectangleShape player(Vector2f(117.0f, 108.0f));
	//player.setFillColor(Color::Magenta);

	//กำหนดจุดกึ่งกลางของตัวละคร เพื่อ setposition ได้ถูกตำแหน่ง
	//player.setOrigin(Vector2f(200.0f, 25.0f));

	//กำหนดจุดแรกของตัวละคร
	player.setPosition(Vector2f(100.0f, 230.0f));

	//textureของplayer 
	Texture playerTexture ; //ประกาศตัวแปรtexture
	playerTexture.loadFromFile("player01Run.png"); //โหลดtextureจากไฟล์
	player.setTexture(&playerTexture); //วิธีนี้ได้textureยืนนิ่งๆ

	//Animation
	Animation animation(&playerTexture, Vector2u(8, 1), 0.05f);
	
	float deltaTime = 0.0f;
	Clock clock;

/*	//textureแบบประสาน
	Vector2u textureSize =  playerTexture.getSize();
	textureSize.x /= 4;
	textureSize.y /= 4;
	player.setTextureRect(IntRect(textureSize.x*0,textureSize.y*2,textureSize.x,textureSize.y)); */

	//วาดplayerออกมา


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		//Animation
		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);
		
		//เคลียร์หน้าต่างหลังจากที่playerขยับแล้ว
		window.clear();
		window.draw(player);
		window.display();

		Event evnt; //ประกาศตัวแปรชนิด event
		while (window.pollEvent(evnt)) //move window around (?)
		{
			switch (evnt.type)
			{
			case Event::Closed: //close window
				window.close();
				break;
			/*case Event::Resized: //resize
				//แสดงผลความยาวและความกว้างของจอหลังจากถูก resize
				printf("New window height: %i New window width: %i \n", evnt.size.height, evnt.size.width);
				break;*/
			/*case Event::TextEntered: //รับtextผ่านkeyboard
				if (evnt.text.unicode < 128) //เช็คว่าเป็นตัวอักษรที่เราต้องการหรือไม่
				{
					printf("%c", evnt.text.unicode);
				}*/
			}


			//รับinputจากคีย์บอร์ด
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

			//รับinputจากเมาส์
			/*if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousePos = Mouse::getPosition(window); //รับตำแหน่งของเมาส์
				player.setPosition((float)mousePos.x, ((float)mousePos.y)); //setpositionplayer == positionmouse
			}*/
		}
	}
	return 0;
}
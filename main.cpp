#include <iostream>
#include <string>
#include "Boton.cpp"
#include "Textbox.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Nodo.h"
#include "Grafo.h"

int main(){

	Grafo g;

	g.crearAristas(0, 1);
	g.crearAristas(0, 2);
	g.crearAristas(1, 3);//B
	g.crearAristas(1, 4);
	g.crearAristas(2, 1);
	g.crearAristas(2, 3);
	g.crearAristas(3, 4);
	g.crearAristas(3, 5);
	g.crearAristas(4, 5);
	g.crearAristas(4, 6);

	//g.mostarGrafo();

	int nodoActual = 0;
	int opt = 0;
	int cont = 0;

	Nodo *vertices[7];

	vertices[0] = new Nodo("Estas pelendo contra Sasuke", "Jutsu Clones de Sombras", "taijutsu", "img/pelea.png");//A
	vertices[1] = new Nodo("Estas venciendo", "Usar Rasengans", "Activar el Seis Caminos", "img/clones.png");//B
	vertices[2] = new Nodo("Estas perdiendo", "Usar Jutsu Clones de Sombras", "Activar el Seis Caminos", "img/perdiendo.png");//C
	vertices[3] = new Nodo("Empezo a utilizar el Rinnegan", "Recibir Daño", "Modo Kurama", "img/rinnegan.png");//D
	vertices[4] = new Nodo("Te esta atacando", "Modo Kurama", "Morir", "img/teataca.png");//E
	vertices[5] = new Nodo("Choque de punos", "        ⸝͟ၜ", "Repetir", "img/choque.png");//F
	vertices[6] = new Nodo("Perdiste la batalla", "    ⸝͟ၜ", "Repetir", "img/morir.jpeg");

///////////////////////////////////////////////////////////////////////////////////////////////////

	
	sf::RenderWindow window(sf::VideoMode(1340, 710), "SMFL");
	window.setFramerateLimit(60);

	window.setVerticalSyncEnabled(true);

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("music/2.ogg"))
	{
		return EXIT_FAILURE;
	}

	sf::Sound sonido;
	sonido.setBuffer(buffer);
	sonido.setVolume(80);

	sf::Music musica;
	musica.openFromFile("music/2.ogg");
	musica.setLoop(true);

	musica.play();

	while (window.isOpen())
    {
		sf::Event event;


	sf::Font font;

	/*window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(true);*/

	Textbox textbox1 = Textbox(15, sf::Color::Red, true);
	textbox1.setFont(font);
	textbox1.setPosition({ 525, 50 });
	textbox1.setText(vertices[nodoActual]->premisa);

	/*sf::Sprite test;
	sf::Texture t2;
	t2.loadFromFile("img/naruto.jpeg");
	test.setTexture(t2);
	test.setPosition(300,400);*/


	font.loadFromFile("font/njnaruto.ttf");

	Button btn1(vertices[nodoActual]->resp1, { 375, 50 }, 20, sf::Color::Black, sf::Color::Red);
	btn1.setPosition({ 450, 480 });
	btn1.setFont(font);
	


	Button btn2(vertices[nodoActual]->resp2, { 200, 50 }, 20, sf::Color::Black, sf::Color::Red);
	btn2.setPosition({ 540, 550 });
	btn2.setFont(font);

        while (window.pollEvent(event) && nodoActual !=7)
        {
            switch(event.type){

				case sf::Event::Closed: window.close(); break;

				case sf::Event::MouseButtonPressed:
					if(btn1.isMouserOver(window)){
						opt = 1;
						nodoActual = g.getOption(nodoActual, opt);
						
						if(nodoActual == 7){
							btn1.setBackColor(sf::Color::Black);
						}
						
					}

					else if(btn2.isMouserOver(window)){
						opt = 2;
						nodoActual = g.getOption(nodoActual, opt);
					}
					else{
						textbox1.setText(vertices[nodoActual]->premisa);
					}


				
			}
			textbox1.setText(vertices[nodoActual]->premisa);

        }

        window.clear();
		btn1.drawTo(window);
		btn2.drawTo(window);
		textbox1.drawTo(window);
		//window.draw(test);
		window.draw(vertices[nodoActual]->getSprite());
        window.display();
		
    }

	/*while(true){

		if(nodoActual != 3){

			std::cout << vertices[nodoActual]->premisa << std::endl;
			std::cout << vertices[nodoActual]->resp1 << std::endl;
			std::cout << vertices[nodoActual]->resp2 << std::endl;

			//std::cin >> opt;

			nodoActual = g.getOption(nodoActual, opt);

		}else{
			std::cout << vertices[nodoActual]->premisa << std::endl;
			break;
		}
	}*/

	

	

	return 0;
}
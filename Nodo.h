#ifndef GRAFO_H
#define GRAFO_H

#include <SFML/Graphics.hpp>
#include <string>

class Nodo{

	public:

	std::string premisa;
	std::string resp1;
	std::string resp2;
	sf::Sprite sprite;
	sf::Texture texture;

	Nodo(std::string pPre, std::string r1, std::string r2, std::string img){
		
		premisa = pPre;
		resp1 = r1;
		resp2 = r2;

		
		texture.loadFromFile(img);
		sprite.setTexture(texture);
		sprite.setPosition(395,100);
		sprite.setScale(600.f / sprite.getTexture()->getSize().x, 350.f / sprite.getTexture()->getSize().y);

	}

	sf::Sprite getSprite(){
		
		return sprite;
	}

};

#endif
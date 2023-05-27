#include <SFML/Graphics.hpp>
#include <string>

std::string map[30] = {
  "AAAAAAAAAAAAAAAAAAAAAAAAAA",
  "AAAAAAAAAAAAAAAAAAAAAAAAAA",
  "AAAA                   AAA",
  "AAAA  BBBBBBBBBBBBBBBBBBBB",
  "AAAA  BBB              AAA",
  "AAAA  BBB              AAA",
  "AAAA  BBB   AA         AAA",
  "AAAA        AA         AAA",
  "AAAA        AA         AAA",
  "AAAAAABBBAAAAA         AAA",
  "AAAAAABBBAAAAA         AAA",
  "AAAAAABBBAAAAAAAAAAAAAAAAA",
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(1300, 600), "SFML");

    sf::Texture t;
    t.loadFromFile("texture/surface.jpg");
    sf::Sprite textures(t);
    
    sf::Texture pers;
    pers.loadFromFile("texture/golden_boy.png");
    sf::Sprite boy(pers);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (map[i][j] == 'A')
                    textures.setTextureRect(sf::IntRect(275, 0, 325, 50));
                if (map[i][j] == 'B')
                    textures.setTextureRect(sf::IntRect(395, 145, 445, 195));
                if (map[i][j] == ' ')
                    textures.setTextureRect(sf::IntRect(400, 0, 450, 50));
                textures.setPosition(j * 50, i * 50);
                window.draw(textures);
            }
        }
        boy.setPosition(850,250);
        window.draw(boy);
        window.display();
    }
    return 0;
}
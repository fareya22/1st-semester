#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Edge : public sf::VertexArray {
public:
Edge(sf::Vector2f startPoint, sf::Vector2f endPoint) {
this->resize(2);
(*this)[0].position = startPoint;
(*this)[1].position = endPoint;
}
};

int main() {
// example usage
Edge* edge = new Edge(sf::Vector2f(10, 10), sf::Vector2f(100, 100));
return 0;
}

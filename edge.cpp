#include <iostream>
#include <vector>
#include <memory>
#include <QLine>

using namespace std;

class GraphicNode;

class Edge : public QLine {
public:
Edge(GraphicNode* startNode, GraphicNode* endNode) {
setLine(startNode->x(), startNode->y(), endNode->x(), endNode->y());
}
};

class GraphicNode {
private:
int nodeNumber;
QString statement;
double xCoord;
double yCoord;
std::vector<std::shared_ptr<Edge>> parents;
std::vector<std::shared_ptr<Edge>> childs;

public:
GraphicNode(int nodeNo, QString nodeStatement, double x, double y)
: nodeNumber(nodeNo), statement(nodeStatement), xCoord(x), yCoord(y) {}
int getNodeNumber() const { return nodeNumber; }
QString getStatement() const { return statement; }
double x() const { return xCoord; }
double y() const { return yCoord; }

void addParent(std::shared_ptr<Edge> parent) { parents.push_back(parent); }
void addChild(std::shared_ptr<Edge> child) { childs.push_back(child); }
};

int main() {
// example usage
std::shared_ptr<GraphicNode> node1 = std::make_shared<GraphicNode>(1, "if (x > y) {", 100, 100);
std::shared_ptr<GraphicNode> node2 = std::make_shared<GraphicNode>(2, "y = x;", 200, 100);
std::shared_ptr<Edge> edge1 = std::make_shared<Edge>(node1.get(), node2.get());
node1->addChild(edge1);
node2->addParent(edge1);
return 0;}

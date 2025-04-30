#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>

using namespace std;

class GraphicNode : public QGraphicsTextItem {
public:
    GraphicNode(int x, int y, string text, string id) {
        setPlainText(QString::fromStdString(text));
        setDefaultTextColor(Qt::white);
        setFont(QFont("times", 16));
        setPos(x, y);
        setFlag(QGraphicsItem::ItemIsMovable);
        setFlag(QGraphicsItem::ItemIsSelectable);
        setToolTip(QString::fromStdString(id));
    }
};

class Edge : public QGraphicsLineItem {
public:
    Edge(GraphicNode* startNode, GraphicNode* endNode) {
        setLine(startNode->x(), startNode->y(), endNode->x(), endNode->y());
        setPen(QPen(Qt::cyan, 5));
    }
};

void initGraph(QGraphicsScene* scene) {
    ifstream nodesFile("F:\\Downloads\\CFG-master\\LeveledNodes.txt");
    ifstream edgesFile("F:\\Downloads\\CFG-master\\Edges.txt");
    ifstream textFile("F:\\Downloads\\CFG-master\\test.txt");
    vector<string> lines;
    unordered_map<int, GraphicNode*> map;
    int numberOfNodes = 0;
    int numberofNodesInLevel[50] = {};

    if (!textFile.is_open() || !nodesFile.is_open() || !edgesFile.is_open()) {
        cerr << "Failed to open one of the files." << endl;
        exit(1);
    }

    string line;
    while (getline(textFile, line)) {
        lines.push_back(line);
    }

    nodesFile >> numberOfNodes;

    while (!nodesFile.eof()) {
        int nodeNumber;
        int levelOfCurNode;
        nodesFile >> nodeNumber >> levelOfCurNode;

        if (levelOfCurNode >= 100000000) {
            continue;
        }

        int thisLevelAlreadyHasNodes = numberofNodesInLevel[levelOfCurNode];
        numberofNodesInLevel[levelOfCurNode]++;
        int adjustor = thisLevelAlreadyHasNodes;

        GraphicNode* curNode = new GraphicNode(150 * (adjustor + 1), levelOfCurNode * 70, lines[nodeNumber], to_string(nodeNumber));
        map[nodeNumber] = curNode;
        scene->addItem(curNode);
    }

    while (!edgesFile.eof()) {
        int source, dest;
        edgesFile >> source >> dest;
        Edge* connection = new Edge(map[source], map[dest]);
        scene->addItem(connection);
    }

    textFile.close();
    nodesFile.close();
    edgesFile.close();
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QGraphicsScene scene;
    initGraph(&scene);
    QGraphicsView view(&scene);
    view.show();
    return app.exec();
}

#include <iostream>
#include <vector>

using namespace std;

class SyntaxIdentifier {
public:
    bool isExpression(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        return (statement[0] != '/' && statement[1] != '/' && statement[statement.length() - 1] == ';');
    }

    bool isIf(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        if (statement.length() >= 3) {
            if (statement[0] == 'i' && statement[1] == 'f' && statement[2] == '(') {
                return true;
            }
        }
        return false;
    }

    bool isElseIf(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        if (statement.length() >= 7) {
            if (statement[0] == 'e' && statement[1] == 'l' && statement[2] == 's'
                && statement[3] == 'e' && statement[4] == 'i' && statement[5] == 'f' && statement[6] == '(') {
                return true;
            }
        }
        return false;
    }

    bool isElse(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        if (statement.length() >= 4) {
            if (statement[0] == 'e' && statement[1] == 'l' && statement[2] == 's' && statement[3] == 'e') {
                return true;
            }
        }
        return false;
    }

    bool isWhile(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        if (statement.length() >= 6) {
            if (statement[0] == 'w' && statement[1] == 'h' && statement[2] == 'i'
                && statement[3] == 'l' && statement[4] == 'e' && statement[5] == '(') {
                return true;
            }
        }
        return false;
    }

    bool isFor(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        if (statement.length() >= 4) {
            if (statement[0] == 'f' && statement[1] == 'o' && statement[2] == 'r' && statement[3] == '(') {
                return true;
            }
        }
        return false;
    }

    bool isLoop(string statement) {                      //"for(" nowt working, so instead using for
        statement = regex_replace(statement, regex("\\s"), "");
        if (isFor(statement) || isWhile(statement)) {
            return true;
        }
        return false;
    }

    bool foundEnd(string statement) {
        statement = regex_replace(statement, regex("\\s"), "");
        return statement[statement.length() - 1] == '}';
    }
};

class Node {
public:
    int nodeNumber;
    string Statement;
    vector<Node*> parents;
    vector<Node*> childs;

    Node(int nodeNo, string nodeStatement) {
        this->nodeNumber = nodeNo;
        this->Statement = nodeStatement;
    }

    void setParent(Node* pr) {
        this->parents.push_back(pr);
    }

    void setChild(Node* pr) {
        this->childs.push_back(pr);
    }
};

int main() {
// example usage
SyntaxIdentifier si;
Node* node1 = new Node(1, "if (x > y) {");
Node* node2 = new Node(2, "x = x + 1;");
Node* node3 = new Node(3, "}");
Node* node4 = new Node(4, "if (x < y) {");
Node* node5 = new Node(5, "y = y + 1;");
Node* node6 = new Node(6, "}");
node1->setChild(node2);
node1->setChild(node3);
node2->setParent(node1);
node3->setParent(node1);

node3->setChild(node4);
node4->setParent(node3);

node4->setChild(node5);
node4->setChild(node6);
node5->setParent(node4);
node6->setParent(node4);

return 0;
}

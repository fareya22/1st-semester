#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int line;
    string keyword;
    vector<int> children;
};

vector<Node> graph;
vector<string> tokens;

void parseTokens(const string& tokensFile) {
    ifstream inputFile(tokensFile);
    string token;
    while (inputFile >> token) {
        tokens.push_back(token);
    }
    inputFile.close();
}

void addEdge(int parent, int child) {
    graph[parent].children.push_back(child);
}

int findMatchingClosingBrace(int startLine) {
    stack<string> st;
    for (int i = startLine; i < tokens.size(); i++) {
        if (tokens[i] == "{") {
            st.push("{");
        } else if (tokens[i] == "}") {
            st.pop();
            if (st.empty()) {
                return i;
            }
        }
    }
    return -1;
}

void buildCFG(int startLine, int endLine, int parent) {
    int i = startLine;
    while (i <= endLine) {
        string keyword = tokens[i];
        Node node;
        node.line = i + 1;
        node.keyword = keyword;
        graph.push_back(node);
        addEdge(parent, graph.size() - 1);

        if (keyword == "if" || keyword == "else if") {
            int closingBrace = findMatchingClosingBrace(i + 1);
            buildCFG(i + 2, closingBrace - 1, graph.size() - 1);
            i = closingBrace;
        } else if (keyword == "else") {
            int nextKeywordLine = i + 1;
            string nextKeyword = tokens[nextKeywordLine];
            if (nextKeyword == "if") {
                int closingBrace = findMatchingClosingBrace(nextKeywordLine + 1);
                buildCFG(nextKeywordLine + 2, closingBrace - 1, graph.size() - 1);
                i = closingBrace;
            } else {
                int closingBrace = findMatchingClosingBrace(i + 1);
                buildCFG(i + 2, closingBrace - 1, graph.size() - 1);
                i = closingBrace;
            }
        } else if (keyword == "for" || keyword == "while") {
            int closingBrace = findMatchingClosingBrace(i + 1);
            buildCFG(i + 2, closingBrace - 1, graph.size() - 1);
            i = closingBrace;
        }

        i++;
    }
}

void printGraph() {
    cout << "Control Flow Graph:\n";
    for (const auto& node : graph) {
        cout << "Node " << node.line << " (" << node.keyword << ") -> ";
        for (int child : node.children) {
            cout << graph[child].line << " ";
        }
        cout << endl;
    }
}

int main() {
    string tokensFile = "TokenFile.txt";
    parseTokens(tokensFile);

    graph.clear();
    bool mainFound = false;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "int" && tokens[i + 1] == "main" && tokens[i + 2] == "(" && tokens[i + 3] == ")") {
            buildCFG(i + 4, tokens.size() - 1, -1);
            mainFound = true;
            break;
        }
    }

    if (mainFound) {
        printGraph();
    } else {
        cout << "Main function not found." << endl;
    }

    return 0;
}


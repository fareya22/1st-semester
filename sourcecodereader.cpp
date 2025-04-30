
#include <iostream>
#include <fstream>
#include <vector>
#include "MakeGraph.hpp"

using namespace std;

int main() {
    cout << "Control Flow Graph\n\n";
    cout << "Enter the path of a C source code file\n";
    string fileName;
    cin >> fileName;
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 0;
    }
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    MakeGraph graph(lines);
    graph.start();
    // graph.printGraph();
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define a struct to represent a DFA transition.
struct Transition {
    int state;
    char symbol;
};

// Define a function to read a DFA table from standard input.
unordered_map<int, vector<Transition>> read_dfa_table() {
    int num_states, num_symbols;
    cin >> num_states >> num_symbols;

    unordered_map<int, vector<Transition>> dfa_table;
    for (int i = 0; i < num_states; ++i) {
        dfa_table[i] = vector<Transition>(num_symbols);
        for (int j = 0; j < num_symbols; ++j) {
            cin >> dfa_table[i][j].state;
            cin >> dfa_table[i][j].symbol;
        }
    }

    return dfa_table;
}

// Define a main function to test the read_dfa_table function.
int main() {
    unordered_map<int, vector<Transition>> dfa_table = read_dfa_table();

    // Print the DFA table to standard output for testing purposes.
    for (auto& kv : dfa_table) {
        int state = kv.first;
        vector<Transition>& transitions = kv.second;
        cout << state << ": ";
        for (const auto& transition : transitions) {
            cout << "(" << transition.symbol << ", " << transition.state << ") ";
        }
        cout << endl;
    }

    return 0;
}


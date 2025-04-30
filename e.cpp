#include <bits/stdc++.h>
using namespace std;

struct State {
    string name;
    set<string> epsilons;
    map<char, set<string>> transitions;
};

int main() {
    int num_states, num_symbols;
    cin >> num_states >> num_symbols;

    // Create an array of State structures to represent each state
    State states[num_states];

    // Read in the names of each state and populate the State structure
    for (int i = 0; i < num_states; i++) {
        string state_name;
        cin >> state_name;
        states[i].name = state_name;
    }

    // Read in the transition matrix and populate the State structures
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_symbols; j++) {
            for (int k = 0; k < num_states; k++) {
                char transition;
                cin >> transition;

                if (transition == '0') {
                    continue;
                }

                string state_name = states[k].name;

                if (transition == 'e') {
                    states[i].epsilons.insert(state_name);
                } else {
                    states[i].transitions[transition].insert(state_name);
                }
            }
        }
    }

    // Print out the epsilon transitions
    cout << "Epsilon Transitions:" << endl;
    for (int i = 0; i < num_states; i++) {
        cout << states[i].name << " -> {";
        for (const string& state : states[i].epsilons) {
            cout << state << ",";
        }
        cout << "}" << endl;
    }

    // Convert the epsilon-NFA to a DFA
    // Start with the initial state and epsilon closure
    set<string> dfa_states;
    dfa_states.insert(states[0].name);
    for (const string& epsilon : states[0].epsilons) {
        dfa_states.insert(epsilon);
    }

    // Create a vector of sets to hold the transition table
    vector<set<string>> transition_table;
    transition_table.push_back(dfa_states);

    // Continue building the DFA by adding new states
    int state_index = 0;
    while (state_index < transition_table.size()) {
        // Iterate over each symbol in the alphabet
        for (char symbol = 'a'; symbol < 'a' + num_symbols - 1; symbol++) {
            // Find the set of states that this state transitions to on this symbol
            set<string> transition_states;
            for (const string& state : transition_table[state_index]) {
                auto& transitions = states[getIndex(states, state)].transitions[symbol];
                transition_states.insert(transitions.begin(), transitions.end());
            }

            // Take the epsilon closure of the transition states
            set<string> epsilon_closure;
            for (const string& state : transition_states) {
                epsilon_closure.insert(state);
                for (const string& epsilon : states[getIndex(states, state)].epsilons) {
                    epsilon_closure.insert(epsilon);
                }
            }

            // If the new set of states is not already in the transition table, add it
            if (epsilon_closure.size() > 0 && !contains(transition_table, epsilon_closure)) {
                transition_table.push_back(epsilon_closure);
            }
        }

        // Move on to the next state in the transition table
        state_index++;
    }

    // Print out the DFA transition table
    cout << "DFA Transition Table:" << endl;
    for (int i =0

#include <bits/stdc++.h>
using namespace std;

struct State {
    string nam;
    set<string> epsilons;
    map<char, set<string>> transitions;
};

int getIndex(State* states, int num_states, string name) {
    for (int i = 0; i < num_states; i++) {
        if (states[i].nam == name) {
            return i;
        }
    }
    return -1;
}

bool contains(vector<set<string>>& transition_table, set<string>& states) {
    for (const set<string>& s : transition_table) {
        if (s == states) {
            return true;
        }
    }
    return false;
}

int main() {
    int num_states, num_symbols;
    cin >> num_states >> num_symbols;

    // Create an array of State structures to represent each state
    State states[num_states];

    // Read in the names of each state and populate the State structure
    for (int i = 0; i < num_states; i++) {
        string state_name;
        cin >> state_name;
        states[i].nam = state_name;
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

                string state_name = states[k].nam;

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
        cout << states[i].nam << " -> {";
        for (const string& state : states[i].epsilons) {
            cout << state << ",";
        }
        cout << "}" << endl;
    }

    // Convert the epsilon-NFA to a DFA
    // Start with the initial state and epsilon closure
    set<string> dfa_states;
    dfa_states.insert(states[0].nam);
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
        for (char symbol = 'a'; symbol < 'a' + num_symbols; symbol++) {
            // Find the set of states that this state transitions to on this symbol
            set<string> transition_states;
            for (const string& state : transition_table[state_index]) {
                auto& transitions = states[getIndex(states, num_states, state)].transitions[symbol];
                transition_states.insert(transitions.begin(), transitions.end());
            }

            // Find the epsilon closure of the set of transition states
            set<string> epsilon_closure;
            for (const string& state : transition_states) {
                epsilon_closure.insert(state);
                for (const string& epsilon : states[getIndex(states, num_states, state)].epsilons) {
                    epsilon_closure.insert(epsilon);
                }
                        }

        // Check if the epsilon closure is already in the transition table
        if (!contains(transition_table, epsilon_closure)) {
            // Add the epsilon closure to the transition table
            transition_table.push_back(epsilon_closure);
        }

        // Add the transition to the DFA
        int transition_index = getIndex(transition_table.data(), transition_table.size(), transition_table[state_index]);
        states[state_index].transitions[symbol] = transition_table[transition_index];

        // If the state we just transitioned to has not been processed yet, add it to the queue
        if (transition_index == -1) {
            dfa_states = transition_table.back();
            queue.push_back(dfa_states);
        }
    }

    // Move on to the next state in the queue
    state_index++;
}

// Print out the DFA transition table
cout << "DFA Transition Table:" << endl;
cout << "     ";
for (char symbol = 'a'; symbol < 'a' + num_symbols; symbol++) {
    cout << " " << symbol << "  ";
}
cout << endl;
for (int i = 0; i < transition_table.size(); i++) {
    cout << "{";
    for (const string& state : transition_table[i]) {
        cout << state << ",";
    }
    cout << "} ";
    for (char symbol = 'a'; symbol < 'a' + num_symbols; symbol++) {
        auto& transitions = states[getIndex(states, num_states, transition_table[i])].transitions[symbol];
        cout << "{";
        for (const string& state : transitions) {
            cout << state << ",";
        }
        cout << "} ";
    }
    cout << endl;
}

return 0;


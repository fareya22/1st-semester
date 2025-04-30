#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Define a struct to represent a pair of states.
struct StatePair {
    int state1;
    int state2;
};

// Define a function to determine if two states are equivalent.
bool are_states_equivalent(int state1, int state2,
                           const unordered_map<int, vector<int>>& partition) {
    for (const auto& kv : partition) {
        const vector<int>& group = kv.second;
        if ((find(group.begin(), group.end(), state1) != group.end() &&
             find(group.begin(), group.end(), state2) == group.end()) ||
            (find(group.begin(), group.end(), state1) == group.end() &&
             find(group.begin(), group.end(), state2) != group.end())) {
            return false;
        }
    }
    return true;
}

// Define a function to perform the table filling algorithm.
void table_filling_algorithm(const unordered_map<int, vector<Transition>>& dfa_table,
                              vector<unordered_set<int>>& groups) {
    // Initialize the partition with two groups: accepting states and non-accepting states.
    unordered_map<int, vector<int>> partition;
    unordered_set<int> accepting_states;
    unordered_set<int> non_accepting_states;
    for (const auto& kv : dfa_table) {
        int state = kv.first;
        bool is_accepting = false;
        for (const auto& transition : kv.second) {
            if (transition.symbol == '1') {
                is_accepting = true;
                break;
            }
        }
        if (is_accepting) {
            accepting_states.insert(state);
        } else {
            non_accepting_states.insert(state);
        }
    }
    partition[0] = vector<int>(accepting_states.begin(), accepting_states.end());
    partition[1] = vector<int>(non_accepting_states.begin(), non_accepting_states.end());

    // Initialize the table with all pairs of states.
    vector<StatePair> state_pairs;
    for (const auto& kv1 : dfa_table) {
        int state1 = kv1.first;
        for (const auto& kv2 : dfa_table) {
            int state2 = kv2.first;
            if (state1 < state2) {
                state_pairs.push_back(StatePair{state1, state2});
            }
        }
    }

    // Iterate over the table until it is no longer being refined.
    bool is_table_refined = true;
    while (is_table_refined) {
        is_table_refined = false;
        for (const auto& state_pair : state_pairs) {
            int state1 = state_pair.state1;
            int state2 = state_pair.state2;
            if (are_states_equivalent(state1, state2, partition)) {
                char symbol = dfa_table.at(state1)[0].symbol; // DFA is assumed to be total.
                int next_state1 = dfa_table.at(state1)[0].state;
                int next_state2 = dfa_table.at(state2)[0].state;
                if (partition.count(next_state1) != 0 &&
                    partition.count(next_state2) != 0 &&
                    partition.at(next_state1) != partition.at(next_state2)) {
                    // The two states are not equivalent.
                    int group1 = partition.at(next_state1)[0];
                    int group2 = partition.at(next_state2)[0];
                    groups[group1].insert(state1);
                    groups[group2].insert(state2);
                                 // Refine the partition and table.
                partition.at(next_state2) = partition.at(next_state1);
                is_table_refined = true;
            }
        }
    }
}

// Print out the groups of equivalent states.
cout << "Equivalent state groups:" << endl;
for (const auto& kv : partition) {
    const vector<int>& group = kv.second;
    if (group.size() > 1) {
        cout << "  ";
        for (int state : group) {
            cout << state << " ";
        }
        cout << endl;
    }
}
}

// Define a struct to represent a transition in a DFA.
struct Transition {
char symbol;
int state;
};

// Define a function to read in a DFA table from standard input.
unordered_map<int, vector<Transition>> read_dfa_table() {
int num_states, num_symbols;
cin >> num_states >> num_symbols;
unordered_map<int, vector<Transition>> dfa_table;
for (int i = 0; i < num_states; ++i) {
int state;
cin >> state;
vector<Transition> transitions;
for (int j = 0; j < num_symbols; ++j) {
char symbol;
int next_state;
cin >> symbol >> next_state;
transitions.push_back(Transition{symbol, next_state});
}
dfa_table[state] = transitions;
}
return dfa_table;
}

// Define the main function to read in a DFA table and run the table filling algorithm.
int main() {
unordered_map<int, vector<Transition>> dfa_table = read_dfa_table();
int num_states = dfa_table.size();
vector<unordered_set<int>> groups(num_states);
table_filling_algorithm(dfa_table, groups);
return 0;
}


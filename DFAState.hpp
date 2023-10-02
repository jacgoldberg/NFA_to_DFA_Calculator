#include <string>
#include <vector>

#ifndef DFAState_H
#define DFAState_H

using namespace std;

class DFAState{
    public:
        string stateName;
        vector<string> alphabet;
        string* transitions;
        int alphabetSize;
        bool startState;
        bool finalState;

//Default Constructor
        DFAState();
//Overloaded Constructor (Should be primarily used)
        DFAState(string startState);
//Add the transitions to the state
        void AddTrasition(string state, string input);
        string returnStateName();
        void loadAlphabet(vector<string> initialAlphabet);
        void setInitialState(bool input);
        void setFinalState(bool input);
        string printTransitionSetAt(int t);
        string stateTransitionsAt(int i);
        void cleanup();

};
#endif
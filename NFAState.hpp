// NFAState.hpp
#include <string>
#include <vector>

#ifndef NFAState_H
#define NFAState_H

using namespace std;

class NFAState{
    public:

        string stateName;
        vector<string> alphabet;
        vector<string>* transitions;
        bool startState;
        bool finalState;


        NFAState();
        NFAState(string startState);
        void AddTrasition(string state, string input);
        string returnStateName();
        void loadAlphabet(vector<string> initialAlphabet);
        void setInitialState(bool input);
        void setFinalState(bool input);
        vector<string> stateTransitionsAt(int i);
        bool isInitial();
        };
#endif
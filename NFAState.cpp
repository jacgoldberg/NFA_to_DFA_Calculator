#include "NFAState.hpp"

//Default Constructor
    NFAState::NFAState(){

    }

//Overloaded Constructor (Should be primarily used)
    NFAState::NFAState(string temp){
        stateName = temp;
        bool startState = false;
        bool finalState = false;
    }

//Add the transitions to the state
    void NFAState::AddTrasition(string state, string input){
        for(int i = 0; i < alphabet.size(); i++){
            if(alphabet.at(i) == input){
                transitions[i].push_back(state);
            }
        }
    }
string NFAState::returnStateName(){
        return stateName;
    }
void NFAState::loadAlphabet(vector<string> initialAlphabet){
        int temp = initialAlphabet.size();
        transitions = new vector<string>[temp];
        for(int i = 0; i < temp; i++){
            alphabet.push_back(initialAlphabet.at(i));
        }
    }
void NFAState::setInitialState(bool input){
        if(!input){
            startState = false;
        }else{
            startState = true;
        }
    }
void NFAState::setFinalState(bool input){
        if(!input){
            startState = false;
        }else{
            startState = true;
        }
    }
vector<string> NFAState::stateTransitionsAt(int i){
        return transitions[i];
    }
bool NFAState::isInitial(){
        return startState;
    }
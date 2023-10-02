#include "DFAState.hpp"


//Default Constructor
        DFAState::DFAState(){

        }

//Overloaded Constructor (Should be primarily used)
        DFAState::DFAState(string temp){
            stateName = temp;
            startState = false;
            finalState = false;
        }

//Add the transitions to the state
        void DFAState::AddTrasition(string state, string input){
            for(int i = 0; i < alphabet.size(); i++){
                if(alphabet.at(i) == input){
                    transitions[i] = state;
                }
            }
            
        }
        string DFAState::returnStateName(){
            return stateName;
        }
        void DFAState::loadAlphabet(vector<string> initialAlphabet){
            alphabetSize = initialAlphabet.size();
            for(int i = 0; i < alphabetSize; i++){
                alphabet.push_back(initialAlphabet.at(i));
            }
            transitions = new string[alphabetSize];
            for(int i = 0; i < alphabetSize; i++){
                transitions[i] = "n/a";
            }
        }
        void DFAState::setInitialState(bool input){
            if(!input){
                startState = false;
            }else{
                startState = true;
            }
        }
        void DFAState::setFinalState(bool input){
            if(!input){
                startState = false;
            }else{
                startState = true;
            }
        }
        string DFAState::printTransitionSetAt(int t){
            if(transitions[t] == "n/a"){
                return "";
            }
                return stateName + "," + alphabet.at(t) + " = " + transitions[t] + "\n";
        }
        string DFAState::stateTransitionsAt(int i){
            return transitions[i];
        }
        void DFAState::cleanup(){
            delete transitions;
        }
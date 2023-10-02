#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include "NFAState.hpp"
#include "DFAState.hpp"

using namespace std;


int main() {

    cout << "Please enter file name: ";
    string response;
    cin >> response;
    string line;
    ifstream myfile (response);
    vector<NFAState> stateList;
    vector<string> alphabetList;
    string startState;
    string finalState;
    vector<string> acceptenceList;
    string currentState;
    string currentTransition;
    string transitionDefinition;

    if (myfile.is_open())
    {
        cout << "Able to open file";

//Start Line 1 Logic
        getline (myfile,line);
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        char* ptr = strtok(cstr," ");
        vector<char*> v;

        while(ptr!=nullptr){
            v.push_back(ptr);
            ptr = strtok(nullptr," ");
        }
        for (int i = 0; i < v.size(); i++){
            NFAState temp(v.at(i));
            stateList.push_back(temp);
        }
        delete [] cstr;
//End Line 1 Logic
//Start Line 2 Logic
        getline (myfile,line);
        cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        ptr = strtok(cstr," ");
        v.clear();
        while(ptr!=nullptr){
            v.push_back(ptr);
            ptr = strtok(nullptr," ");
        }
        for (int i = 0; i < v.size(); i++){
                alphabetList.push_back(v.at(i));
        }
        for(int i = 0; i < stateList.size(); i++){
             stateList.at(i).loadAlphabet(alphabetList);
        }

//End Line 2 Logic
//Start Line 3 Logic
        getline (myfile,line);
        startState = line;
        for(int i = 0; i < stateList.size(); i++){
            if(stateList.at(i).returnStateName() == startState){
                stateList.at(i).setInitialState(true);
            }
        }
//End Line 3 Logic
//Start Line 4 Logic
        getline (myfile,line);
        cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        ptr = strtok(cstr," ");
        v.clear();

        while(ptr!=nullptr){
            v.push_back(ptr);
            ptr = strtok(nullptr," ");
        }
        for (int i = 0; i < v.size(); i++){
                acceptenceList.push_back(v.at(i));
        }
//End Line 4 Logic
//Start rest of file logic
        getline (myfile,line);
        while ( getline (myfile,line) && line != "END")
        {
            int i = 0;
            int end = 0;
            string tempString;
            while(line.at(i)!= ','){
                string s(1, line.at(i));
                tempString.append(s);
                i++;
                end = i;
            }
            currentState = tempString;
            i = end + 1;
            tempString = "";
            while(line.at(i) != ' '){
                string s(1, line.at(i));
                tempString.append(s);
                i++;
                end = i;
            }
            currentTransition = tempString;
            
            i = end + 3;
            tempString = "";
            while(i != line.size()){
                string s(1, line.at(i));
                tempString.append(s);
                i++;
                end = i;
            }
            transitionDefinition = tempString;
            for(int i = 0; i < stateList.size(); i++){
                if(stateList.at(i).returnStateName() == currentState){
                    stateList.at(i).AddTrasition(transitionDefinition, currentTransition);
                }

            }
        }
    }
    else cout << "Unable to open file";
    myfile.close();
//Start of Conversion to DFA
    vector<DFAState> dfaStateList;
    queue<string> statesToEvaluate;
    vector<string> statesUsed;

    for(int i = 0; i < stateList.size(); i++){
        if(stateList.at(i).isInitial()){
            iter_swap(stateList.begin() + 0, stateList.begin() + i);
            statesToEvaluate.push(stateList.at(i).returnStateName());
                statesUsed.push_back(stateList.at(i).returnStateName());
        }
    }    

    // statesToEvaluate.size() != 0
    int x =0;
    while(statesToEvaluate.size() > 0){
        string workingTranisition = "";
        string workingState = statesToEvaluate.front();
        statesToEvaluate.pop();
        DFAState tempState(workingState);
        tempState.loadAlphabet(alphabetList);

        for (int i = 0; i < alphabetList.size(); i++){

            for(int j = 0; j < stateList.size(); j++){
//If the selected state from the state list is present in the workingstate, continue. 
                if(workingState.find(stateList.at(j).returnStateName()) != string::npos){
                    for(int k = 0; k < stateList.at(j).stateTransitionsAt(i).size(); k++){
//Check for duplicates, if not present it continues.
                        if(workingTranisition.find(stateList.at(j).stateTransitionsAt(i).at(k)) == std::string::npos){

                            workingTranisition.append(stateList.at(j).stateTransitionsAt(i).at(k));
                        }
                    }
                }
            }
//If current working transition string is empty.
            if(!(workingTranisition == "")){
                tempState.AddTrasition(workingTranisition, to_string(i));
//Checks if a state has aready been inserted
                if(!(find(statesUsed.begin(), statesUsed.end(), workingTranisition) != statesUsed.end())){
                    statesUsed.push_back(workingTranisition);
                    statesToEvaluate.push(workingTranisition);
                }
                workingTranisition = "";
            }
        }
        dfaStateList.push_back(tempState);
    }

//Write to output file
    ofstream myOfile;
    myOfile.open("DFA.txt");
    myOfile << "Starting States: ";
    for(int i = 0; i < stateList.size(); i++){
        myOfile << stateList.at(i).returnStateName() << " ";
    }
    myOfile << endl;
    myOfile << "Given Alphabet: ";
    for(int i = 0; i < alphabetList.size(); i++){
        myOfile << alphabetList.at(i) << " ";
    }
    myOfile << endl;
    myOfile << "Start State: " << startState << endl;
    myOfile << "Final states: ";
    for(int i = 0; i < acceptenceList.size(); i++){
        myOfile << acceptenceList.at(i) << " ";
    }
    myOfile << endl;
    myOfile << "BEGIN" << endl;
    for(int i = 0; i < dfaStateList.size(); i++){
        for(int j = 0; j < alphabetList.size(); j++){
            myOfile << dfaStateList.at(i).printTransitionSetAt(j);
        }
    }
    for(int i = 0; i < dfaStateList.size(); i++){
            dfaStateList.at(i).cleanup();
    }
    myOfile << "END";
    myOfile.close();
}
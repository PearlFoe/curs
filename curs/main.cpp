#include <iostream>
#include "config.h"

using namespace std;

void Invoker::taleStory(string command){
    //���������� � �������������� �������, ���� ���������� �������� size()
    for(int i = 0; i < characters_counter; i++){
        characters[i]->Execute(command);
    }
}

void Invoker::addCharacter(CharacterCommand *character){
	this->catCommand = catCommand;
}


int main()
{

    return 0;
}

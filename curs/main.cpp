#include <iostream>
#include "config.h"

using namespace std;

void Invoker::tellStory(string command){
    for(int i = 0; i < characters.size(); i++){
        characters[i]->Execute(command);
    }
}

void Invoker::addCharacter(CharacterCommand *character){
    characters.push_back(character);
}

void Invoker::removeCharacter(CharacterCommand *Character){
    if(!myvector.empty()){
        myvector.pop_back();
    }
}

GrandMother::GrandMother(GrandFather *grandFather){
        this->grandFather = grandFather;
}

GrandMother::About(){
    cout<<"Я Бабушка"<<endl;
}

GrandMother::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}
GrandMother::~GrandMother(){
    delete grandFather;
}

GrandFather::GrandFather(GrandMother *grandMother){
    this->grandMother = grandMother;
}

GrandFather::About(){
    cout<<"Я Дедушка"<<endl;
}

GrandFather::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}

GrandFather::~GrandFather(){
    delete grandMother;
}

Kolobok::Kolobok(){}

Kolobok::About(){
    cout<<"Я Колобок"<<endl;
}

Kolobok::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}

Kolobok::~Kolobok(){}

Fox::Fox(){}

Fox::About(){
    cout<<"Я Лиса"<<endl;
}

Fox::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}

Fox::~Fox(){};

Hare::Hare(){}

Hare::About(){
    cout<<"Я Заяц"<<endl;
}

Hare::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}

Hare::~Hare(){}

Wolf::Wolf(){}

Wolf::About(){
    cout<<"Я Волк"<<endl;
}

Wolf::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}

Wolf::~Wolf(){}

Bear::Bear(){}

Bear::About(){
    cout<<"Я Медведь"<<endl;
}

Bear::analyzeCommand(string *command){
    switch(int(command)){
    case 1:
        cout<<"---"<<endl;
        break;
    }
}

Bear::~Bear(){}

Character* GrandFatherFactory::createCharacter(){
    return new GrandFather();
}

Character* GrandMotherFactory::createCharacter(){
    return new GrandMother();
}

Character* KolobokFactory::createCharacter(){
    return new Kolobok();
}

Character* HareFactory::createCharacter(){
    return new Hare():
}

Character* WolfFactory::createCharacter(){
    return new Wolf();
}

Character* BearFactory::createCharacter(){
    return new Bear();
}

Character* FoxFactory::createCharacter(){
    return new Fox();
}



int main()
{

    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "config.h"

using namespace std;

void Invoker::tellStory(int command){
    for(int i = 0; i < characters.size(); i++){
        characters[i]->Execute(command);
    }
}

void Invoker::addCharacter(CharacterCommand *character){
    characters.push_back(character);
}

void Invoker::removeCharacter(CharacterCommand *Character){
    if(!characters.empty()){
        characters.pop_back();
    }
}

GrandMother::GrandMother(){}

void GrandMother::About(){
    cout<<"Я Бабушка"<<endl;
}

void GrandMother::analyzeCommand(int command){
    switch(command){
    case 0:
        this->About();
        break;
    case 2:
        cout<<"Бабка испекла Колобка"<<endl;
        break;
    }
}

GrandMother::~GrandMother(){}

GrandFather::GrandFather(){}

void GrandFather::About(){
    cout<<"Я Дедушка"<<endl;
}

void GrandFather::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 1:
        cout<<"Дед собрал муку"<<endl;
        break;
    }
}

GrandFather::~GrandFather(){}

Kolobok::Kolobok(){}

void Kolobok::About(){
    cout<<"Я Колобок"<<endl;
}

void Kolobok::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 3:
        cout<<"Колобок сбежал от Бабушки и Дедушки"<<endl;
        break;
    case 5:
        cout<<"Колобок спел песню Зайцу и сбежал"<<endl;
        break;
    case 7:
        cout<<"Колобок спел песню Волку и сбежал"<<endl;
        break;
    case 9:
        cout<<"Колобок спел песню Медведю и сбежал"<<endl;
        break;
    case 11:
        cout<<"Колобок сел на нос Лисе и поет песню"<<endl;
        break;
    }
}

Kolobok::~Kolobok(){}

Fox::Fox(){}

void Fox::About(){
    cout<<"Я Лиса"<<endl;
}

void Fox::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 10:
        cout<<"Лиса грозится съесть Колобка"<<endl;
        break;
    case 12:
        cout<<"Лиса съедает колобка"<<endl;
        break;
    }
}

Fox::~Fox(){};

Hare::Hare(){}

void Hare::About(){
    cout<<"Я Заяц"<<endl;
}

void Hare::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 4:
        cout<<"Заяц грозится съесть Колобка"<<endl;
        break;
    }
}

Hare::~Hare(){}

Wolf::Wolf(){}

void Wolf::About(){
    cout<<"Я Волк"<<endl;
}

void Wolf::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 6:
        cout<<"Волк грозится съесть Колобка"<<endl;
        break;
    }
}

Wolf::~Wolf(){}

Bear::Bear(){}

void Bear::About(){
    cout<<"Я Медведь"<<endl;
}

void Bear::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 8:
        cout<<"Медведь грозится съесть Колобка"<<endl;
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
    return new Hare();
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

CharacterCommand::CharacterCommand(Receiver *receiver){
    this->receiver = receiver;
}

void CharacterCommand::Execute(int command){
    this->receiver->analyzeCommand(command);//????????????????????????
}

CharacterCommand::~CharacterCommand(){
    delete receiver;
}


int main()
{
	setlocale(LC_ALL, "Russian");

    cout << "*********************************************" << endl;
	cout << "* Курсовой проект по дисциплине *" << endl;
	cout << "* Объектно-ориентированное программирование *" << endl;
	cout << "* Тема: Сказка 'Колобок' *" << endl;
	cout << "* выполнил студент группы ИТ-992 *" << endl;
	cout << "* Воронкин Денис Сергеевич *" << endl;
	cout << "*********************************************" << endl;

    GrandFatherFactory* grandFatherFactory = new GrandFatherFactory();
    GrandMotherFactory* grandMotherFactory = new GrandMotherFactory();
    KolobokFactory* kolobokFactory = new KolobokFactory;
    HareFactory* hareFactory = new HareFactory;
    WolfFactory* wolfFactory = new WolfFactory;
    BearFactory* bearFactory = new BearFactory;
    FoxFactory* foxFactory = new FoxFactory;

    GrandFather* grandFather = (GrandFather*) grandFatherFactory->createCharacter();
    GrandMother* grandMother = (GrandMother*) grandMotherFactory->createCharacter();
    Kolobok* kolobok = (Kolobok*) kolobokFactory->createCharacter();
    Hare* hare = (Hare*) hareFactory->createCharacter();
    Wolf* wolf = (Wolf*) wolfFactory->createCharacter();
    Bear* bear = (Bear*) bearFactory->createCharacter();
    Fox* fox = (Fox*) foxFactory->createCharacter();

    Invoker* invoker = new Invoker();

    invoker->addCharacter(new CharacterCommand(grandFather));
    invoker->addCharacter(new CharacterCommand(grandMother));
    invoker->addCharacter(new CharacterCommand(kolobok));
    invoker->addCharacter(new CharacterCommand(hare));
    invoker->addCharacter(new CharacterCommand(wolf));
    invoker->addCharacter(new CharacterCommand(bear));
    invoker->addCharacter(new CharacterCommand(fox));

    fstream fs;
	string command = "";
	fs.open("commands.txt", fstream::in);

	if(!fs.is_open()){
		cout<<"Ошибка открытия файла"<<endl;
	}
	else{
		while (!fs.eof()){
			command = "";
			fs>>command;
			cout<<endl;
			invoker->tellStory(stoi(command));
		}
	}

	fs.close();
	cout<<endl;
	system("pause");

    return 0;
}













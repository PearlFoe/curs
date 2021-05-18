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
    cout<<"� �������"<<endl;
}

void GrandMother::analyzeCommand(int command){
    switch(command){
    case 0:
        this->About();
        break;
    case 2:
        cout<<"����� ������� �������"<<endl;
        break;
    }
}

GrandMother::~GrandMother(){}

GrandFather::GrandFather(){}

void GrandFather::About(){
    cout<<"� �������"<<endl;
}

void GrandFather::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 1:
        cout<<"��� ������ ����"<<endl;
        break;
    }
}

GrandFather::~GrandFather(){}

Kolobok::Kolobok(){}

void Kolobok::About(){
    cout<<"� �������"<<endl;
}

void Kolobok::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 3:
        cout<<"������� ������ �� ������� � �������"<<endl;
        break;
    case 5:
        cout<<"������� ���� ����� ����� � ������"<<endl;
        break;
    case 7:
        cout<<"������� ���� ����� ����� � ������"<<endl;
        break;
    case 9:
        cout<<"������� ���� ����� ������� � ������"<<endl;
        break;
    case 11:
        cout<<"������� ��� �� ��� ���� � ���� �����"<<endl;
        break;
    }
}

Kolobok::~Kolobok(){}

Fox::Fox(){}

void Fox::About(){
    cout<<"� ����"<<endl;
}

void Fox::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 10:
        cout<<"���� �������� ������ �������"<<endl;
        break;
    case 12:
        cout<<"���� ������� �������"<<endl;
        break;
    }
}

Fox::~Fox(){};

Hare::Hare(){}

void Hare::About(){
    cout<<"� ����"<<endl;
}

void Hare::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 4:
        cout<<"���� �������� ������ �������"<<endl;
        break;
    }
}

Hare::~Hare(){}

Wolf::Wolf(){}

void Wolf::About(){
    cout<<"� ����"<<endl;
}

void Wolf::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 6:
        cout<<"���� �������� ������ �������"<<endl;
        break;
    }
}

Wolf::~Wolf(){}

Bear::Bear(){}

void Bear::About(){
    cout<<"� �������"<<endl;
}

void Bear::analyzeCommand(int command){
    switch(int(command)){
    case 0:
        this->About();
        break;
    case 8:
        cout<<"������� �������� ������ �������"<<endl;
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
	cout << "* �������� ������ �� ���������� *" << endl;
	cout << "* ��������-��������������� ���������������� *" << endl;
	cout << "* ����: ������ '�������' *" << endl;
	cout << "* �������� ������� ������ ��-992 *" << endl;
	cout << "* �������� ����� ��������� *" << endl;
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
		cout<<"������ �������� �����"<<endl;
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













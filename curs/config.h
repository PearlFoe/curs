#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

class Reciever;
class CharacterCommand;
class Invoker;

class Character;
class GrandMother;
class GrandFather;
class Kolobok;
class Fox;
class Hare;
class Wolf;
class Bear;

class Receiver{
public:
    virtual void analyzeCommand(int command) = 0;
};

class CharacterCommand{
private:
    Receiver *receiver;
public:
    CharacterCommand(Receiver *receiver);

    void Execute(int command);

    ~CharacterCommand();
};

class Invoker{
private:
    std::vector<CharacterCommand*> characters;
public:
    void tellStory(int command);
    void addCharacter(CharacterCommand *character);
    void removeCharacter(CharacterCommand *character);
};

class Character : public Receiver{
public:
    virtual void About() = 0;
};

class GrandMother: public Character{
public:
    GrandMother();

	void About()override;
	void analyzeCommand(int command)override;

	~GrandMother();
};

class GrandFather: public Character{
public:
    GrandFather();

	void About() override;
	void analyzeCommand(int command)override;

	~GrandFather();
};

class Kolobok: public Character{
public:
    Kolobok();

    void About() override;
	void analyzeCommand(int command)override;

    ~Kolobok();
};

class Fox: public Character{
public:
    Fox();

    void About() override;
	void analyzeCommand(int command)override;

	~Fox();
};

class Hare: public Character{
public:
    Hare();

    void About() override;
	void analyzeCommand(int command)override;

	~Hare();
};

class Wolf: public Character{
public:
    Wolf();

    void About() override;
	void analyzeCommand(int command)override;

	~Wolf();
};

class Bear: public Character{
public:
    Bear();

    void About() override;
	void analyzeCommand(int command)override;

	~Bear();
};

class CharacterFactory{
public:
	virtual Character* createCharacter() = 0;
};

class GrandMotherFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

class GrandFatherFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

class KolobokFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

class FoxFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

class HareFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

class WolfFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

class BearFactory : public CharacterFactory{
public:
	Character* createCharacter() override;
};

#endif

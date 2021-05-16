#ifndef CONFIG_H
#define CONFIG_H

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
    virtual void analyzeCommand(string command) = 0;
};

class CharacterCommand{
private:
    Reciever *reciever;
public:
    CharacterCommand(Reciever *reciever);

    virtual void Execute(string command) = 0;

    ~CharacterCommand();
};

class Invoker{
private:
    CharacterCommand * characters;
private:
    void tellStory(string command);
    void addCharacter(CharacterCommand character);
    void removeCharacter(CharacterCommand character);
    void setcommand(CharacterCommand command);//???????????????????????????????????
};

class Character : public Receiver{
public:
    virtual void About() = 0;
};

class GrandMother: public Character{
private:
    GrandFather *grandFather;
public:
    GrandMother();

	void About() override;
	void analyzeCommand(string command)override;

	~GrandMother();
};

class GrandFather: public Character{
private:
    GrandMother *grandMother;
public:
    GrandFather();

	void About() override;
	void analyzeCommand(string command)override;

	~GrandFather();
};

class Kolobok: public Character{
public:
    Kolobok();

    void About() override;
	void analyzeCommand(string command)override;

    ~Kolobok();
};

class Fox: public Character{
public:
    Fox();

    void About() override;
	void analyzeCommand(string command)override;

	~Fox();
};

class Hare: public Character{
public:
    Hare();

    void About() override;
	void analyzeCommand(string command)override;

	~Hare();
};

class Wolf: public Character{
public:
    Wolf();

    void About() override;
	void analyzeCommand(string command)override;

	~Wolf();
};

class Bear: public Character{
public:
    Bear();

    void About() override;
	void analyzeCommand(string command)override;

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

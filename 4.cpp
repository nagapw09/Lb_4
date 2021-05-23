#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Главный персонаж
class MainCharacter
{
public:
	virtual void Fight() {}

	virtual ~MainCharacter() {}
};

// Бестиарий
class Bestiariy : public MainCharacter
{
public:
	void Fight() override { cout << "Бестиарий"; }
};

// Мирмилон
class Mirmilon : public MainCharacter
{
public:
	void Fight() override { cout << "Мирмиллон"; }
};

// Фракиец
class Frakiec : public MainCharacter
{
public:
	void Fight() override { cout << "Фракиец"; }
};

// Эквит
class Ekvit : public MainCharacter
{
public:
	void Fight() override { cout << "Эквит"; }
};

// Галл
class Gall : public MainCharacter
{
public:
	void Fight() override { cout << "Галл"; }
};

// Велит
class Orders : public MainCharacter
{
public:
	void Fight() override { cout << "Велит"; }
};

// Провокатор
class Provocateur : public MainCharacter
{
public:
	void Fight() override { cout << "Провокатор"; }
};

// Гопломах
class Goplomakh : public MainCharacter
{
public:
	void Fight() override { cout << "Гопломах"; }
};

// Димахер
class Diemaher : public MainCharacter
{
public:
	void Fight() override { cout << "Димахер"; }
};

// Скутар
class Scutar : public MainCharacter
{
public:
	void Fight() override { cout << "Скутар"; }
};

// Секугор
class Secugor : public MainCharacter
{
public:
	void Fight() override { cout << "Секугор"; }
};

// Ратиарий
class Ratiarius : public MainCharacter
{
public:
	void Fight() override { cout << "Ратиарий"; }
};

class CharacterCreator
{
public:
	virtual MainCharacter* FactoryM_CreateMainCharacter() const = 0;

	void SomeOperation() const {
		MainCharacter* _MainCharacter_ = this->FactoryM_CreateMainCharacter();

		_MainCharacter_->Fight();

		delete _MainCharacter_;
	}

	virtual ~CharacterCreator() {};
};

class ConcreteBestiariy : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Bestiariy(); }
};

class ConcreteFrakiec : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Frakiec(); }
};

class ConcreteMirmilon : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Mirmilon(); }
};

class ConcreteEkvit : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Ekvit(); }
};

class ConcreteGall : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Gall(); }
};

class ConcreteOrders : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Orders(); }
};

class ConcreteProvocateur : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Provocateur(); }
};

class ConcreteGoplomakh : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Goplomakh(); }
};

class ConcreteDiemaher : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Diemaher(); }
};

class ConcreteScutar : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Scutar(); }
};

class ConcreteSecugor : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Secugor(); }
};

class ConcreteRatiarius : public CharacterCreator
{
public:
	MainCharacter* FactoryM_CreateMainCharacter() const override { return new Ratiarius(); }
};

//////////////////////////////////////////////////////

// Противник/Оппонент
class Opponent
{
public:
	virtual void Fight() {}

	virtual ~Opponent() {}
};

// Леопард
class Leopard : public Opponent
{
public:
	void Fight() override { cout << "Леопард\n"; }
};

// Тигр
class Tiger : public Opponent
{
public:
	void Fight() override { cout << "Тигр\n"; }
};

class OpponentCreator
{
public:
	virtual Opponent* FactoryM_CreateOpponent() const = 0;

	void SomeOperation() const {
		Opponent* _Opponent_ = this->FactoryM_CreateOpponent();

		_Opponent_->Fight();

		delete _Opponent_;
	}

	virtual ~OpponentCreator() {};
};

class ConcreteLeopard : public OpponentCreator
{
public:
	Opponent* FactoryM_CreateOpponent() const override { return new Leopard(); }
};

class ConcreteTiger : public OpponentCreator
{
public:
	Opponent* FactoryM_CreateOpponent() const override { return new Tiger(); }
};

//////////////////////////////////////////////////////

// Строитель
class MainCharacterArmament
{
public:
	vector<string> parts;

	void PrintArmament() const {
		cout << "Вооружение и Сильные стороны персонажа: ";

		for (int i = 0; i < parts.size(); i++) {
			if (parts[i] == parts.back())
				cout << parts[i];
			else
				cout << parts[i] << ", ";
		}
		cout << endl;
	}
};

class Builder
{
public:
	virtual void buildShield() const = 0;
	virtual void buildSpear() const = 0;
	virtual void buildSword() const = 0;
	virtual void buildArmor() const = 0;

	virtual void buildFast() const = 0;
	virtual void buildLarge() const = 0;
	virtual void buildStrong() const = 0;
	virtual void buildStrategist() const = 0;
	virtual void buildStrongHealth() const = 0;

	virtual ~Builder() {}
};

class ArmamentBuilder : public Builder
{
	MainCharacterArmament* armament;
public:
	ArmamentBuilder() { this->Reset(); }

	void Reset() { this->armament = new MainCharacterArmament(); }

	void buildShield() const override { this->armament->parts.push_back("Щит"); }

	void buildSpear() const override { this->armament->parts.push_back("Копье"); }

	void buildSword() const override { this->armament->parts.push_back("Меч"); }

	void buildArmor() const override { this->armament->parts.push_back("Доспехи"); }

	void buildFast() const override { this->armament->parts.push_back("Быстрый"); }

	void buildLarge() const override { this->armament->parts.push_back("Большой"); }

	void buildStrong() const override { this->armament->parts.push_back("Сильный"); }

	void buildStrategist() const override { this->armament->parts.push_back("Стратег"); }

	void buildStrongHealth() const override { this->armament->parts.push_back("Сильное здоровье"); }

	MainCharacterArmament* Get_armament() {
		MainCharacterArmament* result = this->armament;
		this->Reset();
		return result;
	}

	~ArmamentBuilder() { delete armament; }
};

class Director
{
	Builder* builder;
public:
	void Set_builder(Builder* builder) { this->builder = builder; }

	void BuildEasyLvl() {
		this->builder->buildShield();
		this->builder->buildSpear();
		this->builder->buildSword();
		this->builder->buildArmor();
		this->builder->buildStrongHealth();
		this->builder->buildFast();
	}

	void BuildNormalLvl() {
		this->builder->buildShield();
		this->builder->buildSpear();
		this->builder->buildArmor();
		this->builder->buildStrong();
		this->builder->buildLarge();
	}

	void BuildHardLvl() {
		this->builder->buildShield();
		this->builder->buildArmor();
		this->builder->buildSpear();
		this->builder->buildStrategist();
	}
};

//////////////////////////////////////////////////////

class Game
{
public:
	void playGame()
	{
		cout << "\t\tИГРА ЗАПУСТИЛАСЬ\n";
		cout << "\tВыберите героя из предложенных:\n1. Бестиарий\n2. Мирмилон\n3. Фракиец\n4. Эквит\n5. Галл\n6. Велит\n7. Провокато\n8. Гопломах\n9. Димахер\n10. Скутар\n11. Секугор\n12. Ратиарий\n\n"; int choise;	cin >> choise;

		CharacterCreator* character = new ConcreteBestiariy();

		if (choise == 1)
			character = new ConcreteBestiariy();

		else if (choise == 2)
			character = new ConcreteMirmilon();

		else if (choise == 3)
			character = new ConcreteFrakiec();

		else if (choise == 4)
			character = new ConcreteEkvit();

		else if (choise == 5)
			character = new ConcreteGall();

		else if (choise == 6)
			character = new ConcreteOrders();

		else if (choise == 7)
			character = new ConcreteProvocateur();

		else if (choise == 8)
			character = new ConcreteGoplomakh();

		else if (choise == 9)
			character = new ConcreteDiemaher();

		else if (choise == 10)
			character = new ConcreteScutar();

		else if (choise == 11)
			character = new ConcreteSecugor();

		else if (choise == 12)
			character = new ConcreteRatiarius();
		

		else
			cout << "Неверный выбор героя\n";


		cout << "\n\tВыберите уровень сложности:\n1. Легкий\n2. Средний\n3. Сложный\n\n"; cin >> choise;

		ArmamentBuilder* builder = new ArmamentBuilder();
		Director* _director = new Director();
		_director->Set_builder(builder);
		MainCharacterArmament* armament = new MainCharacterArmament();

		if (choise == 1) {
			_director->BuildEasyLvl();
			armament = builder->Get_armament();
			armament->PrintArmament();
		}

		else if (choise == 2) {
			_director->BuildNormalLvl();
			armament = builder->Get_armament();
			armament->PrintArmament();
		}

		else if (choise == 3) {
			_director->BuildHardLvl();
			armament = builder->Get_armament();
			armament->PrintArmament();
		}

		else
			cout << "Неверный выбор уровня сложности\n";


		cout << "\n\tВыберите противника:\n1. Леопард\n2. Тигр\n\n"; cin >> choise;

		OpponentCreator* opponent = new ConcreteLeopard();

		if (choise == 1)
			opponent = new ConcreteLeopard();

		else if (choise == 2)
			opponent = new ConcreteTiger();

		else
			cout << "Неверный выбор противника\n";


		cout << "\n\t\tБОЙ МЕЖДУ\n\t";

		character->SomeOperation();
		cout << "\t\tи\t";
		opponent->SomeOperation();


		delete builder;
		delete _director;
		delete character;
		delete opponent;
		delete armament;
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");

	Game game;
	game.playGame();

	return 0;
}
#include <iostream>
using namespace std;

//class for character
class Character
{
private:
string name;
int damagePoint;
int defence;
int health;
public:
	Character(string _name,int _health, int _damagePoint, int _defence)
	{
		name = _name;
		health = _health;
		damagePoint = _damagePoint;
		defence = _defence;
	}
	void Display()
	{
		cout<<"\nNAME : "<<name;
		cout<<"\nHEALTH : "<<health;
		cout<<"\nDAMAGE POINT : "<<damagePoint;
		cout<<"\nDEFENCE : "<<defence;
	}
};

//class for safe house
class SafeHouse
{
private:
	int option;
	int n = 0;
	Character *list[7] ;
	void DisplayAvailableCharacters()
	{
		for(int i=0; i<n; i++)
			list[n]->Display();
	}
public:
	SafeHouse()
	{
		list[0] = new Character("LADY WAGON",100,84,52);
		n=1;
	}
	void Play()
	{
		while (list[0] != NULL)
		{
			cout<<"\nAVAILABLE CHARACTERS = ";
			DisplayAvailableCharacters();
			if(n>3)
			{
				cout<<"\nDO YOU WANT TO SWAP CHARCTERS\n1. YES\n2. NO";
				cout<<"\nENTER YOUR CHOICE : ";
				cin>>option;
				switch(option)
				{
					case 1:
					SwapCharacter();
					break;
					default:
					cout<<"\nINVALID CHOICE SO DEFAULT CHOICE NO";
					break;
				}
					
			}
			cout<<"\n1. EXPLORE THE WILD";
			cout<<"\n2. GO TO SHOP";
			cout<<"\nENTER YOUR OPTION : ";
			cin>>option;
		}
	}
};

//class of game
class IntoTheWild
{
private:
	//functions
	//function to display game name
	void DisplayGameName()
	{
		cout<<"\n\t\t\tINTO THE WILD";	
	}
	//function to display game story
	void DisplayGameStory()
	{
		cout<<"\nYOU ARE IN A NEW WORLD NAMED WAKANDA. YOU NEED TO TAKE OVER THIS WORLD BY CONQUER THE ANIMALS AND ENEMIES IN THE WORLD . YOU CAN EXPLORE THE WORLD BETWEEN 10.00HR TO 20.00 HRS. YOU HAVE A HOUSE IN THIS WORLD INITIALLY YOU HAVE ONE CHARACTER AVAILABLE IN THE HOUSE LATER ON YOU CAN UNLOCK MORE CHARACTERS BY EXPLORE THEM. AFTER EACH MATCH YOU CAN COME BACK AND CHANGE THE CHARACTER. YOU CAN HAVE UPTO 3 CHARATERS AT THE TIME OF EXPLORE EACH CHARACTER HAVE DIFFERENT ABILITIES AND EACH ABILITIES TAKE DIFFERENT TURN CYCLE \n\nALL THE BEST";
	}
	
public:
	void Game()
	{
		//function call to display game name
		DisplayGameName();
		//function to display game story
		DisplayGameStory();
		//class object safehouse
		SafeHouse House;
		House.Play();
		
	}
};

int main()
{
	IntoTheWild newGame;
	newGame.Game();
	return 0;
}
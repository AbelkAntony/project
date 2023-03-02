#include <iostream>
using namespace std;

//class for character
class Character
{
private:
string name;
int damagePoint;
int defence;
int maxHealth;
int health;
public:
	Character(string _name,int _health, int _damagePoint, int _defence)
	{
		name = _name;
		maxHealth = _health;
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

	//getter
	int GetDamagePoints()	{		return damagePoint;		}

	//setter
	void TakeDamage(int damagePoint)		
	{	
		int damage;
		if(damagePoint < defence)
			damage =0;
		else
			damage =damagePoint-defence;
		health=health-damage;	
		cout<<"\nCAUSE DAMAGE "<<damage;
	}
};


//class for player
class Player : public Character
{
public:
	Player (string _name,int _health, int _damagePoint, int _defence): Character ( _name, _health,  _damagePoint, _defence)
	{
		
	}
};

//class for enemy
class Enemy : public Character
{
public:
	Enemy (string _name,int _health, int _damagePoint, int _defence): Character ( _name, _health,  _damagePoint, _defence)
	{
		
	}
};

//class for safe house
class SafeHouse
{
private:
	//variables
	float time = 10.00;
	int option;
	int playerCount = 0;
	Player *playerList[7];
	int gold=0;
	int copper=0;
	int iron = 0;
	//function
	//function to display all player characters
	void DisplayAllCharacters()
	{
		for(int i=0; i<playerCount; i++)
		{
			cout<<endl<<endl;
			cout<<"\nCHARACTER "<<i+1;
			playerList[i]->Display();
		}
	}

	void SwapCharacter()
	{
		bool swap = true;
		while(swap)
		{
			int changeThis;
			int chanageThat;
			Player *ptr;
			DisplayAllCharacters();
			cout<<"\nSELECT THE NUMBER OF CHARCTER TO CHANGED : ";
			cin>>changeThis;
			cout<<"\nSELECT THE NUMBER OF CHARACTER TO REPLACE : ";
			cin>>chanageThat;
			ptr = playerList[changeThis-1];
			playerList[changeThis-1]=playerList[chanageThat-1];
			playerList[chanageThat-1]=ptr;
			cout<<"DO YOU WANT TO SWAP AGAIN?\n1. YES\n2. NO";
			cin>>option;
			if(option==2)
				swap = false;
		}
	}

	
public:
	//getter
	Player *GetCharacterList(int i)		{		return playerList[i];	}
	int GetNumberOfPlayers()			{		return playerCount;		}

	//setter
	void AddGold(int value)				{		gold =gold+ value;cout<<"\nGET "<<value<<" GOLD FROM CHEST";			}
	void AddCopper(int value)			{		copper =copper+ value;cout<<"\nGET "<<value<<" COPPER FROM CHEST";		}
	void AddIron(int value)				{		iron =iron+ value;cout<<"\nGET "<<value<<" IRON FROM CHEST";			}

	//function to dispaly utilities
	void DisplayUtilities()
	{
		cout<<"\n\nGOLD : "<<gold;
		cout<<"\nCOPPER : "<<copper;
		cout<<"\nIRON : "<<iron;
	}


	SafeHouse()
	{
		playerList[0] = new Player("LADY WAGON",100,84,52);
		playerCount=1;
	}
	int Play()
	{
		while (playerCount>0)
		{
			cout<<"\nAVAILABLE CHARACTERS ";
			DisplayAllCharacters();
			if(playerCount>3)
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
			cout<<"\n3. EXIT GAME";
			cout<<"\nENTER YOUR OPTION : ";
			cin>>option;
			switch(option)
			{
				case 1:
				if(time>=10.00 && time<20.00)
					return 1;
				else
				{
					cout<<"\nTIME IS "<<time<<"YOU CANNOT EXPLORE AT THIS TIME";
					return 0;
				}
				case 2:
				return 2;
				case 3:
				return 3;
				default:
				cout<<"\nINVALID OPTION";
				return 4;
			}
		}
		cout<<"return 0";
		return 0;
	}
};

//class of game
class IntoTheWild
{
private:
	//variable
	int option=0;
	SafeHouse *House = new SafeHouse;
	int numberOfPlayers;
	int playerCount = 0;
	int numberOfEnemy=0;
	int numberOfCharacters=0;
	Player *playerList[7];
	Enemy *enemyList[3];
	string player = "alive";
	string enemy = "alive";
	int round = 1;
	Character *allCharacter[6];
	//functions
	//function to display game name
	void DisplayGameName()
	{
		cout<<"\n\t\t\tINTO THE WILD";	
	}
	//function to display game story
	void DisplayGameStory()
	{
		cout<<"\nYOU ARE IN A NEW WORLD NAMED WAKANDA. YOU NEED TO TAKE OVER THIS WORLD BY CONQUER THE ANIMALS AND ENEMIES IN THE WORLD . YOU CAN EXPLORE THE WORLD BETWEEN 10.00HR TO 20.00 HRS. YOU HAVE A HOUSE IN THIS WORLD INITIALLY YOU HAVE ONE CHARACTER AVAILABLE IN THE HOUSE LATER ON YOU CAN UNLOCK MORE CHARACTERS BY EXPLORE THEM. AFTER EACH MATCH YOU CAN COME BACK AND CHANGE THE CHARACTER. YOU CAN HAVE UPTO 3 CHARATERS AT THE TIME OF EXPLORE EACH CHARACTER HAVE DIFFERENT ABILITIES AND EACH ABILITIES TAKE DIFFERENT TURN CYCLE . YOU CAN HAVE MANY CHARACTERS BUT WHEN YOU GO TO EXPLORE YOU CAN HAVE ONLY FIRST THREE CHARACTER \n\nALL THE BEST";
	}

	//function to get random number
	int GetRandomNumber(int lowerLimit, int upperLimit)
	{
		int randomNumber = lowerLimit + (rand()%(upperLimit - lowerLimit + 1));
		return randomNumber;
	}

	void DisplayStatus()
	{
		cout<<"\n\nPLAYERS";
		for(int i=0;i<numberOfPlayers;i++)
		{
			cout<<"\nNUMBER "<<i+1;
			playerList[i]->Display();
		}
		cout<<"\n\nENEMIES";
		for(int i=0;i<numberOfEnemy;i++)
		{
			cout<<"\nNUMBER "<<i+1;
			enemyList[i]->Display();	
		}
	}
	//function to fight
	void Fight(Player *player, Enemy *enemy)
	{
		enemy->TakeDamage(player->GetDamagePoints())	;
	}
	void Fight()
	{
		int enemy =  GetRandomNumber(0, numberOfEnemy-1);
		int player = GetRandomNumber(0, numberOfPlayers-1);
		cout<<"\n"<<player;
		playerList[player]->TakeDamage(enemyList[enemy]->GetDamagePoints());
	}

	//function to game round
	void GameRound()
	{
		int playerNumber;
		int enemyNumber;
		
		numberOfPlayers = House->GetNumberOfPlayers();
		for(int i=0;i<numberOfPlayers;i++)
			playerList[i] = House->GetCharacterList(i);
		CreateEnemy(numberOfPlayers); 
		DisplayStatus();
		while(player =="alive" && enemy == "alive")
		{
			cout<<"\nROUND : "<<round;
			cout<<"\nPLAYER TURN";
			cout<<"\nSELECT YOUR PLAYER TO ATTACK : ";
			cin>>playerNumber;
			cout<<"\nENTR ENEMY TO ATTACK : ";
			cin>>enemyNumber;
			Fight(playerList[playerNumber-1],enemyList[enemyNumber-1]);
			//if(enemyList[enemyNumber-1]->GetHealth<=0)
			{
			//	Delete(enemyList[enemyNumber-1]);
			}
			DisplayStatus();
			Fight();
			round++;
		}
	}

	//function to create enemy
	void CreateEnemy(int numberOfPlayers)
	{
		numberOfEnemy = 3;
		if(numberOfPlayers<3)
		{
			numberOfEnemy = numberOfPlayers;
		}
		for(int i=0;i<numberOfEnemy;i++)
		{
			option = GetRandomNumber(1,4);
			switch(option)
			{
				case 1:
				enemyList[i]= new Enemy ("WOLF",100,30,40);
				break;
				case 2:
				enemyList[i]= new Enemy ("TIGER",150,50,30);
				break;
				case 3:
				enemyList[i]= new Enemy ("ELEPHANT",200,30,60);
				break;
				case 4:
				enemyList[i]= new Enemy ("LION",175,50,40);
				break;
			}
		}
	}
	
	
	

	//function for chest
	void Chest()
	{
		int numberOfItems = GetRandomNumber(1,3);
		for(int i=0; i<numberOfItems;i++)
		{
			option = GetRandomNumber(1,3);
			int value = GetRandomNumber(5, 25);
			switch(option)
			{
				case 1:
				House->AddGold(value);
				break;
				case 2:
				House->AddCopper(value);
				break;
				case 3:
				House->AddIron(value);
				break;
			}
		}
		House->DisplayUtilities();	
	}

	

	//function to shop
	void Shop()
	{
			
	}

	//function to explore
	int Explore()
	{
		option = GetRandomNumber(1,1);
		switch(option)
		{
			case 1:
			cout<<"\nFIGHT STARTS";
			GameRound();
			return 0;
			case 2:
			cout<<"\nFOUND A CHEST";	
			Chest();
			return 0;
		}
		return 0;
	}
	
public:
	void Game()
	{
		//function call to display game name
		DisplayGameName();
		//function to display game story
		DisplayGameStory();
		//class object safehouse
		
		while(option <3)
		{
			option = House->Play();
			switch(option)
			{	
				case 1:
				option= Explore();
				break;
				case 2:
				Shop();
				break;
			}
		}
	}
};

int main()
{
	srand(time(0));
	IntoTheWild newGame;
	newGame.Game();
	return 0;
}
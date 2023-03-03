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
int currentHealth;
public:
	Character(string _name,int _health, int _damagePoint, int _defence)
	{
		name = _name;
		maxHealth = _health;
		currentHealth = _health;
		damagePoint = _damagePoint;
		defence = _defence;
	}
	void Display()
	{
		cout<<"\nNAME : "<<name;
		cout<<"\nHEALTH : "<<currentHealth;
		cout<<"\nDAMAGE POINT : "<<damagePoint;
		cout<<"\nDEFENCE : "<<defence;
	}

	//getter
	int GetDamagePoints()	{		return damagePoint;		}
	int GetHealth()			{		return currentHealth;	}
	string GetName()		{		return name;			}
	//setter
	void TakeDamage(int damagePoint)		
	{	
		int damage;
		if(damagePoint-defence<0)
			damage =0;
		else if(currentHealth-(damagePoint-defence)<0)
			damage = currentHealth;
		else
			damage =damagePoint-defence;
		currentHealth=currentHealth-damage;	
		cout<<"\nCAUSE DAMAGE "<<damage;
	}
	void SetDamagePoint()	{		damagePoint = damagePoint+(damagePoint*.2);		}
};


//class for player
class Player : public Character
{
private:
string weapon;
int weaponUpgrade;
public:
	Player (string _name,int _health, int _damagePoint, int _defence,string _weapon,int _weaponUpgrade): Character ( _name, _health,  _damagePoint, _defence)
	{
		weapon = _weapon;
		weaponUpgrade = _weaponUpgrade;
	}

	//getter
	int GetWeaponUpgrade()			{		return weaponUpgrade;	}

	//setter
	void SetWeaponUpgrade()			{		weaponUpgrade = weaponUpgrade+(weaponUpgrade * .2);	}
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
	Player *ptr;
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

	int GetRandomNumber(int lowerLimit, int upperLimit)
	{
		int randomNumber = lowerLimit + (rand()%(upperLimit - lowerLimit + 1));
		return randomNumber;
	}
	
public:
	//getter
	Player *GetCharacterList(int i)		{		return playerList[i];	}
	int GetNumberOfPlayers()			{		return playerCount;		}
	

	//setter
	void AddGold(int value)				{		gold =gold+ value;cout<<"\nGET "<<value<<" GOLD FROM CHEST";			}
	//void AddCopper(int value)			{		copper =copper+ value;cout<<"\nGET "<<value<<" COPPER FROM CHEST";		}
	void AddIron(int value)				{		iron =iron+ value;cout<<"\nGET "<<value<<" IRON FROM CHEST";			}

	//function to dispaly utilities
	void DisplayUtilities()
	{
		cout<<"\n\nGOLD : "<<gold;
		//cout<<"\nCOPPER : "<<copper;
		cout<<"\nIRON : "<<iron;
	}

	//function to get random player
	void GetRandomPlayer()
	{
		bool playerFound = false;
		while(GetNumberOfPlayers()<7)
		{
			option = GetRandomNumber(1,7);
			switch(option)
			{
				case 1:
				ptr = new Player ("LADY WAGON",100,84,52,"ARROW AND BOW",50);
				break;
				case 2:
				ptr = new Player ("ROBERT",100,48,61,"BATON",60);
				break;
				case 3:
				ptr = new Player ("STELLA",100,67,54,"TASER",30);
				break;
				case 4:
				ptr = new Player ("ALBERT",100,65,38,"LASER GUN",70);
				break;
				case 5:
				ptr = new Player ("WIZARD",100,65,38,"FIRE GUN",40);
				break;
				case 6:
				ptr = new Player ("PABLO",100,58,47,"MACHETES",55);
				break;
				case 7:
				ptr = new Player ("JAMES",100,54,43,"HAMMER",35);
				break;
			}
			for(int i=0;i<playerCount;i++)
			{
				if(playerList[i]==ptr)
				{
					playerFound = true;
				}
			}
			if(playerFound == false)
			{
				playerList[playerCount] = ptr;
				playerCount++;
				break;
			}
		}
	}


	SafeHouse()
	{
		GetRandomPlayer();
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
	string name;
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

	//fuction defenition of Plawer win
	void PlayerWin()
	{
		Chest();
		House->GetRandomPlayer();
	}	

	void DisplayPlayer()
	{
		cout<<"\n\nPLAYERS";
		for(int i=0;i<numberOfPlayers;i++)
		{
			cout<<"\nNUMBER "<<i+1;
			playerList[i]->Display();
		}
	}

	void DisplaEnemies()
	{
		cout<<"\n\nENEMIES";
		for(int i=0;i<numberOfEnemy;i++)
		{
			cout<<"\nNUMBER "<<i+1;
			enemyList[i]->Display();	
		}	
	}

	//funtion to display status of player and enemy
	void DisplayStatus()
	{
		DisplayPlayer();
		DisplaEnemies();
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
		cout<<"\n"<<enemyList[enemy]->GetName()<<" ATTACKED "<<playerList[player]->GetName();
		playerList[player]->TakeDamage(enemyList[enemy]->GetDamagePoints());
		if(playerList[player]->GetHealth()<=0)
			{
				name = enemyList[player]->GetName();
				cout<<"\nENEMY "<<name<<" DEAD";
				DeleteCharacter(player,numberOfPlayers);
				
			}
		DisplayStatus();
	}

//function to delete dead player
	void DeleteCharacter(int playerPosition,int numberOfPlayer)
	{
		if(playerPosition==0)
		{
			delete playerList[0];
			numberOfPlayers -=1;
		}
		else
		{
			for(int i=0; i<numberOfEnemy; i++)
			{
				if(playerList[i]==playerList[playerPosition])
				{
					delete playerList[i];
					for(int j=i;j<numberOfPlayers;j++)
					{
						playerList[j]=playerList[j+1];
					}
					i -=1;
					numberOfPlayers -=1;
				}
			}
		}
		if(numberOfPlayers <=0)
		{
			player ="dead";
		}
	}
//function to delete dead enemy
	void DeleteCharacter(int enemyPosition)
	{
		if(enemyPosition==0)
		{
			delete enemyList[0];
			numberOfEnemy -=1;
		}
		else
		{
			for(int i=0; i<numberOfEnemy; i++)
			{
				if(enemyList[i]==enemyList[enemyPosition])
				{
					cout<<"\n deleting enemy";
					delete enemyList[i];
					for(int j=i;j<numberOfEnemy;j++)
					{
						enemyList[j]=enemyList[j+1];
					}
					i -=1;
					numberOfEnemy -=1;
				}
			}
		}
		if(numberOfEnemy <=0)
		{
			enemy ="dead";
		}
	}

	//function for chest
	void Chest()
	{
		int numberOfItems = GetRandomNumber(1,3);
		for(int i=0; i<numberOfItems;i++)
		{
			option = GetRandomNumber(1,2);
			int value = GetRandomNumber(5, 25);
			switch(option)
			{
				case 1:
				House->AddGold(value);
				break;
				case 2:
				House->AddIron(value);
				break;
				//case 3:
				//House->AddCopper(value);
				//break;
			}
		}
		House->DisplayUtilities();	
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
		round = 0;
		while(player =="alive" && enemy == "alive")
		{
			cout<<"\n\nROUND : "<<round;
			cout<<"\nPLAYER TURN";
			cout<<"\nSELECT YOUR PLAYER TO ATTACK : ";
			cin>>playerNumber;
			cout<<"\nENTR ENEMY TO ATTACK : ";
			cin>>enemyNumber;
			Fight(playerList[playerNumber-1],enemyList[enemyNumber-1]);
			if(enemyList[enemyNumber-1]->GetHealth()<=0)
			{
				name = enemyList[enemyNumber-1]->GetName();
				cout<<"\nENEMY "<<name<<" DEAD";
				DeleteCharacter(enemyNumber-1);
				
			}
			if(numberOfEnemy==0)
			{
				PlayerWin();
				break;
			}
			DisplayStatus();
			Fight();
			if(numberOfPlayers == 0)
			{
				cout<<"\nYOU LOSS";
				break;
			}
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
	
	
	



	

	//function to shop
	void Shop()
	{
		DisplayPlayer();
		cout<<"\nSELECT PLAYER : ";
		cin>>option;
		
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
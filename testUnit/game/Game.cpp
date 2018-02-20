#include "Game.hpp"

/*gameplay*/
void Game::gameplay(Market& market){

	int i;
	int numberOfHeroes;
	int typeOfHero;
	string nameOfHero;

	cout<<"How many heroes you want to have?"<<endl
		<<"give a number between 1-3"<<endl;
	cin>>numberOfHeroes;
	while((numberOfHeroes!=1 && numberOfHeroes!=2 && numberOfHeroes!=3) || cin.fail()){
			if(cin.fail()){ // or if(!cin)
			    // user didn't input a number
			    cin.clear(); // reset failbit
			    cin.ignore(100, '\n'); //skip bad input
				cout<<"Give a valid number (1-3). Please try again."<<endl;
				cin>>numberOfHeroes;	
			}
			else
			{
			cout<<"Give a valid number (1-3). Please try again."<<endl;
			cin>>numberOfHeroes;
			}
	}
								

/*UI for creation of heroes*/
	Hero**Heroes=new Hero*[numberOfHeroes];
	for(i=0;i<numberOfHeroes;i++){
		cout<<"Give a name for Hero "<<i+1<<" and a number between 1-3 for the type of Hero."<<endl
			<<"1)Warrior, 2)Paladin, 3)Sorcerer"<<endl;
		cin>>nameOfHero;	
		cin>>typeOfHero;
		while((typeOfHero!=1 && typeOfHero!=2 && typeOfHero!=3)|| cin.fail()){
			if(cin.fail()){ // or if(!cin)
			    // user didn't input a number
			    cin.clear(); // reset failbit
			    cin.ignore(100, '\n'); //skip bad input
				cout<<"Give a valid number (1-3). Please try again."<<endl;
				cin>>typeOfHero;	
			}
			else{
				cout<<"Give a valid number (1-3). Please try again."<<endl;
				cin>>typeOfHero;
			}
		}
		
		switch(typeOfHero){
			case 1:Heroes[i]=new Warrior(nameOfHero);
				   break;
			case 2:Heroes[i]=new Paladin(nameOfHero);
				   break;
			case 3:Heroes[i]=new Sorcerer(nameOfHero);
				   break;
		}
	}

/*Creation of our grid*/
Grid* g = new Grid;
	char keyInput;	// when grid is displayed keyInput takes keyboard's input
	int inBattle = 0;	// used to know if we are in battle at a specific time unit
	int battle = 0;	// if battle is about to begin getmv sets battle to 1

	// Game begins!
	do {

		g->displayMap();
		keyInput = g->getmv(battle);
		switch(keyInput){
			case 'm':
				if (!g->nextToMarket())
					break;
				g->clearScreen();
				market.menuMarket(Heroes,numberOfHeroes);	// let's go to the market
				break;
			case 'p':
				g->clearScreen();
				for (int i = 0; i < numberOfHeroes; ++i)
					Heroes[i]->printHero();
				cout << "Press anything to continue...";
				/////////////////////////////////////////////////////// check if it works /////////////////////////////////////////////////
				if(cin.fail()){
					cin.clear(); // reset failbit
			   		cin.ignore(100, '\n'); //skip bad input
				}
				cin.ignore(100, '\n');	
				break;
			case 'i':
				int returnOfCheckInventory;
				int choice;
				g->clearScreen();
				cout << "For which hero you want to see inventory?" << endl;
				for (int i = 0; i < numberOfHeroes; ++i)
					Heroes[i]->printHero();	
				cin >> choice;

				while(choice < 0 || choice > numberOfHeroes || cin.fail()){	// while user don't give valid input
					if(cin.fail()){ // or if(!cin)
					    // user didn't input a number
					    cin.clear(); // reset failbit
					    cin.ignore(100, '\n'); //skip bad input
						cout << "Give a valid number (1-" << numberOfHeroes << "). Please try again." << endl;
						cin >> choice;	
					}
					else{
						cout << "Give a valid number (1-" << numberOfHeroes << "). Please try again." << endl;
						cin >> choice;
					}
				}
				// If user's input is valid do whatever you have to do...
				switch(choice){
					case 1:
						returnOfCheckInventory = Heroes[0]->inventory.checkInventory(*Heroes[0],inBattle);
						if(returnOfCheckInventory!=2)
							getchar();
						cout << "Press anything to continue...";
						/////////////////////////////////////////////////////// check if it works /////////////////////////////////////////////////
						if(cin.fail()){
							cin.clear(); // reset failbit
					   		cin.ignore(100, '\n'); //skip bad input
						}
						cin.ignore(100, '\n');	
						break;
					case 2:
						returnOfCheckInventory=Heroes[1]->inventory.checkInventory(*Heroes[1],inBattle);
						if(returnOfCheckInventory!=2)
							getchar();
						cout << "Press anything to continue...";
						/////////////////////////////////////////////////////// check if it works /////////////////////////////////////////////////
						if(cin.fail()){
							cin.clear(); // reset failbit
					   		cin.ignore(100, '\n'); //skip bad input
						}
						cin.ignore(100, '\n');	
						break;
					case 3:
						returnOfCheckInventory=Heroes[2]->inventory.checkInventory(*Heroes[2],inBattle);
						if(returnOfCheckInventory!=2)
							getchar();
						cout << "Press anything to continue...";
						/////////////////////////////////////////////////////// check if it works /////////////////////////////////////////////////
						if(cin.fail()){
							cin.clear(); // reset failbit
					   		cin.ignore(100, '\n'); //skip bad input
						}
						cin.ignore(100, '\n');	
						break;
				}
				break;
			case 'b':{
					if(!battle)
						break;

					// Creation of monsters (same number as heroes)
					int levelOfMonsters = getAverageLevelOfHeroes(Heroes, numberOfHeroes);
					Monster** Monsters = new Monster*[numberOfHeroes];
					int randomMonster;
					for(int j = 0; j < numberOfHeroes; j++){
						randomMonster = rand()%3;
						switch(randomMonster){
							case 0:
								Monsters[j] = new Dragon("Dragon", levelOfMonsters); 
								break;
							case 1:
								Monsters[j] = new Spirit("Spirit", levelOfMonsters);
								break;
							case 2:
								Monsters[j] = new Exoskeleton("Exoskeleton", levelOfMonsters);
								break;
							default:break;
						}
					}
				
					int option;	// attack or check inventory to equip item (or cast spell) or use potion
					int i;
					int check; // check if the user used a Potion or casted a Spell in inventory
					int counter = 1; // counter for the rounds
					inBattle = 1;	// while we are in battle
					int checkLifeOfSpell[numberOfHeroes];		// 
					int monsterHitWithSpell[numberOfHeroes];	// for every monster if it is under the effect of a spell (1) or not (0)
					int whichMonsterWasHit[numberOfHeroes];		// for every hero; get which monster he attacked with spell (positions of an array: [0,1,2] for example)
					for(int k = 0; k < numberOfHeroes; k++){
						checkLifeOfSpell[k] = 0;
						monsterHitWithSpell[k] = 0;
						whichMonsterWasHit[k] = 0;
					}
					int returnFromAttackWithSpell = 0;
					int getOutOfdoWhileLoop = 0;
					displayStats(Heroes,Monsters,numberOfHeroes);

					do{
						cout<<"<-------------------ROUND "<<counter<<"------------------->"<<endl;		// round of battle (round = heroes do something + monsters do something)
						for(i=0;i<numberOfHeroes;i++){	// for every hero for every round what do you want to do
							/*if hero is alive*/
							if (!Heroes[i]->isAlive()){
								cout << "Hero " << i+1 << " is dead." << endl;
								continue;
							}
							
							getOutOfdoWhileLoop=0;
							do{
								/*HEROES' TURN*/
								//print options
								cout<<"For hero " << i+1 << ":"<<endl;
								cout<<"If you want to check the inventory press 1"<<endl;
								cout<<"If you want to start the Attack press 2"<<endl;
								 
								cin>>option;
					
								while((option!=1 && option!=2) || cin.fail()){ //check
									if(cin.fail()){ // or if(!cin)
									    // user didn't input a number
									    cin.clear(); // reset failbit
									    cin.ignore(100, '\n'); //skip bad input
										cout<<"Give a valid option."<<endl;
									    cin>>option;
									}
									else{	
										cout<<"Give a valid option."<<endl;
									    cin>>option;
									}
								}
								switch(option){
									case 1:
										    check = Heroes[i]->inventory.checkInventory(*Heroes[i],inBattle); //checkInventory for the current hero
											
											if(check == 2){
												getOutOfdoWhileLoop = returnFromAttackWithSpell = 0;
												break;
											}
											else if(check == 1){
												getOutOfdoWhileLoop=1;
												break;
											}

									case 2: cout << "Attack of Hero " << i+1 << endl;
											if(Heroes[i]->MySpell!=nullptr){
												cout << "A spell is equiped" << endl;
												if(!Heroes[i]->MySpell->getInUse(i)){
													returnFromAttackWithSpell=attackWithSpell(*Heroes[i],Monsters,numberOfHeroes,monsterHitWithSpell,i,whichMonsterWasHit);
													if(returnFromAttackWithSpell==0){
														cout << "For hero " << i+1 << ":" << endl;
														cout << "If you want to check the inventory press 1" << endl;
														cout << "If you want to start the Attack press 2" << endl;
														cin >> option;
														while((option!=1 && option!=2)|| cin.fail()){
															if(cin.fail()){ // or if(!cin)
															    // user didn't input a number
															    cin.clear(); // reset failbit
															    cin.ignore(100, '\n'); //skip bad input
																cout << "Give a valid option." << endl;
															    cin >> option;
															}
															else{
																cout << "Give a valid option." << endl;
															    cin >> option;
															}
														}
														Heroes[i]->MySpell=nullptr;	
														break;
													} else if (returnFromAttackWithSpell == -1) { break; }
													checkLifeOfSpell[i]=counter+returnFromAttackWithSpell;
												}
												else {
													getOutOfdoWhileLoop=1;
													attack(*Heroes[i],Monsters,numberOfHeroes); //attack with the current hero
												}
											}
											else{
												getOutOfdoWhileLoop=1;
												attack(*Heroes[i],Monsters,numberOfHeroes); //attack with the current hero
											}
											
								}
							}while(returnFromAttackWithSpell == 0 && getOutOfdoWhileLoop == 0);
						}

						if(!monstersAreDead(Monsters,numberOfHeroes))
							break;

						/*MONSTERS' TURN*/
						for(i=0;i<numberOfHeroes;i++){
							//////////////////////////////////////////////////////////////////////check if hero is dead
							int whoToHit=rand()%numberOfHeroes; //generate a random number between 0-2 to choose the hero
							/*probability(agility) for hero to avoid an attack from a monster*/
							if(((double) Heroes[whoToHit]->getAgility()/Heroes[whoToHit]->getMaxAgility())>((double) rand() / (RAND_MAX))){
								cout << "Hero " << whoToHit+1 << " avoid the attack!" << endl;
								continue;	// next monster please...
							}
							Heroes[whoToHit]->attackToHero(Monsters[i]->generateHit()); //hit the chosen hero
						}	
						displayStats(Heroes,Monsters,numberOfHeroes);
						
						monstersAfterRound(Monsters,numberOfHeroes);
						heroesAfterRound(Heroes,numberOfHeroes);
						
						counter++;
						endOfSpell(Heroes,Monsters,numberOfHeroes,checkLifeOfSpell,monsterHitWithSpell,counter,whichMonsterWasHit);
					}while(monstersAreDead(Monsters,numberOfHeroes) && heroesAreDead(Heroes,numberOfHeroes)); //while all heroes or all monsters die
					inBattle = 0;
					getchar();
					getchar();

					/*heroesAreDead returns life of heroes (if it is 0, monsters won)*/
					if(!heroesAreDead(Heroes,numberOfHeroes)){
						cout<<"The monsters won!!!!"<<endl;
						cout<<"Press enter to continue...!!"<<endl;
						getchar();
						heroesAfterLosing(Heroes,numberOfHeroes);
					}

					/*monstersAreDead returns life of monsters (if it is 0, heroes won)*/
					if(!monstersAreDead(Monsters,numberOfHeroes)){
						cout<<"The heroes won!!!!"<<endl;
						cout<<"Press enter to continue...!!"<<endl;
						getchar();
						heroesAfterWinning(Heroes,numberOfHeroes);
					}

					destroyMonsters(Monsters,numberOfHeroes);
					battle=0;
					break;
				}
			default:
				break;
		}
		g->clearScreen();

	} while (keyInput != 'q');	

	/*memory frees*/
	/*delete heroes*/
	for (int i = 0; i < numberOfHeroes; ++i)
		delete Heroes[i];
	delete[] Heroes;
	
	/*delete grid*/
	delete g;
}

void Game::endOfSpell(Hero**&heroes,Monster**&monsters,int NumberOfHeroes,int*const&checkLifeOfSpell,int*const&monsterHitWithSpell,int counter,int*const&whichMonsterWasHit){
	for(int i=0;i<NumberOfHeroes;i++){		
		if(heroes[i]->MySpell!=nullptr)
			if(heroes[i]->MySpell->getInUse(i))
				if(counter==checkLifeOfSpell[i]){
					cout<<"End of spell for hero "<<i<<endl;/////////////////////
					if (monsterHitWithSpell[whichMonsterWasHit[i]]==1){
						heroes[i]->MySpell->undoSpell(*monsters[whichMonsterWasHit[i]]);
						monsterHitWithSpell[whichMonsterWasHit[i]] = 0;
					}
					heroes[i]->MySpell->setInUse0(i);
					heroes[i]->MySpell=nullptr;
				}
			
	}
}
/*heroesAfterWinning*/
void Game::heroesAfterWinning(Hero**& heroes,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		heroes[i]->increaseMoney(heroes[i]->getLevel()*4+NumberOfHeroes*2);
		if (heroes[i]->getLevel() < 10){				// otan ftasei level 10 no more experience kai mhn elegxeis kan gia level up
			heroes[i]->increaseExperience(heroes[i]->getLevel()*3+NumberOfHeroes*3);
			if(heroes[i]->checkIfLevelUp())
				heroes[i]->levelUp();
		}
	}

}

/*heroesAfterRound*/
void Game::heroesAfterRound(Hero**&heroes,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		if(heroes[i]->isAlive()){
			heroes[i]->regenerateHealthPowerAfterRound();
			heroes[i]->regenerateMagicPowerAfterRound();
		}
	}
}

/*monstersAfterRound*/
void Game::monstersAfterRound(Monster**&monsters,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		if (monsters[i]->isAlive())
			monsters[i]->regenerateHealthPowerAfterRound();
	}
}

/*destroyMonsters*/
void Game::destroyMonsters(Monster**& monsters,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		delete monsters[i];
		monsters[i]=nullptr;
	}
	delete[] monsters;
	monsters=nullptr;
}

/*heroesAfterLosing*/
void Game::heroesAfterLosing(Hero**& heroes,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		heroes[i]->reduceMoneyAfterLosing();
		if(heroes[i]->getCurrHealthPower()==0)
			heroes[i]->regenerateHealthPowerAfterLosing();
	}
}

/*monstersAreDead*/
int Game::monstersAreDead(Monster**&monsters,int NumberOfHeroes){
	int life=0;
	for(int i=0;i<NumberOfHeroes;i++){ //for every monster
		life += monsters[i]->getCurrHealthPower(); //add the health
	}
	return life; //return 0 if all monsters are dead else != 0
}

/*heroesAreDead*/
int Game::heroesAreDead(Hero**&heroes,int NumberOfHeroes){
	int life=0;
	for(int i=0;i<NumberOfHeroes;i++){ //for every monster
		life += heroes[i]->getCurrHealthPower(); //add the health
	}
	return life; //return 0 if all monsters are dead else != 0
}

/*attack*/
void Game::attack(Hero& hero,Monster**& monsters,int NumberOfHeroes){
	int option;
		cout<<" to Monster: (give a number between 1-"<<NumberOfHeroes<<")"<<endl;
		cin>>option;

		while(option<1 || option>NumberOfHeroes || monsters[option-1]->getCurrHealthPower()==0 || cin.fail()){
			if(cin.fail()){
				 // user didn't input a number
			    cin.clear(); // reset failbit
			    cin.ignore(100, '\n'); //skip bad input
				cout << "Give a valid option." << endl;
			    cin >> option;
			}
			else if(option<1 || option>NumberOfHeroes){
				cout<<"Wrong input please give a number between 1-"<<NumberOfHeroes<<")"<<endl;	
				cin>>option;
			}
			else if(!monstersAreDead(monsters,NumberOfHeroes))
				return;
			else if(monsters[option-1]->getCurrHealthPower()==0){
				cout<<"This monster has no life. Choose another one."<<endl;
				cin>>option;
			}
		}

		/*Probability for monster to avoid a normal attack from hero*/
		if(((double) monsters[option-1]->getProbability()/monsters[option-1]->getMaxProbability())>((double) rand() / RAND_MAX)){
			cout << "Monster " << option << " avoid the attack!" << endl;
			return;
		}

		if(hero.Lhand==hero.Rhand && hero.Rhand!=nullptr)
			monsters[option-1]->attackToMonster(hero.Rhand->getDamageValue()+hero.getStrength()); 
		else if(hero.Lhand==nullptr && hero.Rhand==nullptr)			
			monsters[option-1]->attackToMonster(hero.getStrength());
		else if (hero.Lhand!=nullptr && hero.Rhand!=nullptr)
			monsters[option-1]->attackToMonster(hero.Rhand->getDamageValue()+hero.Lhand->getDamageValue()+hero.getStrength());
		else if(hero.Rhand==nullptr)
			monsters[option-1]->attackToMonster(hero.Lhand->getDamageValue()+hero.getStrength());	
		else
			monsters[option-1]->attackToMonster(hero.Rhand->getDamageValue()+hero.getStrength());
		
}


/*attackWithSpell*/
int Game::attackWithSpell(Hero& hero,Monster**& monsters,int NumberOfHeroes,int*const& monsterHitWithSpell,int whoHitTheMonster,int*const&whichMonsterWasHit){
	cout<<"Attack with spell"<<endl;//////////////////////////////
	if(!hero.reduceMagicPower(hero.MySpell->getMagicPower())){
		cout << "Your magic power is not enough... Better luck next time!" << endl;
		hero.MySpell=nullptr;
		return 0;
	}
	hero.MySpell->setInUse1(whoHitTheMonster);
	//check if magicPower of hero goes bellow 0
	int option;
		cout<<" to Monster: (give a number between 1-"<<NumberOfHeroes<<")"<<endl;
		cin>>option;

		while(option<1 || option>NumberOfHeroes || monsters[option-1]->getCurrHealthPower()==0 || monsterHitWithSpell[option-1]!=0 || cin.fail()){
			if(cin.fail()){
				 // user didn't input a number
			    cin.clear(); // reset failbit
			    cin.ignore(100, '\n'); //skip bad input
				cout << "Give a valid option." << endl;
			    cin >> option;
			}
			else if(option<1 || option>NumberOfHeroes){
				cout<<"Wrong input please give a number between 1-"<<NumberOfHeroes<<")"<<endl;	
				cin>>option;
			}
			else if(monsters[option-1]->getCurrHealthPower()==0){
				cout<<"This monster has no life. Choose another one."<<endl;
				cin>>option;
			}
			else if(monsterHitWithSpell[option-1]!=0){
				cout<<"The monster you chose has already been hit by a spell, please choose another one or press 0 to exit attack with spell."<<endl;
				cin>>option;
				if(option==0){
					hero.MySpell->setInUse0(whoHitTheMonster);
					return 0;
				}
			}
		}

		/*Probability for monster to avoid a spell attack from hero*/
		if(((double) monsters[option-1]->getProbability()/monsters[option-1]->getMaxProbability())>((double) rand() / RAND_MAX)){
			cout << "Monster " << option << " avoid the attack!" << endl;
			hero.MySpell->setInUse0(whoHitTheMonster);
			return -1;
		}

		whichMonsterWasHit[whoHitTheMonster]=option-1;
		monsterHitWithSpell[option-1]=1;
		//monsters[option-1]->attackToMonster(100);
		monsters[option-1]->attackToMonster(hero.MySpell->generateHit(hero.getDexterity()));  
		hero.MySpell->castSpell(*monsters[option-1]);
		return hero.MySpell->getImpactForNRounds();	
}


/*getAverageLevelOfHeroes*/
int Game::getAverageLevelOfHeroes(Hero**& heroes,int NumberOfHeroes){
	int averageLevel=0;
	for(int i=0;i<NumberOfHeroes;i++){
		averageLevel += heroes[i]->getLevel();
	}
	return averageLevel/NumberOfHeroes;
}

/*displayStats*/
void Game::displayStats(Hero**& heroes, Monster**& monsters,int NumberOfHeroes){
	for(int i=0;i<NumberOfHeroes;i++){
		cout << "Name: "<< heroes[i]->getName(); cout<<'\t'<<'\t'<<"Name: "<< monsters[i]->getName(); cout<<endl;
		cout << "Level: "<< heroes[i]->getLevel(); cout<<'\t'<<'\t'<< "Level: "<< monsters[i]->getLevel(); cout<<endl;
		cout << "HP: "<<heroes[i]->getCurrHealthPower(); cout<< "/"<< heroes[i]->getMaxHealthPower(); cout<<'\t'<<'\t'<<"HP: "<< monsters[i]->getCurrHealthPower(); cout<< "/"<<monsters[i]->getMaxHealthPower(); cout<<endl;
		cout << "MP: "<< heroes[i]->getCurrMagicPower(); cout<< "/"<<heroes[i]->getMaxMagicPower(); cout<<'\t'<<'\t'<<"DamageRange: "<< monsters[i]->getMinDamageRange(); cout<< "-"<< monsters[i]->getMaxDamageRange(); cout<<endl;
		cout << "Dexterity: "<<heroes[i]->getDexterity(); cout<<'\t'<<'\t'<<"Probability: "<< monsters[i]->getProbability(); cout<<endl;
		cout << "Agility: "<< heroes[i]->getAgility(); cout<<'\t'<<'\t'<<"Defense: "<<monsters[i]->getDefense(); cout<<endl;
		cout << "Strength: "<< heroes[i]->getStrength(); cout<< endl; // cout<<'\t'<<'\t'<<
		
		if(heroes[i]->MyArmor!=nullptr){
			cout << "Armor: " << heroes[i]->MyArmor->getDamageSave();cout<<endl; /////////attention
		}
		
		if(heroes[i]->Lhand==heroes[i]->Rhand && heroes[i]->Rhand!=nullptr)
			cout << "Weapon's damage: " << heroes[i]->Rhand->getDamageValue()<<endl<<endl; 
		else if(heroes[i]->Lhand==nullptr && heroes[i]->Rhand==nullptr)
			cout << "Both hands are empty." << endl<<endl;
		else if(heroes[i]->Lhand!=nullptr && heroes[i]->Rhand!=nullptr){
			cout << "Right hand->weapon's damage:"<<heroes[i]->Rhand->getDamageValue()<<endl<<endl;
			cout << "Left hand->weapon's damage:"<<heroes[i]->Lhand->getDamageValue()<<endl<<endl;
		}
		else if(heroes[i]->Rhand==nullptr)
			cout << "Left hand->weapon's damage:"<<heroes[i]->Lhand->getDamageValue()<<endl<<endl;
		else
			cout << "Right hand->weapon's damage:"<<heroes[i]->Rhand->getDamageValue()<<endl<<endl;
	}
}
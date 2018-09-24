#ifndef WOW_HEADER_
#define WOW_HEADER_

#include <iostream>
#include <string>

using namespace std;

enum enumType{
	DRAGON = 0,
	NINJA = 1,
	ICEMAN = 2,
	LION = 3,
	WOLF = 4,
};

class Warrior{
private:
	int idNumber;
	enumType warriorType;
	int healthPoint;
	int aggressivity;
public:
	Warrior(int idN, enumType wT, int hP, int ag=0){
		idNumber = idN;
		warriorType = wT;
		healthPoint = hP;
		aggressivity = ag;
	}
	void setHealthPoint(int a){
		healthPoint = a;
	}
	int getHealthPoint(){
		return healthPoint;
	}
	void setIdNumber(int a){
		idNumber = a;
	}
	int getIdNumber(){
		return idNumber;
	}
	void setAggressivity(int a){
		aggressivity = a;
	}
	int getAggressivity(){
		return aggressivity;
	}
	void setWarriorType(enumType a){
		warriorType = a;
	}
	enumType& getWarriorType(){
		return warriorType;
	}
	virtual int getOneKindWarriorCnt();
};

class Dragon : public Warrior{
public:
	static int dragonCnt;
public:
	Dragon(int idN, enumType wT, int hP, int ag=0):Warrior(idN, wT, hP, ag){dragonCnt++;}
	~Dragon(){dragonCnt--;}
	int getOneKindWarriorCnt(){
		return dragonCnt;
	}
};

class Ninja : public Warrior{
public:
	static int ninjaCnt;
public:
	Ninja(int idN, enumType wT, int hP, int ag=0):Warrior(idN, wT, hP, ag){ninjaCnt++;}
	~Ninja(){ninjaCnt--;}
	int getOneKindWarriorCnt(){
		return ninjaCnt;
	}
};

class Lion : public Warrior{
public:
	static int lionCnt;
public:
	Lion(int idN, enumType wT, int hP, int ag=0):Warrior(idN, wT, hP, ag){lionCnt++;}
	~Lion(){lionCnt--;}
	int getOneKindWarriorCnt(){
		return lionCnt;
	}
};

class Wolf : public Warrior{
public:
	static int wolfCnt;
public:
	Lion(int idN, enumType wT, int hP, int ag=0):Warrior(idN, wT, hP, ag){wolfCnt++;}
	~Lion(){wolfCnt--;}
	int getOneKindWarriorCnt(){
		return wolfCnt;
	}
};

class Iceman : public Warrior{
public:
	static int icemanlife;
public:
	Ninja(int idN, enumType wT, int hP, int ag=0):Warrior(idN, wT, hP, ag){icemanlife++;}
	~Ninja(){icemanlife--;}
	int getOneKindWarriorCnt(){
		return icemanlife;
	}
};

class Headquarters{
private:
	int lifeElement;
	vector<Warrior&> warriorVector;
	int nextCreateWarrior;
	bool failureFlag;
public:
	static int dragonlife;
	static int ninjalife;
	static int icemanlife;
	static int lionlife;
	static int wolflife;
private:
	int warriorCnt;
public:
	Headquarters():lifeElement(0),nextCreateWarrior(0),failureFlag(false),warriorCnt(0){}
	virtual bool triggerCreateNewWarrior();
	void setLifeElement(int a){
		lifeElement = a;
	}
	int getLifeElement(){
		return lifeElement;
	}
	int getNextCreateWarrior(){
		return nextCreateWarrior;
	}
	void updateNextCreateWarrior(int idx){
		nextCreateWarrior = idx%5;
	}
	void warriorCntAddOne(){
		warriorCnt++;
	}
	//void warriorCntMinusOne(){
	//	warriorCnt--;
	//}
	int getWarriorCnt(){
		return warriorCnt;
	}
};

class RedArmyHeadquarters : public Headquarters{
public:
	RedArmy(){}
	void printInfo(Warrior& war, enumType eT){
		int initLifeArray[] = {icemanlife, lionlife, wolflife, ninjalife, dragonlife};
		string name[] = {"iceman","lion","wolf","ninja","dragon"};
		cout.width(3);
		cout.fill('0');
		cout << getTimeticks();
		cout << " red " << name[eT] << " " << getWarriorCnt() 
			<< " born with strength " << initLifeArray[eT] << ", " 
			<< war.getOneKindWarriorCnt() <<" " << name[eT] << " in red headquarter" << endl;
	}
	bool triggerCreateNewWarrior(){
		int initLifeArray[] = {icemanlife, lionlife, wolflife, ninjalife, dragonlife};
		int lifeElement = getLifeElement();
		bool rtnFlag = false;
		int validIdx = 0;
		for(int idx = getNextCreateWarrior(); idx < 5; idx++){
			if(lifeElement - initLifeArray[idx] >= 0){
				validIdx = idx;
				rtnFlag = true;
				break;
			}
		}
		for(int idx = 0; rtnFlag == false && idx < getNextCreateWarrior(); idx++)
		{
			if(lifeElement - initLifeArray[idx] >= 0){
				validIdx = idx;
				rtnFlag = true;
				break;
			}
		}
		if (rtnFlag == true){
			switch (validIdx){
				case 0:
					Iceman iceman(getWarriorCnt(), ICEMAN, icemanlife);
					printInfo(iceman, ICEMAN);
					break;
				case 1:
					Lion lion(getWarriorCnt(), LION, lionlife);
					printInfo(lion, LION);
					break;
				case 2:
					Wolf wolf(getWarriorCnt(), WOLF, wolflife);
					printInfo(wolf, WOLF);
					break;
				case 3:
					Ninja ninja(getWarriorCnt(), NINJA, ninjalife);
					printInfo(ninja, NINJA);
					break;
				case 4:
					Dragon dragon(getWarriorCnt(), DRAGON, dragonlife);
					printInfo(dragon, DRAGON);
					break;
				default:
					cout << "triggerCreateNewWarrior has some bugs here" << endl;
					break;
			}
			updateTimeticks();
			updateNextCreateWarrior(validIdx+1);
			warriorCntAddOne();
			setLifeElement(lifeElement - initLifeArray[validIdx]);
		}
		else{
			cout.width(3);
			cout.fill('0');
			cout << getTimeticks();
			cout << " red headquarter stops making warriors" << endl;
		}
		return rtnFlag;
	}
private:
	static int timeticks;
	void updateTimeticks(){
		timeticks++;
	}
	int getTimeticks(){
		return timeticks;
	}
};

class BlueArmyHeadquarters : public Headquarters{
public:
	bool triggerCreateNewWarrior();
private:
		static int timeticks;
};


#endif


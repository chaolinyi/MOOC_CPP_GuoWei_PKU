#include <iostream> 
#include <stdio.h> 
#include <string.h>

using namespace std; 
#define WARRIOR_NUM 5 

class CHead; 
class CWarrior 
{ 
  private: 
    CHead * pHead; 
    int kindNo; // 0 dragon 1 ninja 2 iceman 3 lion 4 wolf 
    int nNo; 
  public: 
    static char * names[WARRIOR_NUM]; 
    static int InitialLifeValue [WARRIOR_NUM]; 
    CWarrior( CHead * p,int nNo_,int kindNo_ ); 
    void PrintResult(int nTime); 
}; 
class CHead 
{ 
  private: 
    int totalLifeValue; 
    bool bStopped; 
    int totalWarriorNum; 
    int color; 
    int curMakingSeqIdx;  
    int warriorNum[WARRIOR_NUM]; 
    CWarrior * pWarriors[1000]; 
  public: 
    friend class CWarrior; 
    static int makingSeq[2][WARRIOR_NUM]; 
    void Init(int color_, int lv); 
    ~CHead () ; 
    int Produce(int nTime); 
    void GetColor( char * szColor); 
 
}; 
CWarrior::CWarrior(  CHead  *  p,int  nNo_,int 
kindNo_ ):nNo(nNo_),kindNo(kindNo_),pHead(p) {  } 
void CWarrior::PrintResult(int nTime)  
{   
    char szColor[20]; 
    pHead->GetColor(szColor); 
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"
  , 
        nTime, szColor, names[kindNo], nNo, InitialLifeValue[kindNo], 
        pHead->warriorNum[kindNo],names[kindNo],szColor); 
} 
void CHead::Init(int color_, int lv) 
{ 
  color = color_; 
  totalLifeValue = lv; 
  totalWarriorNum = 0; 
  bStopped = false; 
  curMakingSeqIdx = 0; 
  for( int i = 0;i < WARRIOR_NUM;i ++ ) 
    warriorNum[i] = 0; 
} 
CHead::~CHead () { 
  for( int i = 0;i < totalWarriorNum;i ++ ) 
    delete pWarriors[i]; 
} 
int CHead::Produce(int nTime) 
{ 
   
  if( bStopped ) 
    return 0; 
  int nSearchingTimes = 0; 
  while(  CWarrior::InitialLifeValue[makingSeq[color][curMakingSeqIdx]]  > 
totalLifeValue &&  
    nSearchingTimes < WARRIOR_NUM ) { 
    curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM ; 
    nSearchingTimes ++; 
  } 
  int kindNo = makingSeq[color][curMakingSeqIdx]; 
  if( CWarrior::InitialLifeValue[kindNo] > totalLifeValue ) { 
    bStopped = true; 
    if( color == 0) 
      printf("%03d red headquarter stops making warriors\n",nTime); 
    else 
      printf("%03d blue headquarter stops making warriors\n",nTime); 
    return 0; 
  } 
  totalLifeValue -= CWarrior::InitialLifeValue[kindNo]; 
  curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM ; 
  pWarriors[totalWarriorNum] = new CWarrior( this,totalWarriorNum+1,kindNo); 
  warriorNum[kindNo]++; 
  pWarriors[totalWarriorNum]->PrintResult(nTime); 
  totalWarriorNum ++; 
  return 1; 
} 
void CHead::GetColor( char * szColor) 
{ 
  if( color == 0) 
    strcpy(szColor,"red"); 
  else 
    strcpy(szColor,"blue"); 
} 
 
char * CWarrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" }; 
int CWarrior::InitialLifeValue [WARRIOR_NUM]; 
int CHead::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} };
 
int main() 
{ 
  int t; 
  int m; 
  CHead RedHead,BlueHead; 
  scanf("%d",&t); 
  int nCaseNo = 1; 
  while ( t -- ) { 
    printf("Case:%d\n",nCaseNo++); 
    scanf("%d",&m); 
    for( int i = 0;i < WARRIOR_NUM;i ++ ) 
      scanf("%d", & CWarrior::InitialLifeValue[i]);  
    RedHead.Init(0,m); 
    BlueHead.Init(1,m); 
    int nTime = 0; 
    while( true) { 
      int tmp1 = RedHead.Produce(nTime);  
      int tmp2 = BlueHead.Produce(nTime); 
      if( tmp1 == 0 && tmp2 == 0) 
        break; 
      nTime ++; 
    } 
  } 
  return 0; 
} 
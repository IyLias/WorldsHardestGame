#include "Pattern.h"
#include <assert.h>

using namespace std;

class PatternSet{

 private:
  vector<Pattern> patternSet;

  int patternNum; // total number of patterns

 public:

  PatternSet(){}

  PatternSet(int patNum){
    patternNum = patNum;

  }

  void setPatternNum(int pNum){
     patternNum = pNum;
  }

  int getPatternNum() { return patternNum;}

  void addMotion(Pattern pattern){
     patternSet.push_back(pattern);
  }

  Pattern getCurPattern(int cur){
    
    assert(cur <= patternNum-1);    

    return patternSet[cur];
  }



};

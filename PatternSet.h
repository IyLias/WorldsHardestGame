#include "Pattern.h"



class PatternSet{

 public:

  PatternSet(int patNum){
    patternNum = patNum;

  }

  int getPatternNum() { return patternNum;}

 private:
  
   vector<Pattern> patternSet;	 

   int patternNum; // number of total patterns

};

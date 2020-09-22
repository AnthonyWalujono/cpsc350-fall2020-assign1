#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#define PI 3.14159265
using namespace std;
int main() {
  string fileName;
  string dnaString;
  int sum = 0;
  int totalDnaStr = 0;
  double mean;
  //Nucleotide Counters
  int aCount = 0;
  int cCount = 0;
  int tCount = 0;
  int gCount = 0;
  int totalNucle = 0;
  //Nucleotide Probabilities
  double aProb, cProb, tProb, gProb;
  //Bigram Counters
  int aaCount = 0;
  int acCount = 0;
  int atCount = 0;
  int agCount = 0;
  int caCount = 0;
  int ccCount = 0;
  int ctCount = 0;
  int cgCount = 0;
  int taCount = 0;
  int tcCount = 0;
  int ttCount = 0;
  int tgCount = 0;
  int gaCount = 0;
  int gcCount = 0;
  int gtCount = 0;
  int ggCount = 0;
  int totalBigram = 0;
  // Bigram Probabilities
  double aaProb, acProb, atProb, agProb;
  double caProb, ccProb, ctProb, cgProb;
  double taProb, tcProb, ttProb, tgProb;
  double gaProb, gcProb, gtProb, ggProb;
  bool processCont = true;
  string userAnswer;
  double variance, stdDev;
  //variables for random number
  double a, b, c, d;
  //for new DNA Strings
  string aString, cString, tString, gString, actgString;
  ifstream inputFile;
  ofstream outputFile;
  while(processCont){
    cout << "Please enter a file name." << endl;
    cin >> fileName;
    inputFile.open(fileName);
    //Check if the file exists
    if(inputFile.fail()) {
      cout << "File not Does not exists \n";
      exit (1);
    }
    outputFile.open("anthony.txt");
  while(getline(inputFile, dnaString)){
    if(dnaString.length() != 0){
      totalDnaStr++;
      sum += dnaString.length();
      //Counts the individual Nucleotide
      for (int i = 0; i < dnaString.length(); i++) {
        if (dnaString.at(i) == 'A'){
          totalNucle++;
          aCount++;
        }
        else if (dnaString.at(i) == 'C'){
          totalNucle++;
          cCount++;
        }
        else if (dnaString.at(i) == 'T'){
          totalNucle++;
          tCount++;
        }
        else if (dnaString.at(i) == 'G'){
          totalNucle++;
          gCount++;
        }
      }
      //Counts individual nucleotide bigram
      for(int i = 0; i < dnaString.length(); i+=2) {
        if(dnaString.at(i) == 'A' && dnaString.at(i+1) == 'A'){
          totalBigram++;
          aaCount++;
        }
        else if(dnaString.at(i) == 'A' && dnaString.at(i+1) == 'C'){
          totalBigram++;
          acCount++;
        }
        else if(dnaString.at(i) == 'A' && dnaString.at(i+1) == 'T'){
          totalBigram++;
          atCount++;
        }
        else if(dnaString.at(i) == 'A' && dnaString.at(i+1) == 'G'){
          totalBigram++;
          agCount++;
        }
        if(dnaString.at(i) == 'C' && dnaString.at(i+1) == 'A'){
          totalBigram++;
          caCount++;
        }
        else if(dnaString.at(i) == 'C' && dnaString.at(i+1) == 'C'){
          totalBigram++;
          ccCount++;
        }
        else if(dnaString.at(i) == 'C' && dnaString.at(i+1) == 'T'){
          totalBigram++;
          ctCount++;
        }
        else if(dnaString.at(i) == 'C' && dnaString.at(i+1) == 'G'){
          totalBigram++;
          cgCount++;
        }
        if(dnaString.at(i) == 'T' && dnaString.at(i+1) == 'A'){
          totalBigram++;
          taCount++;
        }
        else if(dnaString.at(i) == 'T' && dnaString.at(i+1) == 'C'){
          totalBigram++;
          tcCount++;
        }
        else if(dnaString.at(i) == 'T' && dnaString.at(i+1) == 'T'){
          totalBigram++;
          ttCount++;
        }
        else if(dnaString.at(i) == 'T' && dnaString.at(i+1) == 'G'){
          totalBigram++;
          tgCount++;
        }
        if(dnaString.at(i) == 'G' && dnaString.at(i+1) == 'A'){
          totalBigram++;
          gaCount++;
        }
        else if(dnaString.at(i) == 'G' && dnaString.at(i+1) == 'C'){
          totalBigram++;
          gcCount++;
        }
        else if(dnaString.at(i) == 'G' && dnaString.at(i+1) == 'T'){
          totalBigram++;
          gtCount++;
        }
        else if(dnaString.at(i) == 'G' && dnaString.at(i+1) == 'G'){
          totalBigram++;
          ggCount++;
        }
      }
    }
  }
  inputFile.close();
  inputFile.open(fileName);
  mean = (double)sum/totalDnaStr;
  //Process to find the Standard Deviation and Variance
  while(getline(inputFile, dnaString)){
    variance += pow(double(dnaString.length() - mean), 2.0);
  }
  variance = variance/4.0;
  outputFile << "Variance: " << variance << endl;
  stdDev = sqrt(variance);
  outputFile << fixed;
  outputFile << setprecision(1);
  outputFile << "Standard Deviation: " << stdDev << endl;
  a = (double)rand();
  b = (double)rand();
  c = sqrt(2 * log(a)) * cos(2 * PI * b);
  d = (stdDev * c ) + mean;
  //Calculations for nucleotide probabilities
  aProb = (double)aCount/totalNucle;
  cProb = (double)cCount/totalNucle;
  tProb = (double)tCount/totalNucle;
  gProb = (double)gCount/totalNucle;
  //Calculations for bigram probabilities
  aaProb = (double)aaCount/totalBigram;
  acProb = (double)acCount/totalBigram;
  atProb = (double)atCount/totalBigram;
  agProb = (double)agCount/totalBigram;
  caProb = (double)caCount/totalBigram;
  ccProb = (double)ccCount/totalBigram;
  ctProb = (double)ctCount/totalBigram;
  cgProb = (double)cgCount/totalBigram;
  taProb = (double)taCount/totalBigram;
  tcProb = (double)tcCount/totalBigram;
  ttProb = (double)ttCount/totalBigram;
  tgProb = (double)tgCount/totalBigram;
  gaProb = (double)gaCount/totalBigram;
  gcProb = (double)gcCount/totalBigram;
  gtProb = (double)gtCount/totalBigram;
  ggProb = (double)ggCount/totalBigram;
  //Prints out the String, Sum, and Mean
  outputFile << "Total DNA String = " << totalDnaStr;
  outputFile << "\nSum: " << sum;
  outputFile << fixed;
  outputFile << setprecision(1);
  outputFile << "\nMean: " << mean;
  //Prints probability for each nucleotide
  outputFile << fixed;
  outputFile << setprecision(2);
  outputFile << "\nProbability of each Nucleotide: ";
  outputFile << "\nA: " << aProb;
  outputFile << "\nC: " << cProb;
  outputFile << "\nT: " << tProb;
  outputFile << "\nG: " << gProb;
  //Prints probability for each Bigram
  outputFile << fixed;
  outputFile << setprecision(4);
  outputFile << "\nProbability of each Bigram: ";
  outputFile << "\nAA: " << aaProb;
  outputFile << "\nAC: " << acProb;
  outputFile << "\nAT: " << atProb;
  outputFile << "\nAG: " << agProb;
  outputFile << "\nCA: " << caProb;
  outputFile << "\nCC: " << ccProb;
  outputFile << "\nCT: " << ctProb;
  outputFile << "\nCG: " << cgProb;
  outputFile << "\nTA: " << taProb;
  outputFile << "\nTC: " << tcProb;
  outputFile << "\nTT: " << ttProb;
  outputFile << "\nTG: " << tgProb;
  outputFile << "\nGA: " << gaProb;
  outputFile << "\nGC: " << gcProb;
  outputFile << "\nGT: " << gtProb;
  outputFile << "\nGG: " << ggProb;
  //For Loops to create the Strings based on Nucleotides
  for(int i = 0; i < (int)(aProb * d); i++){
    aString += "A";
  }
  for(int i = 0; i < (int)(cProb * d); i++){
    cString += "C";
  }
  for(int i = 0; i < (int)(tProb * d); i++){
    tString += "T";
  }
  for(int i = 0; i < (int)(gProb * d); i++){
    gString += "G";
  }
  actgString = aString + cString + gString + tString;
  outputFile << "\nACTG String: " << endl;
  //Print new DNA Strings 1000 times
  for(int j = 0; j < 1000; j++){
    outputFile << actgString << endl;
  }
  inputFile.close();
  //Ask user if they want to process another file
  cout << "Do you want to process another file? (Y/N)" << endl;
  cin >> userAnswer;
  if (userAnswer.compare("y") == 0 || userAnswer.compare("Y") == 0
      || userAnswer.compare("Yes") == 0 || userAnswer.compare("yes") == 0) {
    processCont = true;
  }
  else {
    processCont = false;
  }
}
  outputFile.close();
  return 0;
}

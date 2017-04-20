//Gezim Saciri & Ben Liepert
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dict.h"
#include "movie.h"
#include <sys/time.h>

using namespace std;

void randomizeFile(string iFile, string oFile){
  //===========================================
  // count lines in original file
  ifstream inputFile1(iFile);
  if (!inputFile1.is_open()){
    cout << "Could not open input file (1), exiting.\n";
    exit(1);
  }
  string line1;
  int numLines = 0;
  while (getline(inputFile1, line1)){
    numLines++;
  }
  //===========================================
  // for every line, pick a random number between 1 and #lines,
  // take this line in the original and write it to the randomized file
  ofstream outputFile(oFile, ios_base::app); //we want to append to existing file
  if (!outputFile.is_open()){
    cout << "Could not open output file, exiting.\n";
    exit(1);
  }
  vector<int> visited;
  int randomLine = 0;
  for(int i = 0; i < numLines; i++){ // for every line
    bool getNewRandom = true;
    // while we need a new random number
    while(getNewRandom){
      randomLine = rand() % numLines; //pick one
      getNewRandom = false;
      // make sure it's not in our vector
      for (int j = 0; j < visited.size(); j++){
        if(visited[j] == randomLine){
          getNewRandom = true;
          break;
        }
      }
      //if getNewRandom is still false, we got a unique random #
    }
    visited.push_back(randomLine); //put the number in our vector bc we're using it
    int count = 0;
    string line;
    ifstream inputFile;
    inputFile.open(iFile); //open the input file from the top
    while(getline(inputFile, line)){ //iterate over every line in orig. file
      if(count == randomLine){ //if out random # matches current line #
        outputFile << line << '\n'; //write to randomized file
        break; //break so we don't go over all the other lines
      }
      count++; //increment line #
    }
  }
}

int main(){
  //randomizeFile("movies_mpaa.txt", "movies_mpaa_random.txt");

  //used this for testing timing

  double timeCount = 0.0;
  for (int i = 0; i < 100; i++){
    timeval timeBefore, timeAfter;
    long diffSeconds, diffUSeconds;
    ifstream inputFile("words");
    string line;
    //int iTabIndex;
    Dictionary<Movie> dict;
    gettimeofday(&timeBefore, NULL);
    while (getline(inputFile, line)){
      //iTabIndex = line.find('\t');
      Movie *m = new Movie;
      m->title = line;//line.substr(0,iTabIndex);
      //m->cast = line.substr(iTabIndex+1);
      dict.insert(m);
    }
    gettimeofday(&timeAfter, NULL);
    diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
    timeCount += (diffSeconds + diffUSeconds/1000000.0);
  }
  cout << "Average time over 100 trials: " << timeCount/100 << endl;
/*
  ifstream inputFile("movies_mpaa.txt");
  if (!inputFile.is_open()){
    cout << "Could not open input file (1), exiting.\n";
    exit(1);
  }
  string line = "";
  int iTabIndex = -12;
  Dictionary<Movie> dict;
  int counter = 0;
  while (getline(inputFile, line)){
    iTabIndex = line.find('\t');
    Movie *m = new Movie;
    m->title = line.substr(0,iTabIndex);
    m->cast = line.substr(iTabIndex+1);
    dict.insert(m);
    Movie N(*m);
    assert(dict.get(N) == m); //proves that the thing is in there bruh
    counter++;
  }
  cout << "conter = " << counter << endl;

  //cout << "Enter a movie title (or exit to stop): ";
  string t = "";
  while(t != "exit"){
    cout << "Enter a movie title (or exit to stop): ";
    getline(cin, t);
    Movie M;
    M.title = t;
    Movie *n = new Movie;
    n = dict.get(M);
    if (n == NULL && t != "exit"){
      cout << "Couldn't find that movie!\n" << endl;
    }else if (t != "exit"){
      cout << "Cast: " << n->cast << endl;
    }
  }
  */
}

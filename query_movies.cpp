//Gezim Saciri & Ben Liepert
//tests the Dictionary on the list of movies

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dict.h"
#include "movie.h"
using namespace std;

void randomizeFile(string file){
  //===========================================
  // count lines in original file
  ifstream inputFile1(file);
  string line1;
  int numLines = 0;
  while (getline(inputFile1, line1)){
    numLines++;
  }
  //===========================================
  // for every line, pick a random number between 1 and #lines,
  // take this line in the original and write it to the randomized file
  ofstream outputFile("movies_mpaa_random.txt", ios_base::app); //we want to append to existing file
  vector<int> visited;
  float randomLine = 0;
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
    float count = 0;
    string line;
    ifstream inputFile;
    inputFile.open(file); //open the input file from the top
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

  randomizeFile("movies_mpaa.txt");

  ifstream inputFile("movies_mpaa_random.txt");
  string line;
  int iTabIndex;

  Dictionary<Movie> dict;

  while (getline(inputFile, line)){
    iTabIndex = line.find('\t');
    Movie *m = new Movie;
    m->title = line.substr(0,iTabIndex);
    m->cast = line.substr(iTabIndex+1);
    dict.insert(m);
  }

  string title = "Satanic (2006)";
  Movie L;
  L.title = title;
  Movie* got = dict.get(L);
  assert(got->title == "Satanic (2006)");
  assert(got->cast == "Brian Burnett	Jeffrey Combs	Rick Dean	Brett Erickson	Michael Gaglio	Matteo Indelicato	James Russo	Angus Scrimm	George Tovar	Lauren Emmel	Diane Ayala Goldner	Clara Houser	Priscilla Jones	Andrea Kennedy	Alicia Lor�n	Debbie Martinez	Annie Sorell	Eliza Swenson");

  string title1 = "Hardware (1990)";
  Movie L1;
  L1.title = title1;
  Movie* got1 = dict.get(L1);
  assert(got1->title == "Hardware (1990)");
  assert(got1->cast == "Sebastian Chee	William Hootkins	Oscar James	Arnold Lee	Fred Leeown	Lemmy	John Lynch	Carl McCoy	Dylan McDermott	Mac McDonald	Chris McHallem	Paul McKenzie	Mark Northover	Iggy Pop	Richard Stanley	Mimi Cheung	Susie Savage	Stacey Travis	Barbara Yu Ling");

  string title2 = "Soul Men (2008)";
  Movie L2;
  L2.title = title2;
  Movie* got2 = dict.get(L2);
  assert(got2->title == "Soul Men (2008)");
  assert(got2->cast == "Nathan Adams	Michael C. 'Mike' Allen	Scott Bomar	Michael Brouillet	P.J. Byrne	Keenan Carter	Ben Cauley	Affion Crockett	Ken Davitian	Miko DeFoor	Maurice DuBois	Gary D. Earl	Art Edmaiston	Mike Epps	Ron Fagan	Fatso-Fasano	Ted Ferguson	Marc Franklin	Michael Franklin	Sean Goulding	Willie Hall	Bart Hansard	Isaac Hayes	Sean Hayes	Adam Herschman	Randy Jackson	Samuel L. Jackson	John Legend	Jackie Long	Bernie Mac	Lee Ann McDade	Donald Meyers	Ritchie Montgomery	Juan Gabriel Pareja	James Paul	Charles 'Skip' Pitts	Joey Robinson	Ketrick Robinson	Dylan Sampson	Shane Sampson	Michael Showers	Franklin Ojeda Smith	Calvin Sykes	Jovan 'Jr.' Taylor	Paul T. Taylor	Jody Thompson	Archie 'Hubie' Turner	Kenon Walker	Thomas Wallace	Steven Whitemon	Clay Yocum	LaVita Brooks	NyaSimone Caldwell	Jennifer Coolidge	Vanessa del Rio	Sara Erikson	Lara Grice	Beth Hebert	Millie Jackson	Jackie Johnson	Sharon Leal	Cindy McBride	Robin Moffett	Soledad O'Brien	Monyetta Shaw	Alicia Tennant");

  string title3 = "Racing Stripes (2005)";
  Movie L3;
  L3.title = title3;
  Movie* got3 = dict.get(L3);
  assert(got3->title == "Racing Stripes (2005)");
  assert(got3->cast == "Kyle Alcazar	Gary Bullock	David Busch	Robert Clotworthy	Snoop Dogg	Michael Clarke Duncan	Jeff Foxworthy	Bruce Greenwood	Nicholas Guest	Archie Hahn	Jess Harnell	Steve Harvey	Graeme Hawkins	Dustin Hoffman	Joshua Jackson	John Lesley	Frankie Ryan Manriquez	Frankie Muniz	Jansen Panettiere	Joe Pantoliano	Caspar Poyck	Phil Proctor	Michael Rosenbaum	David Spade	Matt Stern	Fred Dalton Thompson	Morne Visser	M. Emmet Walsh	Denise Fox	Whoopi Goldberg	Wendie Malick	Dawn Matthews	Tarryn Meaker	Mandy Moore	Hayden Panettiere	Thandi Puren	Gail Thomas");
}

#ifndef ATHLETE_H
#define ATHLETE_H
#include <iostream>
using namespace std;

class Athlete
{

private:
	string team_or_ind;
	string venue;
	string country;

public:
	Athlete *left;
	Athlete *right;
	Athlete *parent;
	string discipline;
	string event;
	string gender;
	string color;
	string key;
	string athlete;
	string medal;
	Athlete(string disciplineIn, string genderIn, string team_or_indIn, string eventIn, string venueIn, string medalIn, string athleteIn, string countryIn);
	Athlete();
	~Athlete();
	void print();
};

#endif


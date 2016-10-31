#include "Athlete.h"
#include <iostream>
#include <string>
using namespace std;

Athlete::Athlete()
{
	discipline = "";
	color = "";
	event = "";
	gender = "";
	key = "";
	medal = "";
	team_or_ind = "";
	venue = "";
	country = "";
	athlete = "";
}

Athlete::~Athlete()
{
//	delete left;
//	delete right;
}

Athlete::Athlete(string disciplineIn, string genderIn, string team_or_indIn, string eventIn, string venueIn, string medalIn, string athleteIn, string countryIn)
{
	try
	{
		discipline = disciplineIn;
		gender = genderIn;
		team_or_ind = team_or_indIn;
		event = eventIn;
		venue = venueIn;
		medal = medalIn;
		athlete = athleteIn;
		country = countryIn;
		key = discipline + gender + event + athlete;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		color = "RED";
	}
	catch (...)
	{
		cout << "Invalid arguments";
	}
}

void Athlete::print()
{
	cout << "discipline:\t" << discipline << endl;
	cout << "gender:\t\t" << gender << endl;
	cout << "team_or_ind:\t" << team_or_ind << endl;
	cout << "event:\t\t" << event << endl;
	cout << "venue:\t\t" << venue << endl;
	cout << "medal:\t\t" << medal << endl;
	cout << "athlete:\t" << athlete << endl;
	cout << "country:\t" << country << endl;
	cout << endl;
}


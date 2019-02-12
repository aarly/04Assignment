// This is an application for the Skynet
// HK-Aerial.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using std::cout;
using std::endl;

int main()
{

	//
	// This is telling the user that the program
	// is generating an 8x8 grid internally.
	//
	cout << "Generating Random enemy location on a 8x8 grid...\n" << endl;
	//
	// This allows the rand to continue to create
	// random numbers.
	// If this is not included, then the program
	// will the same number as the first run 
	// through the program.
	//
	srand(time(0));
	//
	// Now I'm going to create the variables, which will be
	// specific for each search type.
	//
	int binaryHighestNumberSearch = 64;
	int binaryLowestNumberSearch = 1;
	int linearNumberSearch = 0;
	int randomHighestNumberSearch = 64;
	int randomLowestNumberSearch = 1;
	int playerNumberSearch;
	//
	// Next, I create a random number using the
	// two integers that I just created, and then
	// add it to a new integer.
	//
	int enemyLocation = rand() % binaryHighestNumberSearch + binaryLowestNumberSearch;
	// Now, I will make the counter for how many
	// tries the software takes to find the
	// enemy.
	//
	int binaryPingNumber = 0;
	int linearPingNumber = 0;
	int randomPingNumber = 0;
	int playerPingNumber = 1;
	//
	// This is telling the program whether or not
	// the enemy has been found and taken cared of.
	//
	bool binaryTargetFound = false;
	bool linearTargetFound = false;
	bool randomTargetFound = false;
	bool playerTargetFound = false;

	while (playerTargetFound == false)
	{

		//
		// I will now get the player to input their number, until they get the right answer.
		//
		cout << "=====================================================================" << endl;
		cout << "You will put put against three other computer AI, each using their own search patterns." << endl;
		cout << "You will now be entering where you believe the enemy location is on the 8x8 grid.\n" << endl;
		cout << enemyLocation << endl; 
		cin >> playerNumberSearch;
		//
		if (playerNumberSearch != enemyLocation)
		{

			//
			// This will let the user know that they did not guess correctly.
			//
			cout << "You did not guess correctly." << endl;
			cout << "Try again.\n" << endl;
			playerPingNumber++;

		}
		else if (playerNumberSearch == enemyLocation)
		{

			//
			// This will let the user know that they guessed the right answer.
			//
			cout << "You have guessed correctly, and the target has been eliminated at sector #" << playerNumberSearch << "." << endl;
			cout << "You took " << playerPingNumber << " pings to find the enemy.\n" << endl;
			break;


		}

	}
	//
	// Then, I'll output the number that the random
	// number generator came up with.
	//
	cout << "Enemy location has been found at sector #" << enemyLocation << " on the 8x8 grid with 1-64 sectors." << endl;
	//
	cout << "Skynet HK-Aerial now initializing software...\n" << endl;
	//
	while (binaryTargetFound == false)
	{

		//
		// The program will now select the location 
		// the drone's flyover.
		//
		int enemyLocationPrediction = ((binaryHighestNumberSearch - binaryLowestNumberSearch) / 2) + binaryLowestNumberSearch;
		//
		// This will add 1 to the amount of pings
		// that the drone does to find an enemy
		// for each time this part of the program
		// runs
		//
		binaryPingNumber++;
		//
		// The console will now giving the user
		// confirmation for whether or not the
		// programming is running.
		//
		cout << "=====================================================================" << endl;
		cout << "Skynet HK-Aerial that is using the binary search is now sending out ping #" << binaryPingNumber << "\n" << endl;
		//
		if (enemyLocationPrediction > enemyLocation)
		{

			//
			// The drone's highest number prediction
			// is higher than the enemy's location.
			// The drone will now adjust so the highest
			// number location is now lowered.
			//
			binaryHighestNumberSearch = enemyLocationPrediction - 1;
			cout << "The target location prediction of " << enemyLocationPrediction << " was higher than the enemy's location of " << enemyLocation << "." << endl;
			cout << "The new highestNumberSearch is now " << binaryHighestNumberSearch << ".\n" << endl;

		}
		//
		else if (enemyLocationPrediction < enemyLocation)
		{

			//
			// The drone's lowest number prediction
			// is lower than the enemy's location.
			// The drone will now adjust so the lowest
			// number location is now increased.
			//
			binaryLowestNumberSearch = enemyLocationPrediction + 1;
			cout << "The target location prediction of " << enemyLocationPrediction << " was lower than the enemy's location of " << enemyLocation << "." << endl;
			cout << "The new lowestNumberSearch is now " << binaryLowestNumberSearch << ".\n" << endl;

		}

		else if (enemyLocationPrediction == enemyLocation)
		{

			//
			// The drone has found the location
			// of the enemy using it's location
			// prediction.
			// The program will now output that the 
			// enemy has been terminated.
			//
			binaryTargetFound = true;
			cout << "The target has been found at sector #" << enemyLocationPrediction << ", and the drone has terminated enemy." << endl;
			cout << "The drone took " << binaryPingNumber << " pings to find enemy location.\n" << endl;
			break;

		}

	}

	while (linearTargetFound == false)
	{
		//
		// This will now run the linear AI's search
		//
		//
		// By running this, if the search does not equal the enemy's location,
		// than the program will add one to the new search, as well as adding
		// one to the ping.
		//
		linearNumberSearch++;
		linearPingNumber++;
		//
		cout << "=====================================================================" << endl;
		cout << "Skynet HK-Aerial that is using the linear search is now sending out ping #" << linearPingNumber << "\n" << endl;
		//
		if (linearNumberSearch == enemyLocation)
		{

			//
			// The drone has found the location
			// of the enemy using it's location
			// prediction.
			// The program will now output that the 
			// enemy has been terminated.
			//
			linearTargetFound = true;
			cout << "The target has been found at sector #" << linearNumberSearch << ", and the drone has terminated enemy." << endl;
			cout << "The drone took " << linearPingNumber << " pings to find enemy location.\n" << endl;
			break;

		}

	}

	while (randomTargetFound == false)
	{

		//
		// This will run the random search AI, and even if it gets the wrong number
		// it should run until it finds the right number.
		//
		int randomNumberSearch = rand() % randomHighestNumberSearch + randomLowestNumberSearch;
		randomPingNumber++;
		//
		cout << "=====================================================================" << endl;
		cout << "Skynet HK-Aerial that is using the random search is now sending out ping #" << randomPingNumber << "\n" << endl;
		//
		if (randomNumberSearch == enemyLocation)
		{

			//
			// The drone has found the location
			// of the enemy using it's location
			// prediction.
			// The program will now output that the 
			// enemy has been terminated.
			//
			linearTargetFound = true;
			cout << "The target has been found at sector #" << linearNumberSearch << ", and the drone has terminated enemy." << endl;
			cout << "The drone took " << randomPingNumber << " pings to find enemy location.\n" << endl;
			break;

		}

	}

	//
	// This will show the results of all the test in one location.
	// This is for the player's sake.
	//
	cout << "=====================================================================\n" << endl;
	cout << "All players have found the enemy location.\n" << endl;
	cout << "The player took " << playerPingNumber << " pings to find the enemy." << endl;
	cout << "The binary AI drone took " << binaryPingNumber << " pings to find enemy location." << endl;
	cout << "The linear AI drone took " << linearPingNumber << " pings to find enemy location." << endl;
	cout << "The random AI drone took " << randomPingNumber << " pings to find enemy location.\n" << endl;
	cout << "Thank you for playing this simulation.\n" << endl;
	cout << "=====================================================================\n" << endl;

	system("pause");

	return 0;



}
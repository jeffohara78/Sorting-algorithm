/* 
* MS539 Data Structures and Testing
* 11-16-24
* Jeff O'Hara
* In this demonstration console app using a random number generator. The app will utilize a sorting algorithm that will be timed, and we
* will be storing fixed values in a vector for comparison.
*/

// Libraries
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <random>

// use namespace std for cleanliness
using namespace std;

int main()
{
	// Define the test size for testing using a vector
	vector<int> data_sizes = { 100, 1000, 10000, 100000 };

	// Define the random num generator
	random_device rd;
	// Use Mersenne Twister random num generator and seed random as rd
	mt19937 gen(rd());
	// Define the range for the random numbers based on the min and max range
	uniform_int_distribution<> dis(1, 100000);

	// Print a header for the table to the user
	cout << "Data size\tVector Sort time (ms)\tList Sort time (ms)" << endl;

	// Create a loop for each data size
	for (int size:data_sizes)
	{
		// Generate random num and fill the vector
		vector<int> vec_data(size);
		for (int& x : vec_data)
		{
			x = dis(gen); 
		}

		// Copy the vector data to a list for comparison
		list<int> list_data(vec_data.begin(), vec_data.end());

		// Timing and sorting for the vector
		// Record the start time for the vector sort
		auto start_vec = chrono::high_resolution_clock::now();

		// Sort the vector using std::sort
		sort(vec_data.begin(), vec_data.end());

		// Record the end time for the vector sort
		auto end_vec = chrono::high_resolution_clock::now();

		// Calculate the duration in milliseconds (ms)
		auto duration_vec = chrono::duration_cast<chrono::milliseconds>(end_vec - start_vec).count();

		// Timing and sorting for the list
		// Record the start time for the list sort
		auto start_list = chrono::high_resolution_clock::now();

		// Sort the list using its member sort function
		list_data.sort();

		// Record the end time for the list sort
		auto end_list = chrono::high_resolution_clock::now();

		// Calculate the duration in ms
		auto duration_list = chrono::duration_cast<chrono::milliseconds>(end_list - start_list).count();

		// Output results in a table format to the user
		cout << size << "\t\t" << duration_vec << "\t\t\t" << duration_list << endl;
	}

	return 0;

}
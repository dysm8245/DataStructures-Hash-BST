#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>

using namespace std;

// C++ program to find the execution time of code
int main()
{
	auto start = chrono::steady_clock::now();

    // the sleep methods below are for you to test with to
	// prove that the chrono start and end times are working correctly
    this_thread::sleep_for (std::chrono::seconds(4));
	sleep(3);

	auto end = chrono::steady_clock::now();

	cout << "Elapsed time in nanoseconds : " 
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds : " 
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds : " 
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";

	return 0;
}
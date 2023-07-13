#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;

//just a class so i can time my program. i found this on stackoverflow.
class Timer
{
    private:
    using Clock = chrono::steady_clock;
    using Second = chrono::duration<double, ratio<1>>;
    chrono::time_point<Clock> m_beg { Clock::now() };
    
public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};
// this function checks if a number is prime
bool is_prime(unsigned long long num) {
    if (num < 2){
        return false; // 0 and 1 are not prime
    }

    for (unsigned long long i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0){ // if the number is divisible by i, it is not prime
            return false;
        }
    }

    return true;
}

int main() {
    Timer t;
    vector<unsigned long long> primes;
    unsigned long long current_number = 2;

    while (primes.size() < 10001) {
        if (is_prime(current_number)) // if the number is prime, add it to the vector
            primes.push_back(current_number);
        current_number++; // increment the number
    }

    cout << "Time elapsed: " << t.elapsed() << " seconds" << endl; // print the time elapsed
    cout << "10001st Prime: " << primes[10000] << endl; // print the 10001st prime

    return 0;
}

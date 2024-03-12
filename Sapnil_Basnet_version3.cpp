//Sapnil Basnet
//vbb23
//11/26/2023
//Program 6


#include <iostream>
#include<chrono>
using namespace std;
 auto start = chrono::steady_clock::now();


// Function to check if a number is prime
int prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0; // Even numbers greater than 2 are not prime
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

// Function to calculate the sum of squares of digits
int square_sum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}


// Function to check if a number is happy
int happy_num(int n) {
    do {
        n = square_sum(n);
    } while (n != 1 && n != 4);
    
    return n == 1;
}


// Function to count happy prime numbers between 1 and n
int total_happy_numbers(int L) {
    int count = 0;
    for (int i = 2; i <=  L; ++i) {  
        if (prime(i) && happy_num(i)) {
            ++count;
        }
    }
    return count;
}


int main() {
    int L = 1000000;
    int result = total_happy_numbers(L);
    cout << "The number of happy prime numbers between 1 and " << L << " is: " << result <<endl;
   
    auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    return 0;
}

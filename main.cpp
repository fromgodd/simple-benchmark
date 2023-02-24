#include <iostream>
#include <chrono>
#include <cmath>

// define the number of iterations for the benchmark
const int NUM_ITERATIONS = 100000000;

// define the function to benchmark (calculates the square root of a number)
double calculateSquareRoot(double x) {
    return std::sqrt(x);
}

int main() {
    // get the starting time
    auto start_time = std::chrono::high_resolution_clock::now();

    // run the benchmark
     double result = 0; 
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        result += calculateSquareRoot(i);
    }

    // get the ending time
    auto end_time = std::chrono::high_resolution_clock::now();

    // calculate the elapsed time
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // calculate the CPU speed in GHz
    double cpu_ghz = static_cast<double>(std::chrono::high_resolution_clock::period::den) / (std::chrono::high_resolution_clock::period::num * 1000000000.0);

    // calculate the benchmark score
    double score = static_cast<double>(NUM_ITERATIONS) / static_cast<double>(elapsed_time);

    // output the results
    std::cout << "Benchmark results:\n";
    std::cout << "Time: " << elapsed_time << " ms\n";
    std::cout << "CPU speed: " << cpu_ghz << " GHz\n";
    std::cout << "Score: " << score << "\n";

    return 0;
}


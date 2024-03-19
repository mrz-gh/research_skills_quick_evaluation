#include <iostream>
#include <ipp.h>
#include <random>
#include <chrono>


int min_Hamming3(unsigned int tab[], unsigned int tab_size) {
    // Initialize the minimum Hamming distance to the maximum possible value
    int min_distance = 32;

    // Iterate through all pairs of elements in the array
    for (unsigned int i = 0; i < tab_size - 1; ++i) {
        for (unsigned int j = i + 1; j < tab_size; ++j) {
            // Calculate the Hamming distance between the two elements
            unsigned int xor_result = tab[i] ^ tab[j];
            int distance = 0;

            // Count the number of set bits in the XOR result
            while (xor_result > 0) {
                distance++;
                if (distance >= min_distance)    break;

                xor_result &= (xor_result - 1);
            }

            // Update the minimum distance if a smaller distance is found
            if (distance < min_distance)
                min_distance = distance;

            //if (min_distance == 0)
            //    return 0;

        }
    }

    // Return the minimum Hamming distance
    return min_distance;
}


int min_Hamming2(unsigned int tab[], unsigned int tab_size) {
    // Initialize the minimum Hamming distance to the maximum possible value
    int min_distance = 32;

    // Iterate through all pairs of elements in the array
    for (unsigned int i = 0; i < tab_size - 1; ++i) {
        for (unsigned int j = i + 1; j < tab_size; ++j) {
            // Calculate the Hamming distance between the two elements
            unsigned int xor_result = tab[i] ^ tab[j];

            // Using hamming weight to calculate the Hamming distance
            unsigned int distance = 0;
            while (xor_result != 0) {
                distance++;
                xor_result &= (xor_result - 1);
            }

            // Update the minimum distance if a smaller distance is found
            if (distance < min_distance)
                min_distance = distance;
        }
    }

    // Return the minimum Hamming distance
    return min_distance;
}


int min_Hamming1(unsigned int tab[], unsigned int tab_size) {
    // Initialize the minimum Hamming distance to the maximum possible value
    int min_distance = 32;

    // Iterate through all pairs of elements in the array
    for (unsigned int i = 0; i < tab_size - 1; ++i) {
        for (unsigned int j = i + 1; j < tab_size; ++j) {
            // Calculate the Hamming distance between the two elements
            unsigned int xor_result = tab[i] ^ tab[j];
            int distance = 0;

            // Count the number of set bits in the XOR result
            while (xor_result > 0) {
                if (xor_result & 1)
                    distance++;
                xor_result >>= 1;
            }

            // Update the minimum distance if a smaller distance is found
            if (distance < min_distance)
                min_distance = distance;
        }
    }

    // Return the minimum Hamming distance
    return min_distance;
}




int main() {

    const unsigned int SIZE = 10000;
    unsigned int arr[SIZE];

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0, 100);

    // Fill the array with random values
    for (unsigned int i = 0; i < SIZE; ++i) {
        arr[i] = dist(gen);
    }

  
    int min_distance = 32;

    // Measure the execution time of the min_Hamming function
    auto start = std::chrono::high_resolution_clock::now();
    min_distance = min_Hamming1(arr, SIZE);
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Method 1:" << std::endl << "Minimum Hamming distance: " << min_distance << std::endl;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "\n";


    // Measure the execution time of the min_Hamming function
    start = std::chrono::high_resolution_clock::now();
    min_distance = min_Hamming2(arr, SIZE);
    end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Method 2:" << std::endl << "Minimum Hamming distance: " << min_distance << std::endl;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "\n";



    // Measure the execution time of the min_Hamming function
    start = std::chrono::high_resolution_clock::now();
    min_distance = min_Hamming3(arr, SIZE);
    end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Proposed Method:" << std::endl << "Minimum Hamming distance: " << min_distance << std::endl;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}
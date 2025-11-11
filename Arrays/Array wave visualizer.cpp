#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    const int SIZE = 20;          // Number of columns in the wave
    const int HEIGHT = 10;        // Max height of the wave
    int wave[SIZE];               // Array representing wave amplitudes
    srand(time(0));

    cout << "🎶 Dynamic Array Wave Visualizer 🎶\n\n";

    while (true) {
        // Fill array with random wave heights
        for (int i = 0; i < SIZE; i++) {
            wave[i] = rand() % HEIGHT;
        }

        // Clear screen (works in most terminals)
        system("clear"); // Use "cls" if on Windows

        // Print wave from top to bottom
        for (int y = HEIGHT; y >= 0; y--) {
            for (int x = 0; x < SIZE; x++) {
                if (wave[x] == y)
                    cout << "* ";
                else if (wave[x] > y)
                    cout << "| ";
                else
                    cout << "  ";
            }
            cout << endl;
        }

        cout << "\nPress Ctrl+C to stop\n";

        // Pause briefly before the next frame
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    return 0;
}

#include <reg51.h>

// Function prototypes
void delay(unsigned int);

// Main function
int main() {
    // Array for displaying 0, 1, 2, 3, 4 on a 7-segment (common cathode)
    unsigned char arr[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66};
    int i;

    while (1) {
        for (i = 0; i < 5; i++) {
            P2 = arr[i]; // Output the pattern to Port 2
            delay(500);  // Add a delay for visibility (in ms)
        }
    }
}

// Delay function (optimized to prevent loop removal)
void delay(unsigned int time) {
    int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++) { // Calibrated for 1 ms at 12 MHz clock
            // Do nothing (NOP)
        }
    }
}

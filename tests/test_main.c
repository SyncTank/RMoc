#include <stdio.h>
#include "util.h"  // Test your library headers

// Simple test case
int main(void) {
    if (add(2, 3) != 5) {  // Example test
        fprintf(stderr, "Test failed!\n");
        return 1;
    }
    printf("All tests passed!\n");
    return 0;
}

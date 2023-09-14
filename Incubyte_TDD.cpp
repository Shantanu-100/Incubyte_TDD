#include <iostream>
#include <vector>
using namespace std;
void executeCommand(char command, int& x, int& y, int& z, char& direction) {
    switch (command) {
        case 'f':
            if (direction == 'N') {
                y++;
            } else if (direction == 'S') {
                y--;
            } else if (direction == 'E') {
                x++;
            } else if (direction == 'W') {
                x--;
            } else if (direction == 'U') {
                z++;
            } else if (direction == 'D') {
                z--;
            }
            break;
        case 'b':
            if (direction == 'N') {
                y--;
            } else if (direction == 'S') {
                y++;
            } else if (direction == 'E') {
                x--;
            } else if (direction == 'W') {
                x++;
            } else if (direction == 'U') {
                z--;
            } else if (direction == 'D') {
                z++;
            }
            break;
        case 'l':
            if (direction == 'N') {
                direction = 'W';
            } else if (direction == 'S') {
                direction = 'E';
            } else if (direction == 'E') {
                direction = 'N';
            } else if (direction == 'W') {
                direction = 'S';
            }
            break;
        case 'r':
            if (direction == 'N') {
                direction = 'E';
            } else if (direction == 'S') {
                direction = 'W';
            } else if (direction == 'E') {
                direction = 'S';
            } else if (direction == 'W') {
                direction = 'N';
            }
            break;
        case 'u':
            if (direction == 'N' || direction == 'S') {
                direction = 'U';
            } else if (direction == 'U') {
                direction = 'S';
            } else if (direction == 'D') {
                direction = 'N';
            }
            break;
        case 'd':
            if (direction == 'N' || direction == 'S') {
                direction = 'D';
            } else if (direction == 'U') {
                direction = 'N';
            } else if (direction == 'D') {
                direction = 'S';
            }
            break;
        default:
            // Handle invalid command (if needed)
            break;
    }
}

int main() {
    int x = 0, y = 0, z = 0;
    char direction = 'N';

    char continueExecution = 'y';
    while (continueExecution == 'y' || continueExecution == 'Y') {
        std::cout << "Enter a command (f, b, l, r, u, d): ";
        char command;
        std::cin >> command;

        executeCommand(command, x, y, z, direction);

        std::cout << "Current Position: (" << x << ", " << y << ", " << z << ")\n";
        std::cout << "Current Direction: " << direction << "\n";

        std::cout << "Do you want to enter another command? (y/n): ";
        std::cin >> continueExecution;
    }

    std::cout << "Final Position: (" << x << ", " << y << ", " << z << ")\n";
    std::cout << "Final Direction: " << direction << "\n";

    return 0;
}

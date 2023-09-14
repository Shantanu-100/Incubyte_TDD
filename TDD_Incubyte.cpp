#include <iostream>
#include <vector>
using namespace std;
void executeCommands(int x, int y, int z, char direction, const vector<char>& commands, int& newX, int& newY, int& newZ, char& newDirection) {
    newX = x;
    newY = y;
    newZ = z;
    newDirection = direction;
    for (char command : commands) {
        switch (command) {
            case 'f':
                if (newDirection == 'N') {
                    newY++;
                } else if (newDirection == 'S') {
                    newY--;
                } else if (newDirection == 'E') {
                    newX++;
                } else if (newDirection == 'W') {
                    newX--;
                } else if (newDirection == 'U') {
                    newZ++;
                } else if (newDirection == 'D') {
                    newZ--;
                }
                break;
            case 'b':
                if (newDirection == 'N') {
                    newY--;
                } else if (newDirection == 'S') {
                    newY++;
                } else if (newDirection == 'E') {
                    newX--;
                } else if (newDirection == 'W') {
                    newX++;
                } else if (newDirection == 'U') {
                    newZ--;
                } else if (newDirection == 'D') {
                    newZ++;
                }
                break;
            case 'l':
                if (newDirection == 'N') {
                    newDirection = 'W';
                } else if (newDirection == 'S') {
                    newDirection = 'E';
                } else if (newDirection == 'E') {
                    newDirection = 'N';
                } else if (newDirection == 'W') {
                    newDirection = 'S';
                }
                break;
            case 'r':
                if (newDirection == 'N') {
                    newDirection = 'E';
                } else if (newDirection == 'S') {
                    newDirection = 'W';
                } else if (newDirection == 'E') {
                    newDirection = 'S';
                } else if (newDirection == 'W') {
                    newDirection = 'N';
                }
                break;
            case 'u':
                if (newDirection == 'N' || newDirection == 'S') {
                    newDirection = 'U';
                } else if (newDirection == 'U') {
                    newDirection = 'S';
                } else if (newDirection == 'D') {
                    newDirection = 'N';
                }
                break;
            case 'd':
                if (newDirection == 'N' || newDirection == 'S') {
                    newDirection = 'D';
                } else if (newDirection == 'U') {
                    newDirection = 'N';
                } else if (newDirection == 'D') {
                    newDirection = 'S';
                }
                break;
            default:
                cout<<"Invalid Command!!";
                break;
        }
    }
}

int main() {
    int x = 0, y = 0, z = 0;
    char direction = 'N';
    
    vector<char> commands;
    cout << "Enter commands (f, b, l, r, u, d): ";
    string input;
    cin >> input;

    for (char c : input) {
        commands.push_back(c);
    }

    int newX, newY, newZ;
    char newDirection;
    executeCommands(x, y, z, direction, commands, newX, newY, newZ, newDirection);

    cout << "Final Position: (" << newX << ", " << newY << ", " << newZ << ")\n";
    cout << "Final Direction: " << newDirection << "\n";

    return 0;
}

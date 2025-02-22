#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        cout << "System hostname: " << hostname << endl;
    } else {
        cerr << "Failed to get hostname!" << endl;
        return 1;
    }
    return 0;
}

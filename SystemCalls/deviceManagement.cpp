#include <iostream>
#include <dirent.h>

using namespace std;

int main() {
    struct dirent *entry;
    DIR *dp = opendir("/dev");

    if (dp == NULL) {
        cerr << "Error opening /dev directory!" << endl;
        return 1;
    }

    cout << "Listing available devices: " << endl;
    while ((entry = readdir(dp)) != NULL) {
        cout << entry->d_name << endl;
    }

    closedir(dp);
    return 0;
}

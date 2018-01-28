#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main() {
    DIR * d = opendir(".");
    if (d == NULL) {
        cout << "opendir error" << endl;
        return -1;
    }

    struct dirent * entry;
    while ( (entry = readdir(d)) != NULL) {
        cout << entry->d_name << endl;
    }

    closedir(d);

    return 0;
}

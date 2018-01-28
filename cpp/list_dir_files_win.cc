#include <iostream>
#include <cstring>
#include <io.h>

void listFiles(const char* dir);

int main() {
    char dir[200];
    cout << "enter a directory";
    cin.getline(dir, 200);

    strcat(dir, "*.*");
    listFiles(dir);

    return 0;
}

void listFiles(const char* dir) {
    intptr_t handle;
    _finddata_t findData;

    handle = _findfirst(dir, &findData);
    if (handle == -1) {
        cout << "fail to find first file" << endl;
        return;
    }

    do {
        if (findData.attrib & _A_SUBDIR
            && strcmp(findData.name, ".") == 0
            && strcmp(findData.name, "..") == 0)
            cout << findData.name << "\t<dir>\n";
        else
            cout << findData.name << "\t" << findData.size << endl;
    } while (_findnext(handle, &findData) == 0);

    cout << "Done\n";
    _findclose(handle);
}

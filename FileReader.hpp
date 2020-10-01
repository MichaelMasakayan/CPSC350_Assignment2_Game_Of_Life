#ifndef _FILE_READER_HPP_
#define _FILE_READER_HPP_

#include <string>

using namespace std;

class FileReader {
    public:
        FileReader(string fileName);
        char** readFile();

    private:
        int width;
        int height;
        string fileName;
};

#endif
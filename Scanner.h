#ifndef UNTITLED_SCANNER_H
#define UNTITLED_SCANNER_H

#include "Utils.h"
#include <string>
#include <thread>

class FileQueue;
class Scanner
{
public:
    Scanner(FileQueue & queue);
    void startScan(const M_STRING & rootPath);
    void stop();

private:
    void backgroundThread(M_STRING rootPath);

private:
    FileQueue & mQueue;
    std::thread mThread;
    bool stopped;
};


#endif //UNTITLED_SCANNER_H

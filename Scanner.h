#ifndef UNTITLED_SCANNER_H
#define UNTITLED_SCANNER_H

#include <string>
#include <thread>

class FileQueue;
class Scanner
{
public:
    Scanner(FileQueue & queue);
    void startScan(const std::string & rootPath);
    void stop();

private:
    void backgroundThread();

private:
    FileQueue & mQueue;
    std::thread mThread;
    bool stopped;
};


#endif //UNTITLED_SCANNER_H

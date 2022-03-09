//
// Created by Oleksandr Shchukin on 09.03.2022.
//

#ifndef UNTITLED_FILEPROCESSOR_H
#define UNTITLED_FILEPROCESSOR_H

#include <thread>

class FileQueue;
class FileProcessor
{
public:
    FileProcessor(FileQueue & queue);
    void start();
    void stop();
private:

    void backgroundThread();

private:
    FileQueue & mFileQueue;
    std::thread mThread;
    bool stopped;
};


#endif //UNTITLED_FILEPROCESSOR_H

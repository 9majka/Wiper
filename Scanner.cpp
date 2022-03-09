#include "Scanner.h"
#include "FileQueue.h"

Scanner::Scanner(FileQueue &queue)
    : mQueue(queue)
    , stopped(false)
{

}

void Scanner::startScan(const std::string & rootPath)
{
    mThread = std::thread(&Scanner::backgroundThread, this);
}

void Scanner::stop()
{
    stopped = true;
    mThread.join();
}

void Scanner::backgroundThread()
{
    int i = 0;
    while (!stopped)
    {
        // TODO test generation
        mQueue.putFile("Test" + std::to_string(i));
        i++;

        //Test
        if(i>100) return;
    }
}
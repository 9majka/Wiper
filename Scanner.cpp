#include "Scanner.h"
#include "FileQueue.h"

Scanner::Scanner(FileQueue &queue)
    : mQueue(queue)
    , stopped(false)
{

}

void Scanner::startScan(const M_STRING & rootPath)
{
    mThread = std::thread(&Scanner::backgroundThread, this, rootPath);
}

void Scanner::stop()
{
    stopped = true;
    mThread.join();
}

void Scanner::backgroundThread(M_STRING rootPath)
{
    int i = 0;
    while (!stopped)
    {
        // TODO test generation
        M_STRING tempFileName = __M("Test") + TO_M_STRING(i);
        mQueue.putFile(tempFileName);
        i++;

        //Test
        if(i>100) return;
    }
}
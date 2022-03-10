#include "FileProcessor.h"
#include "FileWiper.h"
#include "FileQueue.h"
#include "Utils.h"

FileProcessor::FileProcessor(FileQueue & queue)
    : mFileQueue(queue)
    , stopped(false)
{
}

void FileProcessor::start()
{
    mThread = std::thread(&FileProcessor::backgroundThread, this);
}

void FileProcessor::stop()
{
    stopped = true;
    mThread.join();
}

void FileProcessor::backgroundThread()
{
    while (!stopped)
    {
        M_STRING filePath = mFileQueue.GetFile();
        FileWiper::wipeFile(filePath);
    }
}
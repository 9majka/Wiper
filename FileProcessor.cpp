//
// Created by Oleksandr Shchukin on 09.03.2022.
//

#include "FileProcessor.h"
#include "FileWiper.h"
#include "FileQueue.h"

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
        std::string filePath = mFileQueue.GetFile();
        FileWiper::wipeFile(filePath);
    }
}
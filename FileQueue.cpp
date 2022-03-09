#include "FileQueue.h"
#include <mutex>
#include <condition_variable>

namespace
{
    std::mutex _queueMutex;
    std::condition_variable _condVar;
}

void FileQueue::putFile(const std::string & filePath)
{
    std::lock_guard lg(_queueMutex);
    mFileQueue.push(filePath);
    _condVar.notify_all();
}

std::string FileQueue::GetFile()
{
    std::unique_lock<std::mutex> ul(_queueMutex);
    while (true)
    {
        if(mFileQueue.size() > 0)
        {
            std::string filePath = mFileQueue.front();
            mFileQueue.pop();
            return filePath;
        }
        else
        {
            _condVar.wait(ul);
        }
    }
    return "";
}
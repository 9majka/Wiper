#include "FileQueue.h"
#include <mutex>
#include <condition_variable>

namespace
{
    std::mutex _queueMutex;
    std::condition_variable _condVar;
}

void FileQueue::putFile(const M_STRING & filePath)
{
    std::lock_guard lg(_queueMutex);
    mFileQueue.push(filePath);
    _condVar.notify_all();
}

M_STRING FileQueue::GetFile()
{
    std::unique_lock<std::mutex> ul(_queueMutex);
    while (true)
    {
        if(mFileQueue.size() > 0)
        {
            M_STRING filePath = mFileQueue.front();
            mFileQueue.pop();
            return filePath;
        }
        else
        {
            _condVar.wait(ul);
        }
    }
    return M_STRING();
}
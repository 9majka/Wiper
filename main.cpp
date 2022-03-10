#include "Scanner.h"
#include "FileQueue.h"
#include "FileProcessor.h"
#include <vector>
#include <iostream>
#include "Utils.h"

int threadCount = 5;


void printHelp()
{
    std::cout<<"Usage:"<<std::endl;
    std::cout<<"wiper.exe -p D:\\ -t 5"<<std::endl;
    std::cout<<"wiper.exe -p D:\\"<<std::endl;
    std::cout<<"Where:"<<std::endl;
    std::cout<<"-p - path to disk drive"<<std::endl;
    std::cout<<"-t - number of threads. Default "<< threadCount <<std::endl;
}

bool parseArgs(int argc, M_CHAR *argv[], M_STRING & path, int & tCount)
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout<<argv[i]<<std::endl;
    }

    if(argc == 3 || argc == 5)
    {
        M_STRING pathKey(argv[1]);
        M_STRING pathValue(argv[2]);
        if(pathKey == __M("-p"))
        {
            path = pathValue;
        }
        else return false;

        if(argc == 5)
        {
            M_STRING threadKey(argv[3]);
            M_STRING threadValue(argv[4]);
            if(threadKey == __M("-n"))
            {
                tCount = std::stoi(threadValue);
            }
            else return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

#ifdef WINDOWS
int wmain(int argc, M_CHAR *argv[])
#else
int main(int argc, M_CHAR *argv[])
#endif
{
    int tCount = threadCount;
    M_STRING drivePath;
    if(!parseArgs(argc, argv, drivePath, tCount))
    {
        printHelp();
        return -1;
    }

    std::cout << "Drive path: " << drivePath.c_str() << std::endl;
    std::cout << "Thread count: " << tCount << std::endl;

    FileQueue fileQueue;
    Scanner scanner(fileQueue);
    scanner.startScan(drivePath);

    std::vector<FileProcessor *> processors;

    for (int i = 0; i < tCount; ++i)
    {
        FileProcessor * processor = new FileProcessor(fileQueue);
        processor->start();
        processors.push_back(processor);
    }

    int n;
    std::cout<<"Press any key to exit"<<std::endl;
    std::cin>>n;

    return 0;
}

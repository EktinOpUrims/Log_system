#include <iostream>
#include <unistd.h>
#include <thread>
#include "log.h"


void function_template(std::string file_name, std::string f_prefix, int num)
{
    auto logger = getLogger(file_name, f_prefix);
    logger << "message number " << num;
}


void test()
{
    int N = 2000;
    
    std::string file_name_1 = "";
    std::string file_name_2 = "log.txt"; //"test_log_1.txt";
    std::string file_name_3 = "log2.txt"; //"test_log_2.txt";
    
    std::thread threads[N];
    for(int i = 0; i < N; ++i)
    {
        if (i % 3 == 0)
        {
            threads[i] = std::thread(function_template, file_name_3, "f6", i);
        }
        else if (i % 3 == 1)
        {
            threads[i] = std::thread(function_template, file_name_2, "f5", i);
        }
        else
        {
            threads[i] = std::thread(function_template, file_name_1, "f9", i);
        }
    }
    for (int i = N - 1; i >= 0; --i)
    {
        threads[i].join();
    }    
}
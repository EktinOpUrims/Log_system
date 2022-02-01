#include <iostream>
//#include <chrono>
//#include <fstream>
#include <thread>
#include <mutex>

#include <unistd.h>

#include "log.h"
#include "get_time.h"
#include "generate_color.h"
#include "color.h"
#include "globals.h"

///////////////////////////////////////////////


std::mutex console_mutex;

const char* folder_prefix = "log_outputs/";


///////////////////////////////////////////////


std::ostream& operator<< (std::ostream& os, log_levels log_level) {
    switch (log_level) {
        case INFO: os << "INFO"; break;
        case DEBUG: os << "DEBUG"; break;
        case WARNING: os << "WARNING"; break;
        case ERROR: os << "ERROR"; break;
    }
    return os;
}


//////////////////////////////////////////


getLogger::getLogger(std::string file_n, std::string f_pref)
	    : log_level(INFO)
	    , file_name(file_n)
	    , f_prefix(f_pref) {
    if (file_name == "") {
        output_target = &std::cout;
    }
	else {
        mkdir(folder_prefix);
        out_file = std::ofstream(folder_prefix + file_name, std::ios::app);
        output_target = &out_file;
    }
}


getLogger::~getLogger() {
    if (auto ptr = dynamic_cast<std::ofstream*>(output_target)) {
        ptr->close();
    }
}


std::ostream& getLogger::operator<< (const std::string msg) {
    
    // if we are in console mode, then use mutex: it is the only option in that case
    if (file_name == "")
    {
        //std::lock_guard<std::mutex> guard(console_mutex);
        console_mutex.lock();
    }
    
    // setting the color
    //int do_we_use_colored_output = 0;
    //if (file_name == "" && colored_output_mode)
    //{
    //    do_we_use_colored_output = 1;
    //}

    *output_target << "\n";
    /*if (do_we_use_colored_output)
    {
        *output_target << get_random_color();
    }*/
    *output_target << get_time_now() << "; "
        << log_level << "; "
        << f_prefix
        << "(" << getpid() << "; "
        << std::this_thread::get_id()
        << "): "
        << msg;
    /*if (do_we_use_colored_output)
    {
        *output_target << reset_color;
    }*/
    log_level = INFO;
    if (file_name == "")
    {
        //std::lock_guard<std::mutex> guard(console_mutex);
        console_mutex.unlock();
    }
    return *output_target;
}


getLogger& getLogger::operator ()(log_levels log_lev) {
    log_level = log_lev;
    return *this;
}



  ///////////////////////////////////
 ///////////////////////////////////
///////////////////////////////////

/*void f1()
{
    std::cout << "\nThe current thread (in f1): " << std::this_thread::get_id() << "\n";
    
    auto consoleLogger = getLogger();
    consoleLogger(DEBUG) << "Running a thread";

    auto fileLogger = getLogger("log.txt");
    fileLogger << "Running a thread";
    std::cout << "\nThe current thread (in f1): " << std::this_thread::get_id() << "\n";
}

void f2()
{
    std::cout << "\nThe current thread (in f2): " << std::this_thread::get_id() << "\n";

    auto logger = getLogger("log.txt", "f2");
    logger(DEBUG) << "Running a thread";

    double time_spent = 10.0;
    logger(WARNING) << "Time spent in the thread: " << time_spent << " seconds";

    std::cout << "\nThe current thread (in f2): " << std::this_thread::get_id() << "\n";
}

void f3()
{
    std::cout << "\nThe current thread (in f3): " << std::this_thread::get_id() << "\n";

    auto logger = getLogger("log2.txt", "f3");
    logger << "Running a thread";

    int i = 3;
    logger(ERROR) << "My int is " << i;

    std::cout << "\nThe current thread (in f3): " << std::this_thread::get_id() << "\n";
}
*/
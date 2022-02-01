#pragma once

#include <fstream>
#include <mutex>

enum log_levels {INFO, DEBUG, WARNING, ERROR};
//std::mutex console_mutex;

std::ostream& operator<< (std::ostream& os, log_levels log_level);

std::string get_time_now();

struct getLogger {
    std::string file_name;
    std::string f_prefix;
    log_levels log_level;
    std::ostream* output_target;
    std::ofstream out_file;

    getLogger(std::string file_n = "", std::string f_pref = "");
	
    ~getLogger();
    
    std::ostream& operator<< (const std::string msg);

    getLogger& operator ()(log_levels log_lev);
};
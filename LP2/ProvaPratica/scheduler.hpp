#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include "includes.hpp"

class Scheduler
{
private:

protected:
vector <size_t> m_job;

public:
Scheduler() : m_job(0){};
Scheduler(vector<size_t> vjob) : m_job(vjob) {};
~Scheduler() {};

vector<size_t> GetVector(){return m_job;};

void ResetJobs(vector<size_t> vejob){m_job = vejob;};

bool SetJob(size_t job){
    for(size_t i=0; i<m_job.size(); i++){
        if(job == m_job.at(i)){
        return false;
        }
    }
m_job.push_back(job);
return true;
};

};

#endif
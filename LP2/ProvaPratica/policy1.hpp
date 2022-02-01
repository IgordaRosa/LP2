#ifndef POLICY1_HPP
#define POLICY1_HPP
#include "scheduler.hpp"

class Policy1 : public Scheduler
{   
private:

protected:

public:
Policy1() : Scheduler(){};
Policy1(Scheduler *jobs) : Scheduler(jobs->GetVector()){};
~Policy1(){};

void ExecuteP1(){
    if(m_job.size() > 0){
    cout << "The Job " << m_job.at(0) << " preceeded successfully and delete!" << endl;
    m_job.erase(m_job.begin()+0);
    }

    else{
    cout <<endl << "Finished the tasks to be done!" << endl;
    }
};
};

#endif
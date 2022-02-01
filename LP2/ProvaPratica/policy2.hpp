#ifndef POLICY2_HPP
#define POLICY2_HPP
#include "policy1.hpp"

class Policy2 : public Scheduler
{
private:

protected:

public:
Policy2() : Scheduler(){};
Policy2(Scheduler *jobs) : Scheduler(jobs->GetVector()){};
~Policy2(){};

void ExecuteP2(){
    if(m_job.size() > 0){
    cout << "The Job " << m_job.at(m_job.size()-1) << " preceeded successfully and delete!" << endl;
    m_job.erase(m_job.begin()+ m_job.size()-1);
    }

    else{
    cout <<endl << "Finished the tasks to be done!" << endl;
    }
};
};

#endif
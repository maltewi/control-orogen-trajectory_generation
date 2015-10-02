/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef TRAJECTORY_GENERATION_RMLVELOCITYTASK_TASK_HPP
#define TRAJECTORY_GENERATION_RMLVELOCITYTASK_TASK_HPP

#include "trajectory_generation/RMLVelocityTaskBase.hpp"

namespace trajectory_generation{

class RMLVelocityTask : public RMLVelocityTaskBase
{
    friend class RMLVelocityTaskBase;
protected:

public:
    RMLVelocityTask(std::string const& name = "trajectory_generation::RMLVelocityTask");
    RMLVelocityTask(std::string const& name, RTT::ExecutionEngine* engine);
    ~RMLVelocityTask();
    bool configureHook();
    bool startHook();
    void updateHook();
    void errorHook();
    void stopHook();
    void cleanupHook();


    /** Call position or velocity based OTG, depending on the implementation*/
    virtual ReflexxesResultValue performOTG(base::commands::Joints &current_command);
    /** Set appropriate joint state depending on whether using position or velocity based RML*/
    virtual void setJointState(const base::JointState& state, const size_t idx);
    /** Set appropriate target depending on whether using position or velocity based RML*/
    virtual void setTarget(const base::JointState& cmd, const size_t idx);
    /** Set appropriate constraints depending on whether using position or velocity based RML*/
    virtual void setMotionConstraints(const trajectory_generation::JointMotionConstraints& constraints, const size_t idx);
    /** Convert from RMLOutputParameters to orogen type*/
    virtual const ReflexxesOutputParameters& fromRMLTypes(const RMLOutputParameters &in, ReflexxesOutputParameters& out);

    virtual void printParams(){
        ((RMLVelocityInputParameters*)rml_input_parameters)->Echo();
        ((RMLVelocityOutputParameters*)rml_output_parameters)->Echo();
    }

};
}

#endif


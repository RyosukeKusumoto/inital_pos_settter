#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>

namespace gazebo
{
/// \brief A plugin to control a Velodyne sensor.
class Xdm2InitialPosSetter : public ModelPlugin
{
    /// \brief Constructor
    public: Xdm2InitialPosSetter() {}

    /// \brief The load function is called by Gazebo when the plugin is
    /// inserted into simulation
    /// \param[in] _model A pointer to the model that this plugin is
    /// attached to.
    /// \param[in] _sdf A pointer to the plugin's SDF element.
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
        // Just output a message for now
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << "model name: " << _model->GetName() << " was loaded" << std::endl;

        std::map<std::string, double> positions = {
            {"joint1", 0},
            {"joint2", 0},
            {"joint3", -1.57},
            {"joint4", 0},
            {"joint5", 0},
            {"joint6", 0},
        };
        for (physics::JointPtr joint: _model->GetJoints()) {
            joint->SetPosition(0, positions[joint->GetName()]);
        }
        
    }
};

// Tell Gazebo about this plugin, so that Gazebo can call Load on this plugin.
GZ_REGISTER_MODEL_PLUGIN(Xdm2InitialPosSetter)
}
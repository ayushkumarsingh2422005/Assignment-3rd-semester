from abc import abstractmethod, ABC
import math

class RigidBody(ABC):
    @abstractmethod
    def angular_velocity(self, time, initial_torque):
        pass
    
    @abstractmethod
    def moment_of_inertia(self):
        pass
    
    @abstractmethod
    def torque(self, force, lever_arm):
        pass
    
class SolidSphere(RigidBody):
    def __init__(self, radius, mass):
        self.radius = radius
        self.mass = mass
    
    def moment_of_inertia(self):
        return (2/5) * self.mass * self.radius**2
    
    def torque(self, force, lever_arm):
        return force * lever_arm
    
    def angular_velocity(self, time, initial_torque):
        return (initial_torque / self.moment_of_inertia()) * time

class HollowCylinder(RigidBody):
    def __init__(self, radius, mass):
        self.radius = radius
        self.mass = mass
    
    def moment_of_inertia(self):
        return self.mass * self.radius**2
    
    def torque(self, force, lever_arm):
        return force * lever_arm
    
    def angular_velocity(self, time, initial_torque):
        # ω = (τ/I)t
        return (initial_torque / self.moment_of_inertia()) * time

def compare_angular_velocities(body1, body2, target_velocity, force, lever_arm):
    torque = force * lever_arm
    
    time1 = target_velocity / (torque / body1.moment_of_inertia())
    time2 = target_velocity / (torque / body2.moment_of_inertia())
    
    if time1 < time2:
        return f"Body 1 reaches {target_velocity} rad/s first in {time1:.2f} seconds"
    elif time2 < time1:
        return f"Body 2 reaches {target_velocity} rad/s first in {time2:.2f} seconds"
    else:
        return "Both bodies reach the target velocity at the same time"

# Example usage
if __name__ == "__main__":
    # Create instances
    sphere = SolidSphere(radius=0.1, mass=1.0)
    cylinder = HollowCylinder(radius=0.1, mass=1.0)
    
    # Compare which reaches 10 rad/s first with 5N force at 0.2m lever arm
    result = compare_angular_velocities(sphere, cylinder, 10, 5, 0.2)
    print(result)
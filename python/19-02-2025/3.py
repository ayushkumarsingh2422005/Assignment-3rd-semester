# Implement an abstract class ElectromagneticWave with methods for calculating wave
# parameters. Create two subclasses:
# ● RadioWave: Computes frequency from wavelength in MHz range.
# ● XRayWave: Computes energy using E=hfE = hf.
# Allow polymorphism so users can input frequency or wavelength and get properties for any
# wave type.

from abc import ABC, abstractmethod

class ElectromagneticWave(ABC):
    @abstractmethod
    def calculate_frequency(self):
        pass

class RadioWave(ElectromagneticWave):
    def __init__(self, wavelength):
        self.wavelength = wavelength
    
    def calculate_frequency(self):
        return 3 * 10**8 / self.wavelength  
    
class XRayWave(ElectromagneticWave):
    def __init__(self, frequency):
        self.frequency = frequency
    
    def calculate_frequency(self):
        return self.frequency
    
    def calculate_energy(self):
        return self.frequency * 6.626 * 10**-34 
    
def main():
    radio_wave = RadioWave(1000)
    print(radio_wave.calculate_frequency())
    

    x_ray_wave = XRayWave(1000)
    print(x_ray_wave.calculate_energy())

if __name__ == "__main__":
    main()
    



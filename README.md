# PID Control Project

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

Self-Driving Car Engineer Nanodegree Program

Overview

---

[//]: # (Image References)

[video]: ./images/particle_output.gif "Video showing tracking performance"
[final_result]: ./images/particle_sim_result.PNG "Final Result"
[eq_1]: ./images/equation_1.gif "Equation 1"
[eq_2]: ./images/equation_2.gif "Equation 2"
[eq_3]: ./images/equation_3.gif "Equation 3"
[eq_4]: ./images/equation_4.gif "Equation 4"

**PROJECT DESCRIPTION**

In this project I implemented a PID controller in C++ to maneuver the vehicle around a lake race track in a simulated environment. PID stands for Proportional Integral Derivative Controller. PID controller are popular for applications involving closed loop systems with continuous control. 

The Role of the PID controller is to estimate a corrective value based on cross track error (CTE). The simulator will provide the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle. CTE is deviation from the center or desired trajectory. 

- **Praportional**: Directly praportional to CTE value
- **Integral**: Relates to cumilative sum of CTE values, used to counter systematic bias
- **Derivative**: Relates to difference between the current and previous CTE, helps reduce overshooting as it limits the correction once closer to goal

**Project Goals**

The goals / steps of this project are the following:
- Build a PID controller in C++
- Tune controller coefficients/hyperparameters (Kp, Ki, Kd)
- Vehicle succesfully drives a lap around the track without tires leaving the driveable portions

**Project Files**

The directory structure of this repository is as follows:

```
root
|   cmakepatch.txt
|   CMakeLists.txt
|   install-mac.sh
|   install-ubuntu.sh
|   README.md
|   set_git.sh
|
|___images
|   |   particle_sim_result.PNG
|   |   particle_output.gif
|
|___src
    |   json.hpp
    |   main.cpp
    |   PID.cpp
    |   PID.h

```

## PID Coefficients

For the project I used a PID controller to correct steering angle. The throttle was made proportional to the steering angle such that greater the steering angle slower the speed. 

**Proportional (Kp)**

Reactiveness to error.

Higher: Will cause vehicle to overshoot and oscillate quickly.

Lower: The time difference between oscialltion will increase and the vehicle will be less reactive to errors  

**Proportional (Kd)**

Scalling correction based on magnitude of error.

Higher: Increases reaction time, having a smoothing effect and reducing aggresive oscillations

Lower: Less reaction time causing severe oscillations

**Proportional (Ki)**

The vehicle in the simulator did not appear to have any bias hence this parameter was left as a very small value close to zero.  

Final chosen parameters:

|----|---------|
| Kp | 0.1     |
| Ki | 0.003   |
| Kp | 3.0     |


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).


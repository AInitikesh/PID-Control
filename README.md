# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---


## Manual Tuning of PID coefficients

I have tuned all Kp, Ki and Kd manually with trial and error method.

* Proportional Coefficient (Kp):

Kp is the coefficient that gets multiplied with negative value of CTE to determine the error. Kp is scaling factor for calculating the error from CTE.
For calculating Kp I started with 1.0 keeping Kd and Ki as zero. If I keep the value close to zero car fails to turn on corners and if I increase the value of Kp the car goes outside the track due to wobble. By adjusting the value to 0.2 the car was able to complete the track. 

* Differential Coefficient (Kd):

Kd is the coefficient that gets multiplied with negative value of CTE minus Previous CTE to determine the error. Kd is the scaling factor for calulating the error from rate of change of CTE. For calculating Kd I started with 1.0 keeping Kp = 0.2 and Ki = zero. If I keep the value close to zero car wobble a lot and if I increase the value of Kd to much like 20 the car seams to be stable but takes a lot of time to reduce CTE. By adjusting the value to 6.0 the car was more stable around CTE.

* Integral Coefficient (Ki):

Ki is the coefficient that gets multiplied with negative value of sum of all Previous CTEs to determine the error. Ki is the scaling factor for reducing the baising effect. For calculating Ki I started with 0.1 keeping Kp = 0.2 and Kd = 6.0. If I keep the value zero car works properly in this case but consider the car is very off track keeping a very low value of Ki like 0.000001 will help to bring in the car to the center. By adjusting the value to 0.000001 the car was more stable around CTE.


## PID to calculate the throttle

I have impletemnted another PID to control the speed of car. The CTE in this case is calulated by the equation
```math #yourmathlabel
fabs( 2.0 * cte - steer_value) * 0.7 - 3
```
I manually tuned Kp=1.0, Ki=0.00001 & Kd=30.0 for throttle PID

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

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).


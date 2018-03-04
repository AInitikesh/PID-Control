#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->prev_cte = 0;
}

void PID::UpdateError(double cte) {
    this->p_error = - cte * Kp;
    this->i_error -= cte * Ki;
    this->d_error = - (cte - prev_cte) * Kd;
    this->prev_cte = cte;

}

double PID::TotalError() {
    return p_error + i_error + d_error;
}


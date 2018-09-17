#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() 
{
	p_error = 0.0;
  	i_error = 0.0;
	d_error = 0.0;
	initialized = false;
}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) 
{
	Kp = kp;
	Ki = ki;
	Kd = kd;
}

void PID::UpdateError(double cte) 
{
	if (!initialized)
	{
		initialized = true;
		p_error = cte;		
	}

	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() 
{
	return -Kp * p_error - Kd * d_error - Ki * i_error;
}


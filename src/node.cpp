//============================================================================
// STL Inclusions
//============================================================================
#include <stdlib.h>
#include <vector>

//============================================================================
// Node Class Definition
//============================================================================

class Node
{

public:
  
  // get set position 
  vector<double> get_pos();
  void set_pos(double, double); 
  void offset_pos(double, double); 
  
  // get set x position 
  double get_x_pos();
  void set_x_pos(double);
  void offset_x_pos(double); 
  
  // get set y position
  double get_y_pos(); 
  void set_y_pos(double);
  void offset_y_pos(double);
  
  // get set velocity
  vector<double> get_vel();
  void set_vel(double, double); 
  void offset_vel(double, double); 
  
  // get set velocity magnitude
  double get_vel_mag();
  void set_vel_mag(double);
  void offset_vel_mag(double); 

  // get set velcoity direction
  double get_vel_dir();
  void set_vel_dir(double);
  void offset_vel_dir(double); 

  // get set acceleration 
  vector<double> get_acc();
  void set_acc(double, double);
  void offset_acc(double, double); 

  // get set acceleration magnitude
  double get_acc_mag();
  void set_acc_mag(double);
  void offset_acc_mag(double);

  // get set acceleration direction
  double get_acc_dir();
  void set_acc_dir(double);
  void offset_acc_dir(double);

private:

//-----------------
// position
//-----------------

// x position
double x_pos;
double x_min;
double x_max;

// y position
double y_pos;
double y_min;
double y_max;

//-----------------
// velocity
//-----------------

// magnitude
double vel_mag;
double vel_mag_min;
double vel_mag_max;

// direction (0-360 degrees)
double vel_dir;

//-----------------
// acceleration
//-----------------

// magnitude
double acc_mag;
double acc_mag_min;
double acc_mag_max;

// direction (0-360 degrees)
double acc_dir;

};

//============================================================================
// Function Definitions
//============================================================================

//-------------------------------------
// position (x, y) tuple
//-------------------------------------
vector<double> Node::get_pos()
{
  return vector<double> v = {x_pos, y_pos};
}

void Node::set_pos(double x_position, double y_position)
{
  set_x_pos(x_position);
  set_y_pos(y_position);
} 

void Node::offset_pos(double x_offset, double y_offset)
{
  offset_x_pos(x_offset);
  offset_y_pos(y_offset);
}

//-------------------------------------
// position x component
//-------------------------------------
double Node::get_x_pos()
{
  return x_pos;
}

void Node::set_x_pos(double position)
{
  if(position < x_min)
  {
    x_pos = x_min;
  }
  else if(position > x_max)
  {
    x_pos = x_max;
  }
  else
  {
    x_pos = position;
  }
}

void Node::offset_x_pos(double offset)
{
  double offset_pos = x_pos + offset;
  set_x_pos(offset_pos);
}

//-------------------------------------
// position y component
//-------------------------------------
double Node::get_y_pos()
{
  return y_pos;
}

void Node::set_y_pos(double position)
{
  if(position < y_min)
  {
    y_pos = y_min;
  }
  else if(position > y_max)
  {
    y_pos = y_max;
  }
  else
  {
    y_pos = position;
  }
}

void Node::offset_y_pos(double offset)
{
  double offset_pos = ypos + offset;
  set_y_pos(offset_pos);
}

//-------------------------------------
// velocity (mag, dir) tuple
//-------------------------------------
vector<double> Node::get_vel()
{
  return vector<double> v = {vel_mag, vel_dir};
}

void Node::set_vel(double magnitude, double direction)
{
  set_vel_mag(magnitude);
  set_vel_dir(direction);
}

void Node::offset_vel(double mag_offset, double dir_offset)
{
  offset_vel_mag(mag_offset);
  offset_vel_dir(dir_offset);
}

//-------------------------------------
// velocity magnitude
//-------------------------------------
double Node::get_vel_mag()
{
  return vel_mag;
}

void Node::set_vel_mag(double magnitude);
{
  if(magnitude < vel_mag_min)
  {
    vel_mag = vel_mag_min;
  }
  else if(magnitude > vel_mag_max)
  {
    vel_mag = vel_mag_max;
  }
  else
  {
    vel_mag = magnitude;
  }
}

void Node::offset_vel_mag(double magnitude); 
{
  double offset_mag = vel_mag + magnitude;
  set_vel_mag(offset_mag);
}

//-------------------------------------
// velocity direction
//-------------------------------------
double Node::get_vel_dir();
{
  return vel_dir;
}

void Node::set_vel_dir(double direction);
{
  vel_dir = direction % 360;
}

void Node::offset_vel_dir(double direction); 
{
  double offset_dir = vel_dir + direction;
  set_vel_dir(offset_dir);
}

//-------------------------------------
// acceleration (mag, dir) tuple
//-------------------------------------
vector<double> Node::get_acc()
{
  return vector<double> v = {acc_mag, acc_dir}
}

void Node::set_acc(double magnitude, double direction)
{
  set_acc_mag(magnitude);
  set_acc_dir(direction);
}

void Node::offset_acc(double mag_offset, double dir_offset) 
{
  offset_acc_mag(mag_offset);
  offset_acc_dir(dir_offset);
}

//-------------------------------------
// acceleration magnitude
//-------------------------------------
double Node::get_acc_mag()
{
  return acc_mag;
}

double Node::set_acc_mag(double magnitude)
{
  if(magnitude < acc_mag_min)
  {
    acc_mag = acc_mag_min;
  }
  else if(magnitude > acc_mag_max)
  {
    acc_mag = acc_mag_max;
  }
  else
  {
    acc_mag = magnitude;
  }
}

double Node::offset_acc_mag(double offset)
{
  double offset_mag = acc_mag + offset;
  set_acc_mag(offset_mag);
}

//-------------------------------------
// acceleration direction
//-------------------------------------
double Node::get_acc_dir()
{
  return acc_dir;
}

void Node::set_acc_dir(double direction)
{
  acc_dir = direction % 360;
}

void Node::offset_acc_dir(double offset)
{
  double offset_dir = (acc_dir + offset);
  set_acc_dir(offset_dir);
}

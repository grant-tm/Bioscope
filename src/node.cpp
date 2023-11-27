//============================================================================
// STL Inclusions
//============================================================================
#include <stdlib.h>
#include <vector>
//============================================================================
// Node Class Definition
// Nodes orbit Poles
// The closest two nodes to any other node have lines drawn between them.
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
private:
// position
double x_pos;
double y_pos;
// velcoity
double vel_mag;
double vel_dir;
// acceleration
double acc_mag;
double acc_dir;

// parameters
double x_min;
double x_max;

double y_min;
double y_max;

};

//============================================================================
// Function Definitions
//============================================================================

//
// (x, y) position
//
vector<double> Node::get_pos()
{
  vector<double> v;
  v.push_back(x_pos);
  v.push_back(y_pos);
  return v;
}

void Node::set_pos(double new_x_pos, double new_y_pos)
{
  set_x_pos(new_x_pos);
  set_y_pos(new_y_pos);
} 

void Node::offset_pos(double x_offset, double y_offset)
{
  offset_x_pos(x_offset);
  offset_y_pos(y_offset);
} 

//
// x position
//
double Node::get_x_pos()
{
  return x_pos;
}

void Node::set_x_pos(double new_pos)
{
  bool pos_in_range = (new_pos >= x_min) && (new_pos <= x_max);
  
  if(pos_in_range)
  {
    x_pos = new_pos;
  }
  else
  {
    x_pos = (new_pos > x_max) ? x_max : x_min;
  }
}

void Node::offset_x_pos(double offset)
{
  bool offset_under_min = (x_pos + offset >= x_min);
  bool offset_over_max =  (x_pos + offset <= x_max); 
  bool offset_in_range = offset_under_min && offset_over_max; 
  
  if(offset_in_range)
  {
    x_pos += offset;
  }
  else if(offset_under_min)
  {
    x_pos = x_min;
  }
  else if(offset_over_max)
  {
    x_pos = x_max;
  }
}

//
// y position
//
double Node::get_y_pos()
{
  return y_pos;
}

void Node::set_y_pos(double new_pos)
{
  bool pos_in_range = (new_pos >= y_min) && (new_pos <= y_max);  
  
  if(pos_in_range)
  {
    y_pos = new_pos;
  }
  else
  {
    y_pos = (new_pos > y_max) ? y_max : y_min;
  }
}

void Node::offset_y_pos(double offset)
{
  bool offset_under_min = (y_pos + offset >= y_min);
  bool offset_over_max =  (y_pos + offset <= y_max); 
  bool offset_in_range = offset_under_min && offset_over_max; 
  
  if(offset_in_range)
  {
    y_pos += offset;
  }
  else if(offset_under_min)
  {
    y_pos = y_min;
  }
  else if(offset_over_max)
  {
    y_pos = y_max;
  }
}

//
// get set offset velocity
//
vector<double> Node::get_vel();
void Node::set_vel(double, double); 
void Node::offset_vel(double, double); 

// get set velocity magnitude
double Node::get_vel_mag();
void Node::set_vel_mag(double);
void Node::offset_vel_mag(double); 

// get set velcoity direction
double Node::get_vel_dir();
void Node::set_vel_dir(double);
void Node::offset_vel_dir(double); 

// get set acceleration 
vector<double> Node::get_acc();
void Node::set_acc(double, double);
void Node::offset_acc(double, double); 

// get set acceleration magnitude
double Node::get_acc_mag();

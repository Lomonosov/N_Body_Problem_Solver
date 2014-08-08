/*


 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define COUNT 50
#define G 6.67E-11

struct vector
{
  double x;
  double y;
};

typedef struct point_mass
{
  struct vector pos;
  double mass;
  struct vector acc;
} point_mass_t;

point_mass_t* new_point_mass(double x, double y, double mass, double acc_x, double acc_y);

struct vector g_force(point_mass_t* m1, point_mass_t* m2) //pointing from m1 to m2
{
  double x1=m1->pos.x;
  double x2=m2->pos.x;
  double y1=m1->pos.y;
  double y2=m2->pos.y;
  double mass1=m1->mass;
  double mass2=m2->mass;
  double r = sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
  
  double f=(G*mass1*mass2)/(r*r);
  struct vector r_vector;
  r_vector.x = x2 - x1;
  r_vector.y = y2 - y1;
  r_vector.x /= r;
  r_vector.y /= r;
  
  r_vector.x *= f;
  r_vector.y *= f;

  return r_vector;
}

int main()
{ 
  point_mass_t* m1=new_point_mass(5,7.3,2,0,0);
  point_mass_t* m2=new_point_mass(-4,-14,5,0,0);

  struct vector force;
  force = g_force(m1, m2);
  printf("%f, %f\n", force.x, force.y);

  return EXIT_SUCCESS;
}

point_mass_t* new_point_mass(double x, double y, double mass, double acc_x, double acc_y)
{
  point_mass_t* output = malloc(sizeof(struct point_mass));
  output->pos.x = x;
  output->pos.y = y;
  assert(mass>0);
  output->mass=mass;
  output->acc.x = acc_x;
  output->acc.y = acc_y;
  return output;
}

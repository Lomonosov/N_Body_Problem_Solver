/*


 */

#ifndef GRAVITON_H
#define GRAVITON_H

#define G 4.302E-3 //Units are pc M_solar^-1 (km/s)^2

struct vector
{
  double x;
  double y;
};

typedef struct point_mass
{
    double mass;
    struct vector pos;
    struct vector vel;
    struct vector acc;
} point_mass_t;

extern point_mass_t* new_point_mass(double x, double y,
                                    double mass,
                                    double acc_x, double acc_y,
                                    double vel_x, double vel_y);

extern struct vector g_force(point_mass_t* m1, point_mass_t* m2); //pointing from m1 to m2

#endif

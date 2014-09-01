/*


 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "graviton.h"

#define COUNT 50

int main()
{ 
    point_mass_t* m1=new_point_mass(0.025, 0.030, 2.0, 0, 0, 0, 0);
    point_mass_t* m2=new_point_mass(0.040, 0.040, 5.0, 0, 0, 0, 0);

    struct vector force;
    force = g_force(m1, m2);
    printf("%f, %f\n", force.x, force.y);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <math.h>

void calculate_user_input( double *m, double *o_v, double *o_r) {
    puts("Satellite Orbit Monitoring System");

    printf("Input the Satellite's mass: ");
    scanf("%f\n", m);
    printf("Input the Satellite's orbital velocity: ");
    scanf("%f\n", o_v);
    printf("Input the Satellite's orbital radius: ");
    scanf("%f\n", o_r);
}

void calculate_centripetal_force(const double *m, const double *o_v, const double *o_r, double *f) {
    *f = (*m * pow((*o_v), 2)) / *o_r;
}

void output_calculations(const double *f) {
    printf("The calculated csntripetal force is: %f\n", *f);
}

int main() {
    double mass;
    double orbital_vel;
    double orbital_radius;
    double force;

    calculate_user_input(&mass, &orbital_vel, &orbital_radius);
    calculate_centripetal_force(&mass, &orbital_vel, &orbital_radius, &force);
    output_calculations(&force);

}
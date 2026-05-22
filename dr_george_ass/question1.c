#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double angle;
    double initial_vel;
    const double g = 9.9;

    puts("Missile projection system.");
    printf("please, input the missile's initial velocity: ");
    scanf("%f\n", &initial_vel);
    printf("please, input the missile's initial angle of inclination to the horizontal: ");
    scanf("%f\n", &angle);

    double range = (pow(initial_vel, 2) * sin(angle)) / g ;

    const int hit_status = range >= 6.0 ? 1 : 0;
    if ( hit_status) {
        // since range is greater than or equal to the bridge distance.
        puts("The missile can definitely hit the bridge");
    } else {
        puts("The missile can never hit the bridge.");
    }

    printf("Range of the missile: %f\n", range);
    printf("Launch angle of the missile: %f\n", angle);

    return 0;
}
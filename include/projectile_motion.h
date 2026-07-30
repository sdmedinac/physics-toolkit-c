
typedef struct {
    double initial_velocity;
    double initial_height;
    double launch_angle;
    double vx;
    double vy;
    double flight_time;
    double max_height;
    double range;
} Projectile;

void projectile_motion(Projectile particle);
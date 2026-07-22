
typedef struct {
    double initial_velocity;
    double final_velocity;
    double acceleration;
    double time;
    double distance;
} Linear_Motion;

void uniform_linear_motion(Linear_Motion particle);
void accelerated_uniform_linear_motion(Linear_Motion particle);
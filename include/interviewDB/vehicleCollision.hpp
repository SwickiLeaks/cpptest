#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/**
 * Detect vehicle collision on 2D scale
 */

struct Vehicle {
  double x, y;            // Position
  double theta;           // Orientation (radians)
  double linearVelocity;  // Linear Speed (whatever units)
  double angularVelocity; // Angular Velocity (rad/s)
};

/**
 * Updating position of a vehicle
 * dt = simulation step
 *
 * dt = timestep
 * X = X0 + V * cos(theta) * dt
 * Y = Y0 + V * sin(theta) * dt
 *
 * v.theta += v.angularVelocity * dt;
 * v.x += v.linearVelocity * cos(v.theta) * dt;
 * v.y += v.linearVelocity * sin(v.theta) * dt;
 *
 * Checking collision
 *      Depends on the shape of the vehicle
 */

// Function to update vehicle position
void updatePosition(Vehicle &v, double dt) {
  v.theta += v.angularVelocity * dt;
  v.x += v.linearVelocity * cos(v.theta) * dt;
  v.y += v.linearVelocity * sin(v.theta) * dt;
}

// Function to detect point collision
bool pointCollision(const Vehicle &a, const Vehicle &b) {
  double dx = a.x - b.x, dy = a.y - b.y;

  return (dx * dx) + (dy * dy) <= 0.000000001;
}

/**
 * The distance between the centers is calculated using the distance formula:
 * sqrt((x2 - x1)^2 + (y2 - y1)^2).
 *
 * Overlapping Condition: If the distance
 * between the centers is less than or equal to (r1 + r2), the circles overlap:
 */
bool circularCollision(const Vehicle &a, const Vehicle &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;

  double dist = sqrt((dx * dx) + (dy * dy));

  double radiusA = 1.0;
  double radiusB = 0.5;

  return dist <= radiusA + radiusB;
}

// Simulate the collision scenario
double simulate(Vehicle a, Vehicle b, double dt, double simulationTime) {
  double t = 0;

  while (t <= simulationTime) {
    if (pointCollision(a, b))
      return t;

    updatePosition(a, dt);
    updatePosition(b, dt);

    t += dt;
  }

  return -1.0;
}

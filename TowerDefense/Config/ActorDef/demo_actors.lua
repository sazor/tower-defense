maze_finder = {
  class = "MazeFinder",
  name = "MazeFinder"
}

enemy = {
  class = "Enemy",
  name = "Enemy"
}

lair = {
  class = "Lair",
  name = "Lair"
}

simple_actor = {
  name = "SimpleActor",
}

particle_demo = {
  class = "ParticleActor",
  color = {1, 1, 1},
  size = {0.2, 0.2},
  sprite = "Resources/Images/Test.png",
  max_particles = 500,
  particles_per_second = 100.0,
  particle_lifetime = 1.5,
  system_lifetime = 0.0,
  spread = 3.14159,
  end_color = {1, 0, 0, 0},
  end_scale = 1,
  min_speed = 3.0,
  max_speed = 4.0,
  gravity = {0.0, 0.0},
  name = "ParticleDemo",
}

ground_actor = {
  class = "PhysicsActor",
  color = {0, 1, 0},
  size = {30, 5},
  density = 0,
}

physics_event_actor = {
  class = "PhysicsActor",
  color = {1, 0, 1},
  size = 3,
  restitution = 0.95,
}

grass = {
  class = "PhysicsActor",
  density = 0,
  tag = "grass",
}

road = {
  name = "Road",
  tag = "road",
}

tree = {
  class = "PhysicsActor",
  density = 0,
  tag = "tree",
}
%include <factory.i>

%factory(Actor*, TextActor, FullScreenActor, Lair, Enemy, Camera, Castle, PhysicsActor, ParticleActor);
%factory(DeveloperLog*, ConsoleLog, CompoundLog, FileLog, SystemLog);
%factory(MessageListener*, TextActor, Lair, Enemy, Camera, FullScreenActor, PhysicsActor, Castle, ParticleActor, Actor);
%factory(Renderable*, TextActor, Lair, Enemy, FullScreenActor, Camera, PhysicsActor, Actor, GridActor, Castle, ParticleActor);
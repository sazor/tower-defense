%include <factory.i>

%factory(Actor*, TextActor, Lair, Enemy, FullScreenActor, PhysicsActor, Camera, ParticleActor);
%factory(DeveloperLog*, ConsoleLog, CompoundLog, FileLog, SystemLog);
%factory(MessageListener*, TextActor, Enemy, Lair, FullScreenActor, Camera, PhysicsActor, ParticleActor, Actor);
%factory(Renderable*, TextActor, Lair, Enemy, Camera, FullScreenActor, PhysicsActor, Actor, GridActor, ParticleActor);
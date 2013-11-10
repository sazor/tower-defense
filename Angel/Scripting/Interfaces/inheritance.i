%include <factory.i>

%factory(Actor*, TextActor, FullScreenActor, Enemy, Camera, PhysicsActor, ParticleActor);
%factory(DeveloperLog*, ConsoleLog, CompoundLog, FileLog, SystemLog);
%factory(MessageListener*, TextActor, Enemy, Camera, FullScreenActor, PhysicsActor, ParticleActor, Actor);
%factory(Renderable*, TextActor, Enemy, FullScreenActor, Camera, PhysicsActor, Actor, GridActor, ParticleActor);
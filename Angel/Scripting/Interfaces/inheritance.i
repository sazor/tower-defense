%include <factory.i>

%factory(Actor*, TextActor, FullScreenActor, Lair, Enemy, StandartTower, MagicTower, PhysicsActor, Tower, Camera, Castle, Trap, ParticleActor);
%factory(DeveloperLog*, ConsoleLog, CompoundLog, FileLog, SystemLog);
%factory(MessageListener*, TextActor, Enemy, Lair, MagicTower, StandartTower, Tower, FullScreenActor, Camera, Castle, Trap, PhysicsActor, ParticleActor, Actor);
%factory(Renderable*, TextActor, Lair, FullScreenActor, Enemy, StandartTower, Camera, MagicTower, PhysicsActor, Trap, GridActor, Tower, Castle, ParticleActor, Actor);
%factory(Tower*, Trap, MagicTower, StandartTower);
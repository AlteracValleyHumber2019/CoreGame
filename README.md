# General Information
_**This chunk of information is taken straight from the assignment document, further information about each category can be found further below**_

## Development Team

#### Team Lead
* Kevin Kruusi

### Gameplay
* Nathan
* Kesh
* Ethan
* Jaymie
* Jean-Francois
* Landon Grant 

### Tools
* Arifa Tyrell
* Sarfaraz
* Tyler Betts-O'Donnell
* Violet
* Dong Hyeong Lee
* Ariel 

### Graphics
* Gabriel Kalil
* Matthew Ferreira
* Marco
* Peter Adams
* Ruan

### Networking
* Aditya Dutta
* Samuel Bujold-Bouchard
* Mike Wells
* Eric
* Raphael
* Spencer

## Deliverables
A single GDD placed as the readme for the repository for this project on GitHub. K-kruusi
invited to the repo as a contributor. Your name included in the readme, and a brief
description of your contribution submitted on blackboard.

##Introduction
High up in the snowy mountains of Alterac Valley, there exists an eternal conflict between
the Dwarves of the Alliance and the Frost Wolf Orc Tribe of the Horde. Players must choose
a faction and a character representing one of the four arch-types: Tank, Healer, Mage, and
Assassin; and assist their faction leader in capturing dominion of all Alterac Valley.

## Background
Modeled after Alterac Valley from World of Warcraft, your game will have a much smaller
scope. No persistent characters, no inventory or gear. Just Orcs Vs Dwarves locked in epic
battle for now.

## Game Mechanics
1. Team - When joining players must choose a faction; Horde or Alliance
1. Unit - After picking a faction players must choose a role.
1. Graveyard - If your character dies, your ghost is transported back to the nearest
graveyard; and put into a queue of at most 30 seconds, before respawning at the
graveyard location. Graveyards are capturable, after holding the node for 5 minutes.
1. Each team starts off with 3 graveyards, an additional graveyard located in the center of
the map starts off unowned.
1. Towers - Near the fortress and each graveyard that the teams start off with is a tower;
towers have archers that will attack any opposing side forces that fight near them. They
have limited range and can be burnt down by the opposing team. The archers on the
tower can be killed but will respawn if the tower stands. Towers do not respawn.
1. Captains - Periodically captains of the faction will buff players belonging to that faction
with their own faction buff. Captains can be attacked by opposing side, after dying they
do not respawn.
1. Generals - Defeating the general of the opposing faction wins the game.The Generals
are guarded by 1 Advisor for each active tower that faction has. Itâ€™s almost impossible to
kill the general with multiple advisors up.
1. Spawn Location - Players start the match at an uncapturable graveyard just outside of
their main base. If their team controls no graveyards players will spawn at the entrance.

## Genre
40 vs 40 Cooperative competitive multiplayer game.

## Characters
1. Knight - High Passive Survivability, Low Damage, Disruption
1. Mage - High Damage, Cooldown-Based Survivability, Range
1. Assassin - High Damage, High Mobility, Disruption
1. Priest - Ability to Heal Self/Others, Range

## Abilities
Each class should at the minimum have 4 skills that fit their kit described above.

## Controls
1. Standard World of Warcraft like controls.
1. WASD movement.
1. Mouse based UI and scene target selection
1. Keys 1 through 0 for abilities
1. Menu for game settings
1. Menu for starting / joining a game
1. Escape for seeing the score + metagame information like HKs, killing blows etc.

## UI
1. Health of self
1. Resource (aka mana) of self
1. Ability buttons with mouse over descriptions
1. Current Target
1. Targets Health and resources
1. Buffs on allies and self
1. Group Members

# Gameplay

## Optimization

Optimization is vital for this game as it will be a 40 vs. 40 player online action game. 
The global game data will be handled by a world server providing and updating all data in the game. 
The client will pull 2 sets of data within each update: Global data and Local data.

Global data should be known by every player in the game at all times. 
For example which team owns which graveyard or the amount of resources each team has in their banks.

Local data are important to a specific client but may not be important for another client. 
For example a player will only receive data that is related to events that happen near them within a specific radius.

## Object Inheritance Hierarchy

#### **Capture Points**
##### Graveyards
Capturing a Graveyard increases the global pressence of a team by giving them more respawn options.

##### Towers
Towers contain archers which fire arrows at enemies in the area.

#### **Actions**
##### Mobility
Moving around based on directional input.

##### Auto Attack
While a target is within a valid distance, it will take damage from basic attacks without the user having to add input.

##### Dying
When health hits 0, a unit dies and can respawn at a graveyard.

##### Respawning
After a timer is completed, dead players come back to life at the nearest Graveyard.

##### Capturing
While a player is close enough to a valid capturable point, they will assist in the process of gaining posession.

##### **Abilities**
###### Single Target Attack
Usually deals high damage to a single target.

###### Area of Effect Attack
This attack has the capability of hitting more than one target but usually dealing less damage than single target attacks.

## Playable Classes
#### Knight
Tank, primarily the front-line of battles, quickly closes gap to initiate combat.

#### Scholar
High ranged damage dealing class with escape moves.

#### Assassin
Stealthy high single target damage melee character.

#### Blood Priest
Back line supportive class, recovers health and provides defensive buffs.


## **Character Inheritance**
All the characters (Players and NPCs) in the game will use a class (or one of its specialized subclass) called Character. 
The Character base class will have common behaviour functions such as Moving, Dying, AutoAttack and Respawning. 
Character will also have some basic members such as a mesh, animations etc. Since every player class and NPC will have some similarities and some differences we decided to use the strategy pattern to achieve this effect.
For example, a Knight class can be made of a Character class with MoveStrategy1, DieStrategy2, AutoAttackStrategy2, and RespawnStrategy4 
while a Mage class can be made of a Character class with MoveStrategy1, DieStrategy3, AutoAttackStrategy2, RespawnStrategy1. 
The Knight and Mage both uses the same MoveStrategy and AutoAttackStrategy by using the strategy pattern we essentially avoid the need of repeating unececarry code.
Furthermore, because most Class/NPC behaviours are wrapped inside Strategy classes we can use a factory class to build the desired class at runtime. 
This flexibility enables us the ability to easily define class archetype in a JSON file (see example below). 
Should there ever be a need to change these classes’ behaviours in the future, all we need to do is modify the JSON file and change a single line of our game code.

#### JSON file

```
Knight {
Move: 		“MoveStrategy1”,
Die:		“DieStrategy2,
AutoAttack: 	“AutoAttackStrategy2”,
Respawn:	“RespawnStrategy4”
}

Mage {
Move: 		“MoveStrategy1”,
Die:		“DieStrategy3,
AutoAttack: 	“AutoAttackStrategy2”,
Respawn:	“RespawnStrategy1”
}
```

#### Character factory


```
MakeCharacter(file_path, name) {
	// In the actual factory function there will be a switch statement that creates different
	// strategies classes base on the JSON file input
	
	Character c = new Character();
	c.SetMoveStrategy(new MoveStrategy1());
	// etc…

	return c;
}
```

#### Character class usage

```
Character new_char = CharacterFactory::MakeCharacter(path, “Knight”);
new_char->Move();
new_char->AutoAttack();
new_char->Die();
new_char->Respawn();
```

We also recognized that there will be some cases where defining specific traits of a certain archetype may be difficult when using the strategy pattern above. 
As such, all the base functions in the character class like Move, AutoAttack, Die, and Respawn can be overwritten. This allows us to derive a subclass from the Character class, for example: Character (Derive)-> SpecialCharacter. 
And since SpecialCharacter is a child class from the base class Character, it may also use the same strategy classes while also having the ability to override or add functionalities.

Lastly, skills are handled differently from strategies. Each Character object will contain a list (std::vector object) of Skill based object. 
A Skill object contains some basic information about a skill/ability such as if the damage range is area of effect or single target. 
Skill class will also have a mandatory pure virtual function to define how a skill should be invoked (does it shoots a projectile or does it spawn a bunch of fireball that rain down from sky etc).

![UnitUML](/new.png)

#### Buff and Combo System
In World of Warcraft, most combos are as following:
Skill 1 - Blessing of Lower City: Spell, duration 15 sec, Your healing spells cost 99 less mana. 
Skill 2 - Chain Heal: Spell, 2.5 sec cast, Heals the friendly target for (140% of Spell power), then jumps to heal the 2 most injured nearby allies. 
Healing is reduced by 30% with each jump.

Thus to achieve this combo effect, we have decided to rely on the Buff system. 
A buff class can be created as the super class for all buffs and can be apply to any character. 
We recognized the fact that a buff can be applied to a character from many sources, such as the character itself, another player, an npc, the world or an event. 
Therefore, to reduce tight coupling we chose to implement an observer pattern system into our buff system. 
Anytime a source needs to invoke a buff on one or more characters it will broadcast its message onto the central buff observer object 
then the observer object will broadcast the message to the appropriate Character classes. This way the Character buff will never need to know who invoked it.

#### Controller System
Both the AI and players control some form of Character class in game, thus it would make sense to say that Characters are simply in game controllable objects. 
Objects can be controlled, they can be ordered to do things but they should not be able to control themselves (otherwise AI would be tightly coupled with Character which would be undesirable). 
Hence we decided to make the AI and player classes both controllers. Controllers in this context do not necessarily have to have the same base class: a player controller may not need to have the same base as an AI controller. 
All they must do is send instructions. A mediator pattern “translator” will then take the input of these instructions either from AI or player or anything else that can send instructions,
translate them and calls the correct function in a Character class, for example:

```
Player->A_KEY->translate->MoveLeft
AI->MOVE_ACTION_LEFT->translate->MoveLeft
```

By writing our AI and player classes with a mediator, we essentially allow any AI to be able to take over player characters. 
An application of this may be if there are only 6 players playing the game, the AI could take over the remaining 74 players and the 6 human player can proceed to play the game without trying to find another 74 people. 
Furthermore, because AI is being decoupled from the Character class, we can swap out an easy AI for an hard AI dynamically.

## Skill Structures
Each class will have their own unique skill sets (4 in total) however there are some similarities. 
Each character class, aside from healer, will have one single target ability and one area of effect target ability along with 2 special case skills. See details below.

#### **Knight**
##### Crippling Blow - Single-Target Melee Attack
The Knight fiercly swings his weapon letting out a grunt and dealing heavy damage and increasing the odds of NPC enemies targeting him.
If the target is a player, it will slow their movement rate.

##### Sundering Strike - Area of Effect Stun
The Knight slams his shield into the ground causing the earth to tremor. Enemies caught in the blast are briefly stunned and take some damage.

##### Bum Rush - Single-Target Gap Closer
The Knight charges forward at his target dealing high damage and becomes slowed for a few seconds.

##### Will of Iron
The Knight is granted increased defenses for a short period of time. Nearby allies will also receive a minor version of this buff. Has a long cooldown.

#### **Scholar/ Elementalist**
##### Incinerate - Single-Target Ranged Spell
Deals damage to a target from a distance. Applies a small damage over time effect. For each target that has this debuff, the Scholar moves faster.

##### Boulder Toss - Area of Effect Range Spell
Summon a giagantic boulder and hurl it at a target area dealing damage to and knocking down enemies hit.

##### Time Skip - Blink Spell
The Scholar warps foward in time, moving his own position forward a set distance and slightly reducing the remaining cooldown of his most recent ability.

##### Impaling Ice - Area of Effect Range Spell
Large icicles rain from the sky dealing damage and slowing enemies hit.

#### **Assassin**
##### Where it Counts - Single-Target Melee Attack
Attack an enemy’s vitals, dealing large amounts of damage (bonus damage used while stealthed).

##### Nerve Strike - Single-Target Melee Attack
Interrupt spell-casting and cause the target to suffer nerve damage over time. If used while stealth, nerve strike does more damage and nerve damage persists longer

##### Stalk - Stealth Ability
Stalk your prey, masking your presence completely to enemies. If targeting an enemy before casting, this ability marks the target, increasing all of your damage to them for a duration once you finish stalking. 
They may not know where you are but they know they are being hunted!

##### In For the Kill - Speed-up Ability
Leap behind your target, stunning them momentarily, if used while stealthed, the next strike you land will have increased damage/ be a guaranteed critical hit. 
If you are stalking the target, in for the kill consumes the damage bonus of stalking and causes larger damage.

#### **Blood Priest**
##### Transfusion - Single-Target Ranged Spell and Heal
Cause minor damage to the target, healing the nearest ally by twice the damage done. Heals self by an amount.

##### My Life for Theirs - Area of Effect Heal
Sacrifice a percentage of hit points to heal nearby allies for a total of a multiple of the amount sacrificed. Heals self based on the amount of allies healed.

##### Ring of Blood - Area of Effect Blocking Spell
Generate a circle of blood that costs a percentage of life in order to create an impassable ring that also makes the caster untargetable.
Should an enemy remain within the ring, they will not be able to exit, but will be able to attack the caster.

##### Hemo Shield - Single-Target Shielding Spell
Blood spilled guards the target, generating a protective shell based on hit points lost by the blood priest.


#### **Racial Abilities**
Racial abilities can be used by any one member of a faction but all members of that faction share a cooldown. This ability has a long cooldown and should be saved for an important moment.

##### Orc - Warcry
All the orcs let out a fierce warcry, increasing damage output and temporarily becoming immune to any interruptions.

##### Dwarf - Stone Skin
The dwarves receive inspiration from their earthen roots and gain a temporary shield equal to their maximum health and become immune to any movement impairing effects.

# Tools

## Game Editor
Loading models into the game space. Being able to scale,rotate, move and determine whether they have/are Collided with something. Camera movement(wasd and mouse to look around. Click to place the object). When a model is selected (Knight ,Mage, Assassin ,Priest) a list of parameters will appear in the inspector that can be changed the object can then be moved around the game space as well.

![worldmap-alterac-old](https://user-images.githubusercontent.com/44447609/51505961-af5f7480-1db7-11e9-9774-990f7c47d40f.jpg)

## UI for Game Editor
A menu that has the list of objects that can be placed in the game space. A inspector that shows that parameters for the object. Example, scale, rotate, and location. Once placed in world and selected again the inspector will show all parameters plus a delete option.

1. Character spawn menu (NPC, player char, animal).
1. Terrain (forest, soil, snow covered land, water). 
1. Asset (Tree, Rock, building, flags). 
1. Starting point, end point, out of bounds point (Spawn points will be selected and units will keep spawn by user click).

## Character Editor
Controls character stats such as requirement for Level, str, dex, int, MP (Magic/Mana/Mist Points), EXP(Experience Points), Defense Power, Evasion, and setting abilities. Also controls NPC stats ex. Guards as well.

![636141782667101293](https://user-images.githubusercontent.com/44447609/51506213-2d704b00-1db9-11e9-8b00-cf2b953a8bee.jpg)

## File Format
Json save character stats and account of player or database(MySQL).

![wc3_editor_objects](https://user-images.githubusercontent.com/44447609/51506261-6e685f80-1db9-11e9-89db-57f6342d7f0e.png)

## Particle System
contain four different particle effects which will used by certain characters in the game. The particles will be controlled with things such as their size, brightness, lifespan, speed, rotation, duration and maximum amount of particles.

## Animation System
Controls animations of the player character and NPCs 

![cap1](https://user-images.githubusercontent.com/44447609/51506291-a5d70c00-1db9-11e9-8328-531cec2b63be.JPG)

# Graphics

The graphics section will highlight all the graphics technologies available for the game.

## **Engines**

* OpenGL Custom Graphics Engine - Allows for more flexibility in terms of specific requirements to the game, and can be more optmized in regards of the necessary tools. However, it's a very slow and unreliable option as it needs to be programmed from scratch.
* Unreal Engine 4 - UE4 already holds a powerful engine with advanced graphics pipelines and tools. It has a powerful Lighting and Rendering system, which is a perfect option for a 3D game. Some of the features included in the engine are: Sub-Surface Shading, PSO Caching (Pipeline State Object), Dynamic Resolution and Post Process Effects. A lot of those can be seen in games like Fortnite, Blade&Soul, Aion, Paragon, Gears of War4, Ark: Survival Evolved, and A Way Out.
* Unity Engine - Unity has a solid optmized engine and powerful editor tools to handle the graphics pipeline for the game, although not as powerful as Unreal Engine, it is still a good option. 

## **Animations**

* If using the Custom OpenGL engine, models will need skeletons and animations. We will then, take the spreaded out key frames of those animations and interpolate the vertex positions model (OBJ File). This will allow smoother playback with less memory usage, however it's heavy time consuming and needs specialized work with animations. An OBJ Loader tool for OpenGL will be created to work with all the vertex, texture and other pertinent data.
* If using Unreal Engine, we can use the Skeletal Mesh Animation System which already holds several Animation Tools and Editors already built-in.

## **Animation - Skeleton**
* For the creation of the animations, it would be recommended to utilize or create a skeleton that can be used to fit both types of characters for efficiency (Orcs and Dwarves) or at the very least the skeletons should fit all class types of their respected species [Dwarves and their class types share their own skeleton, Orcs and their respective classes have their own skeleton] with the base bones being the same both in name and function (head, chest, torso, hips, shoulder.L, shoulder.R, thigh.L, thigh.R, etc.) with species unique bones being extra (Dwarves for their beards, orcs might have some extra bones or not, depending one the agreed style of orc).

## **Textures**

* Textures materials for each mesh will be loaded and assigned on Shader Trees.
* All textures locations of the given texture type will be iterated, loaded and generated to store the informations on the Vertex.
* Unreal Engine already has Texture Editor, Compression and Importing built-in.

## **Design Patterns expected and Bottlenecks**

* For the Models handling and loading the graphics engine needs the usage of the Flyweight Pattern to load instanced objects in the scene full of models and effects.
* For each character animation state, the State Pattern will be utilized, to deal with each animation state of Combat, Out-of-Combat, Idle, Walking, Running, Jumping, Attacking, Casting, etc.

Performance can see a big hit depending on the amount of players and models moving at the same place on the scene. Spells and other visual elements being used on the 3D Scene will also be a bottleneck expected in terms of graphics and processing.

## **System Requirements**

### **Minimum**

* OS: Windows 7 or 8
* Processor: Intel Core i5 2.8Ghz or similar
* Memory: 4GB
* Graphics Card: GTX 550 or similar
* Storage: 5GB minimum

### **Recommended**

* OS: Windows 10
* Processor: Intel Core i7 3.4Ghz or similar
* Memory: 8GB
* Graphics Card: GTX 760 or similar
* Storage: 8GB minimum

# **Networking**

The following section will detail the required components and systems that will be build to allow for networked multiplayer between up to 80 unique players. 
We will develop two servers, a TCP server for user login and a UDP server for communication between players during the game.
Connections between the client and the different servers will be executed using multi-threading. 
An efficient method of creating different threads will need to be designed.
Finally, we will create a database using my SQL that will store player account login information and some basic player statistics and connect to the servers. As networking is a topic new to most of the team, we expect to spend a good amount of time researching the subject.
Below, each of these three main sections (servers, multi-threading and databases) will be detailed in full.

## **Servers**
Alterac Valley will require two types of servers to function as efficiently and safely as possible. One for passing critical information and another to send less critical information across several players.

## **TCP Server**
The TCP (Transmission Control Protocol) server will be used when the player logs in or out out of the game or selects what race and character class they wish to play. 
We will use TCP because it is the safest and most reliable protocol for passing sensitive information 
(ie. player account information such as passwords and emails) between the client and the server.
TCP has error checking via a two way connection between the server and client, 
which can ensure that user information is passed accurately or guarantees a player's character selection are read properly by the server. 
While TCP is slower than other protocols, the error checking and increased reliability outweights the slower communication speed.
To setup the TCP server, we will use SDL_net version 2.0.1 <https://www.libsdl.org/projects/SDL_net/>.

Information passed with TCP:
1. Player information (username, password, email).
1. Player statistics (wins, loses).
1. Character faction and class.
1. Core UI information.
1. Character deaths / kills for scoreboard.
1. Tower and graveyard captures.
1. Captain or general deaths.

1. *Stretch goals: Sending messages to other players in the game. Needs to be TCP as the information must be accurate.*
1. *Stretch goals: Character creator information*

## **UDP Server**
The UDP (User Datagram Protocol) server will be used during gameplay to pass information between the different clients in the game and the server. 
We will use UDP for gameplay because it is very fast and can be used to send data at high frequencies (from 21 to 128 times per second). 
This is important for online games where players need to send information about what their doing to the server at all times.
UDP connections are not as reliable as TCP (described above) as there is no error checking. 
This is acceptable for our purposes as the online game will be a non-deterministic simulation
(what one player sees in their game will be very similar to what another player sees but not 100% accurate).
  
Information passed with UDP:
1. Player transform information (location and rotation).
1. Player actions (attacks, heals, captures of areas like graveyards).
1. Buffs and debuffs (let the player know if they get a buff and how long it will last. Client will handle how the buff changes their actions).
1. Character health (to be displayed on other players UI and to check for validity).

### Area vs. World Servers
To reduce the amount of information being passed around the UDP server during gameplay, we will be breaking up the main gameplay server (called the World server)
into separate smaller servers (called Area servers). These smaller area servers will be divided up based on in-game locations that a player can explore (likely 4 to 9 areas).
This is done because a player at the southern end of the game world does not need to know specific information about another player who is at the northern end of the map.
As such, specific player information (transform and action information) will be passed via the area servers 
(note: players can move between area servers as they explore the gameplay area) while general team and game information that all players need to know 
(tower's captured or general's alive) will be passed to the world server. 

## **Database Information**
This section will list what we will need to store in the database
MySQL is the most likely candidate - We previously used it.

1. Player account information: username, email, password, etc.
1. Player gameplay statistics: wins / loses.
1. Character class statistics: health, actions, abilities.
1. Game version: What patch is the game running on, does the game need to be updated

1. *Stretch goals: Able to pull character creator information*

## On the subject of passwords
As we will be storing critical information from our players, passwords, we will have to make use of "Hashing". Starting in SQL Server 2012, SQL offers several algorithms in regards to hashing passwords including...

1. MD2, MD4, MD5
1. SHA, SHA1
1. SHA2_256, SHA2_512

Hashing a password will not make it completely invulnerable to attacks but will make it significantly more difficult to decrypt. Using newer algorithms, in this case SHA2_512, will improve the strenght of the hash and increase security.

Storing user information with SQL would look something similar to..

``` 
DECLARE @responseMessage NVARCHAR(250)

EXEC dbo.uspAddUser
          @pLogin = N'Admin',
          @pPassword = N'123',
          @pFirstName = N'Admin',
          @pLastName = N'Administrator',
          @responseMessage=@responseMessage OUTPUT

SELECT *
FROM [dbo].[User]
``` 

And would leave a result of :
1. UserID = 1
1. LoginName = Admin
1. PasswordHash = 0xCD8C29B8DEED323...
1. FirstName = Admin
1. LastName = Administrator

### The use of salt
Salt is a randomly generated text that adds another layer of encryption to passwords. 
While this might not be required, it seems good to know it exists in case stronger encryption is required.


## Data Transfer
This section will describe how data is being stored the packets sent across the network and will specify how clients with receive data coming in and process the data.
To keep things as efficient and as fast as possible, most information passed will be in the form of simple variables such as characters, floats and integers. 
For passwords and more sensitive information that needs some level of basic encryption, we can use salt (described above).

## **Multi-Threading**
To create fast and relaible threads, we will be using the built-in threads in the standard template library (part of the <thread.h> file).
The advantage of using multiple threads is to ensure that the core game can run smoothly on the client while accepting packets of data from the server in parallel.
Without these separate threads, it is possible that a network connection (specifically TCP connections as the client and server must communicate back and forth for error checking) 
can block the main thread from continuing until the next asset packet is received.
This will cause significant slowly and result in very choppy gameplay. 
As such, any time a network connection is made (either TCP or UDP) a new thread will be created.    
Similar to networking, more research will be required to fully grasp the concept of multithreading and how to use it with STL.

# Markup Text Examples

Here you can find references on how to use the markup language

It's very easy to make some words **bold** and other words *italic* with Markdown. 

You can even [link to Google!](http://google.com)

# This is an h1
## This is an h2 tag
###### This is an h6 tag

*This text will be italic*
_This will also be italic_

**This text will be bold**
__This will also be bold__

_You **can** combine them_

1. Item 1
1. Item 2
1. Item 3
   1. Item 3a
   1. Item 3b
   
   
I think you should use an
`<addr>` element here instead.


```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```

First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column

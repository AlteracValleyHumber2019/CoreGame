# General Information
_**This chunk of information is taken straight from the assignment document, further information about each category can be found further below**_

## Deliverables
A single GDD placed as the readme for the repository for this project on GitHub. K-kruusi
invited to the repo as a contributor. Your name included in the readme, and a brief
description of your contribution submitted on blackboard.
Introduction
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

Because this game will be a 40 vs 40 player MMO, optimization is vital. The global game data will be handled by a world server providing and updating all data in the game. The client will pull 2 sets of data within each update: Global data and Local data.

Global data is data that should be known by every player in the game at all time. For example which team owns which graveyard and how much resource does a said team have.
Local data is data that are important to a specific client but may not be important for another client. For example a player will only receive data that is related to events that happen near them within a radius.

## Object Inheritance Hierarchy

#### Capture Points

##### Graveyards
Capturing a Graveyard increases the global pressence of a team by giving them more respawn options.

##### Towers
Towers contain archers which fire arrows at enemies in the area.

#### Actions
##### Mobility
Moving around based on directional input.

##### Auto Attack
While a target is within a valid distance, it will take damage from basic attacks.

##### Dying
When health hits 0, a unit dies.

##### Respawning
After a timer is completed, dead players come back to life at the nearest Graveyard.

##### Capturing
While a player is close enough to a valid capturable point, they will assist in the process of gaining poccession.

##### Abilities
###### Single Target
Usually deals high damage to a single target.

###### Area of Effect
Has the capability of hitting more than one target but usually dealing less damage.

##Playable Classes
#### Knight
Tank, primarily the front-line of the battles, quickly closes gap to initiate battles.

#### Mage
High ranged damage dealing class with escape moves.

#### Assassin
Stealthy high single target damage melee character.

#### Healer
Back line supportive class, recovers health and provides defensive buffs.

## Skill Structures
Each class will have their own unique skill sets(4 in total) however there are some similarities. Each character class, aside from healer, would have 1 single target ability and 1 AoE target ability along with 2 special case skills. See details below.

#### Knight
##### Assault - Single-Target Melee Attack
The Knight fiercly swings his weapon letting out a grunt and dealing heavy damage and increasing the odds of NPC enemies targeting him.

##### Shockwave - Area of Effect Stun
The Knight slams his shield into the ground causing the earth to tremor. Enemies caught in the blast are briefly stunned and take some damage.

##### Bum Rush - Single-Target Gap Closer
The Knight charges forward at his target dealing high damage and become slowed for a few seconds.

##### Will of Iron
The Knight is granted increased defenses for a small period of time. Nearby allies will also receive a minor version of this buff. Has a long cooldown.

#### Scholar/ Elementalist

##### Incinerate - Single-Target Ranged Spell
Deals damage to a target from a distance. Applies a small damage over time. For each target that has this debuff the Scholar moves faster.

##### Boulder Toss - Area of Effect Range Spell
Summon a giagantic boulder and hurl it at a target area dealing damage to and knocking down enemies hit.

##### Time Skip - Blink Spell
The Scholar warps foward in time moving his own position forward a set distance and slightly reducing the remaining cooldown of his most recent ability.

##### Impaling Ice - Area of Effect Range Spell
Large Icicles rain from the sky dealing damage and slowing enemies hit.

#### Assassin

##### Where it Counts - Single-Target Melee Attack
Attack an enemy’s vitals, dealing large amounts of damage (bonus damage used while stealthed).

##### Nerve Strike - Single-Target Melee Attack
Interrupt spell-casting and cause the target to suffer nerve damage over time. If used while stealth nerve strike does more damage and nerve damage persists longer

##### Stalk - Stealth Ability
Stalk your prey, masking your presence completely to enemies, if targeting an enemy before casting, mark the target increasing all of your damage to them for a duration once you finish stalking. They may not know where you are but they know they are being hunted!

##### In For the Kill - Speed-up Ability
Leap behind your target, stunning them momentarily, if used while stealthed, the next strike you land will be increased/guaranteed crit (if stalk is chosen as the stealth ability, in for the kill consumes the damage bonus of stalking and causes in for the kill to do large damage.

#### Blood Priest

##### Transfusion - Single-Target Ranged Spell and Heal
Cause minor damage to the target, healing self and nearest ally by twice the damage done.

##### My life for Theirs - Area of Effect Heal
Sacrifice a percentage of hp to heal nearby allies for a total of a multiple of the amount sacrificed.

##### Ring of Blood - Area of Effect Blocking Spell
Generate a circle of blood that costs a percentage of life in order to create an impassable ring that also makes the caster untargetable, should an enemy remain within the ring, they will not be able to exit, but will be able to attack the caster.

##### Hemo Shield - Single-Target Shielding Spell
Blood spilled to guard the target, generating a protective shell based on hp lost by the blood priest.

# Tools

# Graphics

# **Networking**

## **TCP Server**
test
Used for when the player logs in or logs out of the game (need safe and reliable connection to server) and when they choose what game they will play in and also what their character / class will be before the game begins.

1. Player information (username, password, email).
1. Player statistics (wins, loses).
1. Character faction and class.
1. Core UI information 
1. Character deaths / kills for scoreboard

1. *Stretch goals: Sending messages to other players in the game. Needs to be TCP as the information must be accurate.*
1. *Stretch goals: Character creator information*

## **UDP Server**

For the gameplay (less error checking but it is much faster which is required for a game running online with 40-80 people ideally at 60 frames per second). 
Information to be sent in data packets:

1. Transform information (location and rotation).
1. Player actions (attacks, heals, captures of areas like graveyards).
1. Buffs and debuffs (let the player know if they get a buff and how long it will last. Client will handle how the buff changes their actions).
1. Character health (to be displayed on other players UI and to check for validity).

1. *Stretch Goals: TDB*

## **TCP or UDP**
1. Broadcasting tower / graveyard captures and captain / general deaths
1. NOTE: Logistics of sending information via TCP and UDP at the same time. Is it possible to connect players to 2 ports at the same time?

## **Database Information**
This section will list what we will need to store in the database
MySQL is the most likely candidate - We previously used it.

1. Player account information: username, email, password, etc.
1. Player gameplay statistics: wins / loses.
1. Character class statistics: health, actions, abilities.
1. Game version: What patch is the game running on, does the game need to be updated

1. *Stretch goals: Able to pull character creator information*




# Markup Text Testing

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

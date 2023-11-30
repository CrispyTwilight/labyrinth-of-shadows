<!-- Auth: John O'Neal -->
<!-- This is a class  hierarchy tree -->
GameManager(super) - John

SaveGame (super) - Will

LoadGame (super) - Will

Shop (super) - John

RNG_Dice (super) - Hunter

Map (super) - Christian

Movement (super) - Christian

Helper_Utilities (super) - All Team
    EnemyName (arr)
    PlayerName (arr)

Character (super) - Will
|-- Player
    |-- Ranger
    |-- Wizard
    |-- Rogue
|-- Enemy
    |-- EnemyEasy
    |-- EnemyMedium
    |-- EnemyBoss
|-- NPC
    |-- ShopOwner
    |-- Other

Attack (super)
(find a way to subclass the attack functionality)

Ability (super)
(Maybe??)

Inventory (super) -CAB

CAB:
|-- EnemyLoot (struct)
|-- RandomLoot (struct)

|-- Bow (struct)
|-- Staff (struct)
|-- Sword (struct)
|-- Dagger (struct)

|-- Shield (struct)
|-- Armor (struct)
|-- HealthPotion (struct)
#VertigoGameTest is an assigment made by Alejandro Catalán for Vertigo Games.
#
#The zip file contains a folder with the executable that runs the game, and a folder with 
#the whole VS2015 project to compile the code if is needed.
#I have implemented all the classes of the project from the scratch, except the
#IO, Keyboard, Gamepad and Framework classes, that are reused from previous and
#personal projects.
#I have created a mini-engine 2D where the objects are made by components. To
#fullfil the task requirements I implemented this classes:
#- Game: contains the objects, and has functions to update and render.
#- GameObject: container that holds the components that defines the behavior of the object
#- CompBase: base class for a component, all components inherits from this.
#- CompTranform: gives a position in the world to the object
#- CompPlayerController: moves the player
#- CompEquipment: manage and use the inventory of the player
#- CompItem: base class for a recollectable and usable object
#- CompItemHead: defines the item is equipable on the head
#- CompHat: defines the item is a Hat and its behavior, represented with H, inherits from CompItemHead
#- CompItemHand: defines the item is equipable on the hands, left or right
#- CompAmmo: defines the item is an Ammo-clip and its behavior, represented with A, inherits from CompItemHand
#- CompGun: defines the item is a Gun and its behavior, represented with G, inherits from CompItemHand
#- CompStone: defines the item is a Stone and its behavior, represented with S, inherits from CompItemHand
#- CompFlashlight: defines the item is a Flashlight and its behavior, represented with F, inherits from CompItemHand
#- CompLever: defines the object is a lever and its behavior
#
#CONTROLS
#This can be controlled with a Keyboard or a Game Controller like an XBOX or PlayStation (PS3 or PS4) controller
#This is the mapping with a PS4 controller:
#- LEFT AXIS: move forward/backward and left/right of the player
#- RIGHT AXIS: rotate player
#I chose this because in a VR the rotation would be defined by the player's head, so the right axis wouldn't be necesary
#- SQUARE: change the left item equipped
#- CIRCLE: change the right item equipped
#- TRIANGLE: change head item equipped
#- CROSS: activates a lever if is close
#- L1: switch the mode of the left item equipped
#- R1: switch the mode of the right item equipped
#- L2 TRIGGER: performs the action of the left item equipped
#- R2 TRIGGER: performs the action of the right item equipped
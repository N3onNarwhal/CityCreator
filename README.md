# City Creator Tool (Unreal Engine 5)
## Overview
This is an in-editor city building tool I made in Unreal Engine 5.
The goal was to make placing roads and props faster and more intuitive by letting me work directly in the viewport instead of dragging assets around manually.

## Features
- Click in the viewport to place assets
- Grid snapping for clean placement
- Ghost preview that shows exactly where something will go
- Rotation preview before placing
- Separate modes for roads and props
- Basic placement validation (prevents bad placement)

## Tech Used
- Unreal Engine 5 (Blueprints)
- Editor Utility Widgets
- Editor scripting tools

## How It Works
- Use the Editor Utility Widget to determine the type/model for the actor you want
- The tool gets a ray from the editor camera to the mouse position
- That ray determines where the object should be placed
- A ghost version of the asset follows the mouse
- When you click, the real actor is spawned in that location

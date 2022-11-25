# EXAMPLE PROJECT FOR EMBEDDED RUST
- in this project I will build a project to blink an led on an arduino with rust
- In this readme you will find notes and instructions on how this is done for later 
    refrence

## SETUP
- building the project: 
> $ cargo new <project_name>  
- add dependencies in Cargo.toml at the bottom: 
> [dependencies.arduino-hal]  
> git = "https://github.com/Rahix/avr-hal"  
> rev = "92d540c"  
- build the new dependencies: 
> $ cargo update  
- make the .cargo folder
> $ mkdir .cargo
- make file inside .cargo
> $ nano /.cargo/config.toml
- edit /.cargo/config.toml
>> [build]
>> target = "avr-atmega328p.json"
- download the appropriate json file from https://github.com/Rahix/avr-hal/avr-specs/ depends on board
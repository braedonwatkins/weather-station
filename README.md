# Weather Station

## Setup

Git cloned? Good? Good.

### Installs

- CCLS: Language Server for .ccls you know the vibe
- PlatformIO: It would be best to install the PlatformIO CLI since that's what I'm using here.

### Initialization

First, there's a good chance you'll need to initialize for your editor. 

You can do so with:

`pio init --ide ${ide}`

This will create `.ccls` file which lets the CCLS language server do its job.

### Running

In the future this will look like a CI/CD pipeline but for now this assumes you have an Arduino Uno with you. 

I'm unsure the context of these commands but a few useful ones to get up and running: 

- `pio run -t clean`: If something is cached this tends to un-stick it
- `pio run -t compiledb`: This creates a `compile_commands.json` and I don't know what that is but it tends to resolve errors like unrecognized flags and header files.
- `pio run`: This one you'll actually want to run like... when you upload to the board. Who would have thunk.

## Research

Putting topics I've researched here as public documentation. Hopefully it helps anyone who may see the project in progress and not understand the thought process.

### CI/CD Pipelines 

#### The Approach That Will Probably Work: OTA Updates

Coming in at #1 is LLM's favorite suggestion. Fundamentally, this seems really similar to Jenkins the only difference is that it's meant for firmware. 

Really I don't see how the code for a weather station should be treated like firmware but I don't normally work with ESP32's so I'm not gonna judge that too harshly.

GitHub Actions will run its pipeline, finish with a release, and then that will get picked up by the OTA pipeline. The OTA pipeline then just takes whatever is there and replaces its firmware with whatever is compiled in the release.

## Description

And it was spoken thus...

> He was number one!

```C
                                           /
                        _,.------....___,.' ',.-.
                     ,-'          _,.--"        |
                   ,'         _.-'              .
                  /   ,     ,'                   `
                 .   /     /                     ``.
                 |  |     .                       \.\
       ____      |___._.  |       __               \ `.
     .'    `---""       ``"-.--"'`  \               .  \
    .  ,            __               `              |   .
    `,'         ,-"'  .               \             |    L
   ,'          '    _.'                -._          /    |
  ,`-.    ,".   `--'                      >.      ,'     |
 . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'
 ||:, .           ,'  ;  /  / \ `        `.    .      .'/
 j|:D  \          `--'  ' ,'_  . .         `.__, \   , /
/ L:_  |                 .  "' :_;                `.'.'
.    ""'                  """""'                    V
 `.                                 .    `.   _,..  `
   `,_   .    .                _,-'/    .. `,'   __  `
    ) \`._        ___....----"'  ,'   .'  \ |   '  \  .
   /   `. "`-.--"'         _,' ,'     `---' |    `./  |
  .   _  `""'--.._____..--"   ,             '         |
  | ." `. `-.                /-.           /          ,
  | `._.'    `,_            ;  /         ,'          .
 .'          /| `-.        . ,'         ,           ,
 '-.__ __ _,','    '`-..___;-...__   ,.'\ ____.___.'
 `"^--'..'   '-`-^-'"--    `-^-'`.''"""""`.,^.`.--'
 ```

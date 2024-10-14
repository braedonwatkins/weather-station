# Weather Station

## Setup

Git cloned? Good? Good.

### PlatformIO

PlatformIO is initialized already and you shouldn't have to do much here.
Right now the main branch is configured to use an arduino uno just because that's what I have so it's easy to test. 

When you want that to change you run the PlatformIO extension in VSCode and initialize a new project. For future me if you're on nvim still it's `:Pioinit`

### Compiled Commands

You may need to do this if your editor doesn't recognize any arduino specific syntax.

For me this was solveable by running `pio run -t compiledb`. This generates a `compile_commands.json` which then helps to recognize everything.

### Running

In the future this will look like a CI/CD pipeline but for now this assumes you have an Arduino Uno with you. 

Plugging that in if you run `Piorun` or the equivalent in the VSCode extension your code should be uploaded to the board and start running.

## Research

Putting topics I've researched here as public documentation. Hopefully it helps you @Alexis or outsiders who may see the project in progress and not understand the thought process.

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

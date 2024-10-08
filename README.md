# Weather Station

## Setup

idk! I haven't made it yet chill out

## Research

Putting topics I've researched here as public documentation. Hopefully it helps you @Alexis or outsiders who may see the project in progress and not understand the thought process.

### CI/CD Pipelines 

#### The Approach That Will Probably Work: OTA Updates

Coming in at #1 is LLM's favorite suggestion. Fundamentally, this seems really similar to Jenkins the only difference is that it's meant for firmware. 

Really I don't see how the code for a weather station should be treated like firmware but I don't normally work with ESP32's so I'm not gonna judge that too harshly.

GitHub Actions will run its pipeline, finish with a release, and then that will get picked up by the OTA pipeline. The OTA pipeline then just takes whatever is there and replaces its firmware with whatever is compiled in the release.

The OTA could either be implemented using platformIO or "Arduino project structure". On one hand I like how platformIO file structure looks on the surface. On the other hand I like not overcomplicating things and using base functionality of the hardware (I assume Arduino project structure is what comes out of the box anyways).


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

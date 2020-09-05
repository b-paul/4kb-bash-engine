# 4 kilobyte chess engine

## Rules
The rules from Aloril posted on the [TCEC discord server](discord.gg/EYuyrDr) are:
```
4k engine rules basically this:
1) Executable is Linux compatible and runs on CPU or GPU machine and size is <=4kiB (4096 bytes)
2) Has to support minimal UCI and work with TCEC cutechess-cli, for example here is random player using UCI: https://paste.ee/p/vi10v Not much is needed. Add Threads and Hash parameters support if needed (use standard names for these and other standard parameters).
3) No cheating like creating external Stockfish library, using libc and other system libraries OK
4) Can naturally compress executable, just decompressor has be part of executable. (upx for example)
```

## About
Almost all of the board representation comes from [micro-max](https://home.hccnet.nl/h.g.muller/encode.html).

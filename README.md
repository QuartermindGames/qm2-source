# QM2 Sources

This repo hosts the source-code for QM2.
Which at the moment is just a barebones _thing_.

You'll need the rest of [ApeTech](https://github.com/QuartermindGames/ape) to compile this, **which at this time isn't yet public**, but this code is available anyway just on the off-chance it might be a useful reference.

**What's QM2?** I suck at names, so this is just a working title until I come up with something. You'll find out assuming it's ever finished. 

**What happened to QM1?** That's still being worked on, but I wanted to work on something a little more primitive and experimental, that I can hopefully push out sooner rather than later.

**Why is this code public if I can't build it?** Eh, why not? Eventually ApeTech _will_ be public, but until then it 

## Compiling

This project is included as a submodule per [ApeTech](https://github.com/QuartermindGames/ape); you'll want to clone that project and then make sure that all submodules are initialized and updated.

As mentioned per the ApeTech repository, the code is taking advantage of C23 additions. To my knowledge, this currently means you're going to be limited to GCC 13 minimum, at least as of April 2024. You might have some success with Clang. MSVC is completely out of the picture.

## Legal

For now, I've not put this under any formal licence.
There isn't really enough here yet to warrant it.
Feel free to nose around and scoff at it.

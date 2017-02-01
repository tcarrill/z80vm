# z80vm
A virtual machine based on a reduced set of the z80 ISA

## Example
You can assemble the provided .asm files into object code which can then be run on the VM.
For example, using pasmo on linux:

```
$ pasmo --bin -v add.asm add.bin
```

The above will produce an add.bin object file.  Running this file through hexdump will show us the machine code our VM reads and executes:

```
$ hexdump -C add.bin

00000000  3e 05 06 07 80 76                                 |>....v|                      00000006 
```

Run this bin through the VM like so:

```
$ z80 add.bin
```

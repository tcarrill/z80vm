# z80vm
A virtual machine based on a reduced set of the z80 ISA.</br>
The following registers, along with their instructions, will be implemented.<br/>
**A**, **F**, **B**, **C**, **D**, **E**, **H** and **L**<br/> 
As well as their 16-bit pairs<br/>
**AF**, **BC**, **DE** and **HL**<br/>
<br/></br>
The following special purpose registers will also be implemented.</br>
**SP**, **PC**, **IX**, **IY** and **R** 

## Example
You can assemble the provided .asm files into object code which can then be run on the VM.
For example, using pasmo on linux:

```
$ pasmo --bin -v add.asm add.bin
```

The above will produce an add.bin object file.  Running this file through hexdump will show us the machine code our VM reads and executes:

```
$ hexdump -C add.bin

00000000  3e 05 06 07 80 76                                 |>....v|
00000006 
```

Run this bin through the VM like so:

```
$ z80 add.bin

Address  Opcode
00000    3e
00002    06
00004    80
00005    76

Registers:
A: 12   B: 7   C: 0   D: 0   E: 0   F: 0   H: 0   L: 0
```

## Idiosyncrasies
Currently, due to the lack of interrupts, the HALT instruction does not operate as documented by the Z80.  We use it as a way to halt execution and end the VM process.
